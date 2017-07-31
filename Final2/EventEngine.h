#pragma once
#ifndef EVENTENGINE_H
#define EVENTENGINE_H



#include "Controller.h"
#include <Windows.h>

class EventEngine
{
public:
	EventEngine(DWORD input = STD_INPUT_HANDLE, DWORD output = STD_OUTPUT_HANDLE);
	void run(Controller &c);
	virtual ~EventEngine();
private:
	void moveFocus(Controller &main, Controller *focused);

	Graphics _graphics;
	HANDLE _console;
	DWORD _consoleMode;
};

#endif // !EVENTENGINE_H