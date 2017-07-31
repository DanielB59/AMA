#include "NumericBox.h"
#include "Graphics.h"
#include "Button.h"
#include "Label.h"
NumericBox::NumericBox(Button *plus1, Button *minus1,int posx,int posy, Label *theNumber1, int minVal, int maxVal, Panel* p) 
{
	//plus->draw(Graphics::getInstance(), 1, 1, 1);
	this->max = maxVal;
	this->min = minVal;
	plus = plus1;
	plus->SetBackGround(Color::Cyan);
	minus = minus1;
	minus->SetBackGround(Color::Cyan);
	theNumber = theNumber1;
	string a = theNumber->getValue();
	int number = std::atoi(a.c_str());
//	this->number = std::atoi(tmp.c_str);
	if ((number < maxVal) && (number > minVal))
	{
		theNumber->SetValue(this->theNumber->getValue());
	}

	p->addControl(plus, posx, posy);
	p->addControl(minus, posx + 3, posy);
	p->addControl(theNumber, posx + 1, posy);
	
}
void NumericBox::draw(Graphics g, int posx, int posy, size_t layer)
{
	if (this->minus->pressed) {
		
		string a = theNumber->getValue();
		int number = std::atoi(a.c_str());
		number--;
		if (number < this->min) {
			number++;
			theNumber->SetValue(std::to_string(number));
		}
		else {
			theNumber->SetValue(std::to_string(number));
		}
		this->minus->pressed = !this->minus->pressed;
	}
	if (this->plus->pressed) {

		string a = theNumber->getValue();
		int number = std::atoi(a.c_str());
		number++;
		if (number >= max) {
			number--;
			theNumber->SetValue(std::to_string(number));
		}
		else {
			theNumber->SetValue(std::to_string(number));
		}
		this->plus->pressed = !this->plus->pressed;
	}
}

