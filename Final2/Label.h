#pragma once
#include "Controller.h"

using namespace std;

class Label :public Controller
{
	string text;
	int size;
	
	int fontColor = 0;
	int backColor = 0;
	COORD init;
public:
	Label() {};
	Label(int width, string value);
	Label(int width,int height) :Controller(width,height) {};
	~Label() {};

	string getValue() { return this->text; };
	void SetValue(string value);
	void handelInput(INPUT_RECORD input);
	void putText();
	void draw(Graphics g, int posx, int posy, size_t layer);
	void mousePressed(int x, int y, bool isLeft) {};
	void keyDown(int keyCode, char charater) {};
};