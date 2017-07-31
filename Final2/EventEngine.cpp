#include "stdafx.h"
#include "EventEngine.h"
#include <vector>


EventEngine::EventEngine(DWORD input, DWORD output)
	: _console(GetStdHandle(input)), _graphics(output)
{
	GetConsoleMode(_console, &_consoleMode);
	SetConsoleMode(_console, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
}

void EventEngine::run(Controller &c)
{

	for (bool redraw = true;c.isRunnable();)
	{
		if (redraw)
		{
			_graphics.clearScreen();
			_graphics.setCursorVisibility(false);
			for (size_t p = 0; p < 5; ++p)
				c.draw(_graphics, 0, 0, p);
			Controller* tmp = Controller::getFocused();
			_graphics.moveToCOORD(tmp->getPosition());
			_graphics.setBackground(Color::Black);
			redraw = false;
		}	
		
		INPUT_RECORD record;
		DWORD count;
		ReadConsoleInput(_console, &record, 1, &count);
		switch (record.EventType)
		{
		case KEY_EVENT:
		{
			Controller* f = Controller::getFocused();
			if (f != nullptr && record.Event.KeyEvent.bKeyDown)
			{
				auto code = record.Event.KeyEvent.wVirtualKeyCode;
				auto chr = record.Event.KeyEvent.uChar.AsciiChar;
				if (code == VK_TAB)
					moveFocus(c, f);
				else
					f->keyDown(code, chr);
			}
			break;
		}
		case MOUSE_EVENT:
		{
			auto button = record.Event.MouseEvent.dwButtonState;
			auto coord = record.Event.MouseEvent.dwMousePosition;
			auto x = coord.X - c.getLeft();
			auto y = coord.Y - c.getTop();
			
			if (button == FROM_LEFT_1ST_BUTTON_PRESSED || button == RIGHTMOST_BUTTON_PRESSED)
			{
				c.MousePressed(x, y, button == FROM_LEFT_1ST_BUTTON_PRESSED);
				redraw = true;
			}
			break;
		}
		default:
			break;
		}
	}
}

EventEngine::~EventEngine()
{
	SetConsoleMode(_console, _consoleMode);
}

void EventEngine::moveFocus(Controller &main, Controller *focused)
{
	vector<Controller*> controls;
	vector<Controller*> *tmp = &controls;
	main.getAllControls(*tmp);
	controls = *tmp;
	Controller *test = controls.at(0);// patch fix later
	auto it = find(controls.begin(), controls.end(), focused); // patch fix later(test)
	do
		if (++it == controls.end())
			it = controls.begin();
	while (!(*it)->canGetFocus());
	COORD aa = (*it)->getPosition();
	_graphics.moveToCOORD(aa);
	main.setFocused((*it));
}
