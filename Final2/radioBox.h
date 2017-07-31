#pragma once
#include "Controller.h"
#include "Button.h"
#include "Label.h"
#include "checklist.h"
#include "Panel.h"
class radioBox: public checklist
{
public:
	radioBox(int size_x, int size_y, int pos_x, int pos_y, Button *b1, Button *b2, Button *b3, Panel *p);
	~radioBox();
	void draw(Graphics g, int posx, int posy, size_t layer);
};

