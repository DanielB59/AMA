#pragma once
#include "Graphics.h"
#include "Panel.h"
#include "Controller.h"
#include "Button.h"
class checklist : public Controller
{
public:
	checklist(int size_x, int size_y, int pos_x,int pos_y, Button *b1, Button *b2, Button *b3, Panel *p);
	~checklist();
	void draw(Graphics g, int posx, int posy, size_t layer);

	char *oprion1, *option2, *option3;
	int x_, y_;
	Button* b1;
	Button* b2;
	Button* b3;
	Label* l1;
	Label* l2;
	Label* l3;
	bool pressed[3];
};

