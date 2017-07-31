#pragma once
#ifndef NUMERICBOX_H
#define NUMERICBOX_H

#include <iostream>
#include <vector>
#include "Panel.h"
#include "Label.h"
#include "Button.h"

using namespace std;
class NumericBox : public Panel
{
private:
	Label _val;
	int _minVal;
	int _maxVal;
	int _currentVal;



public:
	NumericBox(Button* plus,Button* minus,int posx, int posy, Label* theNumber, int minVal, int maxVal, Panel* p);
	Button* plus;
	Button* minus;
	Label* theNumber;
	int getValue() { return _currentVal; }
	//void setValue(int value);
	void draw(Graphics g, int posx, int posy, size_t layer);
	int number;
	int max;
	int min;

};

#endif