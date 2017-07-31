#include "Label.h"

Label::Label(int width, string value) :Controller(width,1), text(value), size(value.length())
{
	canGetFocusVal = false;
	this->putText();
}

void Label::SetValue(string value)
{
	text = value;
	size = text.length();
}

void Label::handelInput(INPUT_RECORD input)  // keyboard & mouse input 
{
	switch (input.EventType)
	{
	case KEY_EVENT: 
		break;

	case MOUSE_EVENT: 
		break;

	default:
		break;
	}

}

void Label::putText()
{
	CONSOLE_CURSOR_INFO cursor = { 100, FALSE };
	SetConsoleCursorInfo(hndl, &cursor);
	COORD LabPos = this->getPosition();
	SetConsoleCursorPosition(hndl, LabPos);
	for (int i = 0; i < size; i++)
	{
		putchar(text[i]);
	}
}

void Label::draw(Graphics g, int posx, int posy, size_t layer) {
/*	g.moveTo(this->getLeft(), _pos_y);
	g.setCursorVisibility(this->isVisible);
	g.setBackground(this->BackGround);
	g.setForeground(this->Forground);
	*/
	Controller::draw(g, posx, posy, layer);
//	Controller::drawBorder(g);
	this->putText();
}

/*void Label::drawBorder(Graphics g) {

	cout << _borderDrawer->topLeftCorner;
	for (int i = 0; i < this->_width; i++)
	{
		cout << this->_borderDrawer->horizontal;

	}

	cout << _borderDrawer->topRightCorner;

	g.moveTo(_pos_x + _width, _pos_y + _height);
	for (int i = 0; i < this->_height + 1; i++)
	{
		g.moveTo(_pos_x + _width + 1, _pos_y + i + 1);
		cout << this->_borderDrawer->vertical;
		g.moveTo(_pos_x, _pos_y + i + 1);
		cout << this->_borderDrawer->vertical;
		if (i == this->_height - 1) { g.moveTo(_pos_x + _width, _pos_y + _height);  cout << endl; }
	}

	//cout << endl;
	for (int i = 0; i < this->_width; i++)
	{

		cout << this->_borderDrawer->horizontal;

	}


}*/
