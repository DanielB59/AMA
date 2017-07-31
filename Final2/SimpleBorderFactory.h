#pragma once
#ifndef SimpleBorderFactory_h
#define SimpleBorderFactory_h
#include "BorderDrawer.h"



class NullBorder : public BorderDrawer
{
public:
	NullBorder() {};
	~NullBorder() {};



};


class SingelBorder : public BorderDrawer
{
public:
	SingelBorder() { cout << "single constructor" << endl; 
	horizontal = 196;
	vertical = 179;
	topLeftCorner = 218;
	topRightCorner = 191;
	bottomLeftCorner = 192; 
	bottomRightCorner = 217;
	leftConnector = 180;
	rightConnector = 195;
	topConnector = 194;
	bottomConnector = 193;
	middleConnector = 197;
	};
	~SingelBorder() ;
 
};



class DoublelBorder : public BorderDrawer

{
public:
	
	DoublelBorder() {
	horizontal = 205;
	vertical = 186;
	topLeftCorner = 201;
	topRightCorner = 187;
	bottomLeftCorner = 200;
	bottomRightCorner = 188;
	leftConnector = 204;
	rightConnector = 185;
	topConnector = 203;
	bottomConnector = 202; 
	middleConnector = 206;
	};
	~DoublelBorder() ;



};

class SimpleBorderFactory {

private:
	SimpleBorderFactory();
	~SimpleBorderFactory();
	NullBorder _null;
	SingelBorder _single;
	DoublelBorder _double;
	



public:
	const BorderDrawer& LNull() { return _null; }

	const BorderDrawer& getSingle() { return _single; }
	const BorderDrawer& getDouble() { return _double; }
	static SimpleBorderFactory& instance() {
		static SimpleBorderFactory instance;

		return instance;
	}
	SimpleBorderFactory(SimpleBorderFactory const&) = delete;
	void operator=(SimpleBorderFactory const&) = delete;
	void drawBorder(Graphics g, int lengh, int height)const;

};

#endif // !SimpleBorderFactory
