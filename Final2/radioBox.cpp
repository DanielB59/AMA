#include "stdafx.h"
#include "radioBox.h"


radioBox::radioBox(int size_x, int size_y, int pos_x, int pos_y, Button *b1, Button *b2, Button *b3, Panel *p): checklist(size_x, size_y , pos_x, pos_y, b1, b2, b3, p)
{

}


radioBox::~radioBox()
{
}


void radioBox::draw(Graphics g, int posx, int posy, size_t layer)
{
	if (this->b1->pressed) {
		this->b1->active = true;
		this->b2->active = false;
		this->b3->active = false;
		this->b1->pressed = false;
		l1->SetBackGround(Color::Red);
		l2->SetBackGround(Color::White);
		l3->SetBackGround(Color::White);
	}
	if (this->b2->pressed) {
		this->b1->active = false;
		this->b2->active = true;
		this->b3->active = false;
		this->b2->pressed = false;
		l1->SetBackGround(Color::White);
		l2->SetBackGround(Color::Red);
		l3->SetBackGround(Color::White);
	}
	if (this->b3->pressed) {
		this->b1->active = false;
		this->b2->active = false;
		this->b3->active = true;
		this->b3->pressed = false;
		l1->SetBackGround(Color::White);
		l2->SetBackGround(Color::White);
		l3->SetBackGround(Color::Red);
	}
}