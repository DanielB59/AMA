

#include "stdafx.h"
#include "Panel.h"
#include "Controller.h"
#include <iostream>

using namespace std;

Panel::Panel()
{
	//	cout << "   panel constractor"<<endl;

}


Panel::~Panel()
{
}

void Panel::setBorderDrawer() {

}

void Panel::draw(Graphics g, int posx, int posy, size_t layer) {
	int i = 0;
	while (i < allControls2.size())
	{
		allControls2.at(i)->draw(g, posx, posy, layer);
		i++;
	}
}

void Panel::MousePressed(int x, int y, bool isLeft)
{
	for (int i = 0; i < allControls.size(); i++)
	{
		if ((x >= allControls2[i]->getLeft() - getLeft()) && (x <= (allControls2[i]->getLeft() - getLeft() + allControls2[i]->getMaxWidth())))
			if (y >= allControls2[i]->getTop() - getTop() && y <= (allControls2[i]->getTop() - getTop() + allControls2[i]->_height))
				allControls2[i]->MousePressedEvent(x + getLeft(), y + getTop(), isLeft);	
		
	};
}

void Panel::addControl(Controller *c, int pos_x, int pos_y)
{

	c->SetPosition(pos_x, pos_y);
	
	c->SetVisibility(true);
	//c->_borderDrawer = this->_borderDrawer;
	allControls.push_back(*c);
	allControls2.push_back(c);
}

Controller *Panel::getControl(int at) {
	return &allControls.at(at);
}


void Panel::getAllControls(vector<Controller*> &controls) {
	int j = 0;
	while (j < allControls2.size())
	{
		Controller* temp = allControls2.at(0);
		controls.push_back(allControls2.at(j));
		j++;
	}

}
