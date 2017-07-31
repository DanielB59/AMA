#pragma once
#ifndef TEXTBOX_H
#define TEXTBOX_H
#include "Controller.h"



class TextBox : public Controller
{
public:
	TextBox(int width);
	~TextBox();
	void draw(Graphics g, int posx, int posy, size_t layer);
//	virtual void drawBorder(Graphics g);
	virtual void SetText(char* value);
	virtual void keyDown(WORD code, char chr);

	
private:
	int Width;
	char** text;
};

#endif
