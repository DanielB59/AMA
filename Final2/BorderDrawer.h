#pragma once
#ifndef BORDERDRAWER_H
#define BORDERDRAWER_H
#include "Graphics.h"

#include <iostream>

class BorderDrawer {

	
public:
	BorderDrawer() {};
	~BorderDrawer() {};
//	virtual void drawBorder(Graphics g, int lengh, int height)const = 0 {
//		g.getInstance
//		g.setBackground(Color::Black);
//		for (int i = 0; i < lengh; i++) {
//			cout <<"aaa";
//			cout << this->middleConnector;
//			cout << this->bottomConnector;

//		}
//	};
	void drawLineVer(Graphics g) {

	}
	void drawLinehor() {

	}

	char horizontal;
	char vertical;
	char topLeftCorner;
	char topRightCorner;
	char bottomLeftCorner;
	char bottomRightCorner;
	char leftConnector;
	char rightConnector;
	char topConnector;
	char bottomConnector;
	char middleConnector;



};


#endif