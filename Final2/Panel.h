#pragma once

#ifndef PANEL_H
#define PANEL_H
#include "Controller.h"

class Panel: public Controller {
public:
	Panel();
	~Panel();
	void getAllControls(vector<Controller*> &controls);
	void setBorderDrawer();
	void MousePressed(int x, int y, bool isLeft);
	void addControl(Controller *c, int pos_x, int pos_y) ;
	Controller *getControl(int at);
//	virtual void getAllControls(vector<Controller*> *control);
	void draw(Graphics g, int posx, int posy, size_t layer);
	static Controller& getFocus() ;
	void drawBorder(Graphics g) {};
//	void AddControl(Contro &control);
private:
	int PanelHeight;
	int panelWidth;
	vector<Controller> allControls;
	vector<Controller*> allControls2;
	void keyDown(char code, char *chr);

	


};

#endif