#pragma once

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Graphics.h"
#include "BorderDrawer.h"
#include "SimpleBorderFactory.h"
#include <vector>
#include <iostream>

typedef enum Border {
	Single , Double, None
};


class Controller
{
private:
	int ControllerSise;
	enum Border BorderType;
	bool _foucus;
	bool runnable;

protected:
	Color BackGround = Color::Black;
	Color Forground = Color::Blue;
	bool isVisible;
	int maxWidth;
	const BorderDrawer *_borderDrawer;
	int _size;

public:
	Controller();
	Controller(int width, int height);
	~Controller();
	static Controller* focused;
	virtual void MousePressed(int x, int y, bool isLeft) {};
	virtual void MousePressedEvent(int x, int y, bool isLeft) { setFocused(this); };
	virtual void setBorderDrawer(const BorderDrawer &borderDrawer);
	virtual void draw(Graphics g, int posx, int posy, size_t layer);
	virtual void drawBorder(Graphics g);
	virtual void keyDown(WORD code, char chr) {};
	virtual void getAllControls(vector<Controller*> &controls) {};
	void SetVisibility(bool visibility);

	void SetForeground(Color fc);
	void SetBackGround(Color bc);
	void SetBorder(enum Border b);
	void SetPosition(int x, int y);
	void setFocused(Controller* c);
	static void setFocus(Controller &c, HANDLE &hndl);
	void SetMaxWidth(int);

	void ToggleRunnable() { runnable = !runnable; }
	bool isRunnable() { return runnable; }

	int getLeft() { return this->_pos_x; };
	int getTop() { return this->_pos_y; };
	int getMaxWidth() { return maxWidth; }
	COORD getPosition() { COORD tmp = { _pos_x + 1, _pos_y + 1 }; return tmp; }
	COORD pos;
	HANDLE hndl = GetStdHandle(STD_OUTPUT_HANDLE);
	bool canGetFocus(){return 1;}
	static Controller* getFocused() { return Controller::focused; };
	bool canGetFocusVal = true;
	int _pos_x, _pos_y, _width, _height;
};


#endif
