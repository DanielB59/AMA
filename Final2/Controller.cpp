

#include "stdafx.h"
#include <string>
#include <iostream>
#include "Controller.h"
#include "BorderDrawer.h"
#include "Graphics.h"
#include "SimpleBorderFactory.h"
#include "EventEngine.h"
#include "TextBox.h"
using namespace std;


void Controller::SetMaxWidth(int width) {
	this->maxWidth = width;
}


Controller::Controller( int width, int height): Controller()
{

	
//	this->BackGround = BackGroundColor;
//	this->SetBackGround(BackGroundColor);
//	this->SetForeground(ForgroundColor);
//	this->SetBorder(border);
//	this->_pos_x = pos_x;
//	this->_pos_y = pos_y;
	this->_height = height;
	this->_width = width;
	this->maxWidth = width;
	this->BorderType = Border::None;


}
Controller::Controller(): runnable(false)
{
//	cout << " defult controler constarctor" << endl;


	
}



Controller::~Controller()
{

}




void Controller::SetVisibility(bool visibility) {
	isVisible = visibility;
}

void Controller::SetBackGround(Color bc) {
	BackGround = bc;
//	this->Forground = bc;
}
void Controller::SetForeground(Color fc) {
	Forground = fc;
}
void Controller::SetBorder(enum Border b) {
	this->BorderType = b;
	
	if (b == Border::Double) {
	
		setBorderDrawer(SimpleBorderFactory::instance().getDouble());

	}
	if (b == Border::Single) {
	
		setBorderDrawer(SimpleBorderFactory::instance().getSingle());
	}
	if (b == Border::None) {
		setBorderDrawer(SimpleBorderFactory::instance().LNull());
	}
}

void Controller::draw(Graphics g, int posx, int posy, size_t layer) {
//	_pos_x = posx;
//	_pos_y = posy;
	g.moveTo(this->getLeft(), _pos_y);
	g.setCursorVisibility(this->isVisible);
	g.setBackground(this->BackGround);
	g.setForeground(this->Forground);
	if (BorderType!= Border::None)
		this->drawBorder(g);

}
void Controller::SetPosition(int x, int y) {
	_pos_x = x;
//	cout << _pos_x << endl;
	_pos_y = y;
}


void Controller::setBorderDrawer(const BorderDrawer &borderDrawer) {
	_borderDrawer = &borderDrawer;
}



void Controller::drawBorder(Graphics g)
{


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


}




Controller* Controller::focused = NULL;

void Controller::setFocused(Controller* c) {
	if (c) {
			if (Controller::focused) Controller::focused->_foucus = false;
		c->_foucus = true;
		Controller::focused = c;
	}
}





void Controller::setFocus(Controller &control, HANDLE &main) {
	COORD tmp = { 6 , 6};
	tmp = control.getPosition();
	SetConsoleCursorPosition(main,tmp ); // change to control x y
	//_graphics.moveTo(10, 10);
	//cout << "h";
}



