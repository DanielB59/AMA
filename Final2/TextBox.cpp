
#include "stdafx.h"
#include "TextBox.h"
#include "Controller.h"
#include <string>
#include<iostream>

using namespace std;

TextBox::TextBox(int width):Controller(width,1)
{
	_width = width;
	_height = 1;
}


TextBox::~TextBox()
{
}


void TextBox::draw(Graphics g, int posx, int posy, size_t layer) {
	Controller::draw(g, posx, posy, layer);
}


void TextBox::SetText(char* value) {
	putchar(int(value));	
	
}

void TextBox::keyDown(WORD code, char chr) {
	cout << chr;

}
