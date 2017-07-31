#include "stdafx.h"
#include "checklist.h"


checklist::checklist(int size_x, int size_y, 
						int pos_x, int pos_y, Button *b1, Button *b2,
										Button *b3, Panel *p) :Controller(size_x, size_y)
{
	x_ = size_x;
	y_ = size_y;
	


	this->b1 = b1;
	this->b2 = b2;
	this->b3 = b3;
	l1 = new Label(3, "option 1");
	l1->SetBackGround(Color::White);
	l1->SetForeground(Color::Blue);
	l2 = new Label(3, "option 2");
	l2->SetBackGround(Color::White);
	l2->SetForeground(Color::Blue);
	l3 = new Label(3, "option 3");
	l3->SetBackGround(Color::White);
	l3->SetForeground(Color::Blue);
	p->addControl(l1, pos_x + 3, pos_y+2);
	p->addControl(l2, pos_x + 3, pos_y + 6);
	p->addControl(l3, pos_x + 3, pos_y + 10);
	p->addControl(b1, pos_x, pos_y + 2);
	p->addControl(b2, pos_x, pos_y + 6);
	p->addControl(b3, pos_x, pos_y + 10);
	this->b1->pressed = false;
	this->b2->pressed = false;
	this->b3->pressed = false;
	this->_height = 14;
	this->_width = 30;
	
	for (int i = 0; i < 3; i++)
		pressed[i] = 0;


}


checklist::~checklist()
{
}



void checklist::draw(Graphics g, int posx, int posy, size_t layer) {
	Controller::draw(g, posx, posy, layer);
	/// radio box
	/*	
	}
	*/
	/// chack list
	if (this->b1->pressed) {
		this->b1->active = !this->b1->active;
		this->b1->pressed = false;
	}
	if(this->b1->active){
		l1->SetBackGround(Color::Red);
	}else {
		l1->SetBackGround(Color::White);
	}
	if (this->b2->pressed) {
		this->b2->active = !this->b2->active;
		this->b2->pressed = false;
	}
	if(this->b2->active){
		l2->SetBackGround(Color::Red);
	}else {
		l2->SetBackGround(Color::White);
	}
	if (this->b3->pressed) {
		this->b3->active = !this->b3->active;
		this->b3->pressed = false;
	}
	if(this->b3->active){
		l3->SetBackGround(Color::Red);
	}else {
		l3->SetBackGround(Color::White);
	}
	
	
	
/*	if (pressed[1]==0)
		cout << " ( ) " << oprion1 << endl;
	else
		cout << " (X) " << oprion1 << endl;
	g.moveTo(this->_pos_x+1, this->_pos_y+2);
	if (pressed[2] == 0)
		cout << " ( ) " << option2 << endl;
	else
		cout << " (X) " << option2 << endl;
	g.moveTo(this->_pos_x+1, this->_pos_y+3);
	if (pressed[3] == 0)
		cout << " ( ) " << option3 << endl;
	else
		cout << " (X) " << option3 << endl;
*/

}
