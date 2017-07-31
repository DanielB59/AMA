#pragma once
#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include "Label.h"
#include "Graphics.h"

class Button;

struct MouseListener
{
	virtual void MousePressed(Button &button, int x, int y, bool isLeft) = 0;
};




class Button :public Label
{
protected:
	MouseListener *event;
	void(*eventHandler)(int, int, bool, Controller&);
private:
	
public:
	bool pressed;
	bool active;
	Button(string str, int width);
	~Button();
	void SetHandler(void(*callback)(int, int, bool, Controller&)) { eventHandler = callback; }
	void AddListener(MouseListener &listener);
	void draw(Graphics g, int posx, int posy, size_t layer);

	void  mousePressed_(int x, int y, bool isLeft);
	void MousePressedEvent(int x, int y, bool isLeft) {
		this->pressed = true;
		//if (nullptr != event) event->MousePressed(*this, x, y, isLeft);
		if (nullptr != eventHandler) eventHandler(x,y,isLeft,*this);
	};

	//virtual void drawBorder(Graphics g);
	virtual int mouseEvent(int x, int y);
	virtual int keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD);
};