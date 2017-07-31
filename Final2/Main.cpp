#include "stdafx.h"
/*#include "TextBox.h"
#include "Controller.h"
#include "Controller.h"
#include "Panel.h"
#include "Label.h"
#include "Button.h"*/
//#include "SimpleBorderFactory.h"
//#include "EventEngine.h"
/*#include "NumericBox.h"
#include "checklist.h"
#include "radioBox.h"*/
//#include "SEBuilder.h"

#include "Console.h"

#include <iostream>
using namespace std;

struct MyListener : public MouseListener
{
	MyListener(Controller &c) : _c(c) { }
	void  MousePressed(Button &b, int x, int y, bool isLeft)
	{
		_c.SetForeground(Color::Orange);
	}
private:
	Controller &_c;
};

/*void funcTest(int x, int y, bool isLeft, Controller& control) {
	control.SetForeground(Color::Green);
}*/

int main()
{
	Console* console = Console::GetConsole();
	console->run();
	return 0;
	
	SEBuilder* builder = SEBuilder::GetBuilder();
	builder->SetOstream(&cout);

	EventEngine eengine;

	Panel mainPanel; mainPanel.ToggleRunnable();

	Label title(5, "Menu:");
	title.SetForeground(Color::White);
	title.SetBorder(Border::Single);

	Button btn1("Add Button", 10), btn2("Add checklist", 13), btn3("Add Label", 9), btn4("testing", 7);
	btn1.SetForeground(Color::White);
	btn2.SetForeground(Color::White);
	btn3.SetForeground(Color::White);
	btn4.SetForeground(Color::White);
	MyListener derp(btn4);
	btn4.AddListener(derp);
	//btn4.SetHandler(funcTest);

	Button done("Done", 4);
	done.SetForeground(Color::White);

	checklist options(10, 20, 0, 0, &btn1, &btn2, &btn3, &mainPanel);
	options.SetForeground(Color::White);

	mainPanel.addControl(&title, 35, 0);
	mainPanel.addControl(&options, 0, 10);
	mainPanel.addControl(&btn4, 20, 10);
	mainPanel.setFocused(&title);
	mainPanel.addControl(&done, 40, 10);

	eengine.run(mainPanel);
	
	Button* btn = builder->BuildButton();
	btn->SetBackGround(Color::Cyan);
	btn->SetForeground(Color::Blue);
	btn->SetBorder(Border::Single);

	Panel* test = builder->BuildPanel();
	test->addControl(btn, 10, 6);
	test->setFocused(btn);

	btn->AddListener(MyListener(*btn));

	return 0;

	Panel ThePanel;
	TextBox t(30);
	t.SetBackGround(Color::Cyan);
	t.SetForeground(Color::White);
	t.SetBorder(Border::Double);

	TextBox t2(10);
	t2.SetForeground(Color::White);
	t2.SetBackGround(Color::Orange);
	t2.SetBorder(Border::Double);

	TextBox t3(10);
	t3.SetBackGround(Color::Purple);
	t3.SetForeground(Color::Blue);
	t3.SetBorder(Border::Single);

	Button button("Button", 6);
	button.SetBackGround(Color::Orange);
	button.SetForeground(Color::Blue);
	button.SetBorder(Border::Double);
	//lable

	char* a = { "aa" };
	char* b = { "bb" };
	char* c = { "cc" };
	
	Label Label1(29, "Put Your Name and Jump By TAB");
	Label1.SetBackGround(Color::White);
	Label1.SetForeground(Color::Blue);
	Label1.SetBorder(Border::Single);
//	check.SetBorder(Border::Double);

	
	Button b2(" ", 1);
	b2.SetBackGround(Color::Orange);
	b2.SetForeground(Color::Blue);
	b2.SetBorder(Border::Single);
	Button b3(" ", 1);
	b3.SetBackGround(Color::Orange);
	b3.SetForeground(Color::Blue);
	b3.SetBorder(Border::Single);
	Button b4(" ", 1);
	b4.SetBackGround(Color::Orange);
	b4.SetForeground(Color::Blue);
	b4.SetBorder(Border::Single);
	int CL_x = 20;
	int CL_y = 20;
	checklist check(20, 20, CL_x, CL_y, &b2 ,&b3 ,&b4 ,&ThePanel);
	radioBox radio(20, 30, 20, 40, &b2, &b3, &b4, &ThePanel);

	check.SetBackGround(Color::Orange);
	check.SetForeground(Color::Blue);
	check.SetBorder(Border::Single);
	
	button.SetBackGround(Color::Orange);
	button.SetForeground(Color::Blue);
	radio.SetBackGround(Color::Orange);
	radio.SetForeground(Color::Blue);
	radio.SetBorder(Border::Single);

	Button pl("+", 1);
	Button mn("-", 1);
	Label num(2, 2);
	NumericBox nb(&pl , &mn, 20, 60, &num, 0, 10, &ThePanel);
	
	ThePanel.addControl(&Label1, 10, 6);
	ThePanel.addControl(&t, 10, 10);
	ThePanel.addControl(&t2, 10, 14);
	ThePanel.addControl(&t3, 10, 18);
	ThePanel.addControl(&button, 30 , 18);
	ThePanel.addControl(&radio, 20, 40);
	//ThePanel.addControl(&b2, 30,30);
	//ThePanel.addControl(&b3, 30, 40);
	//ThePanel.addControl(&b4, 30, 50);
	ThePanel.addControl(&nb, 20, 30);
//	ThePanel.addControl(&b2, 30, 18);
	ThePanel.addControl(&check, CL_x, CL_y);
//	ThePanel.addControl(&b2, 10, 30);
	ThePanel.setFocused(&t);
//  ** numeric  **
	Button nb1("+", 1);
	b2.SetBackGround(Color::Orange);
	b2.SetForeground(Color::Blue);
	b2.SetBorder(Border::Single); 
	Button nb2("-", 1);
	b2.SetBackGround(Color::Orange);
	b2.SetForeground(Color::Blue);
	b2.SetBorder(Border::Single);


	EventEngine engine;

	engine.run(ThePanel);
	int k=2;

	return 0;
} 