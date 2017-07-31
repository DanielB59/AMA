#include "Button.h"
using namespace std;

Button::Button(string str, int width) :Label(width, str), pressed(false) { SetValue(str); event = nullptr; eventHandler = nullptr; }

Button::~Button()
{
	event = nullptr;
	eventHandler = nullptr;
	this->active = false;
}


void Button::AddListener(MouseListener & listener)
{
	this->event = &listener;
}

void Button::draw(Graphics g, int posx, int posy, size_t layer)
{

/*	g.moveTo(this->getLeft(), _pos_y);
	g.setCursorVisibility(this->isVisible);
	g.setBackground(this->BackGround);
	g.setForeground(this->Forground);
	*/
//	Controller::drawBorder(g);
	Controller::draw(g, posx, posy, layer);
	this->putText();
	//Label::draw(g, posx, posy, layer);
}

int Button::mouseEvent(int x, int y)
{
	/*COORD c{ x,y };
	if (true) {
		//pressed = true;
		this->event->MousePressed(*this, x, y, true);
	}
	return 0;*/
	return 0;
}

void Button::mousePressed_(int x, int y, bool isLeftPressed) {
/*	COORD c{ x,y };
	if (this->event ) {
		this->event->MousePressed(*this, x, y, true);
		Controller::setFocused(this);
	}*/
}

int Button::keyPress(KEY_EVENT_RECORD ker, HANDLE output, COORD)
{
	return 0;
}