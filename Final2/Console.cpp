#include "stdafx.h"
#include "Console.h"

int xp = 0, yp = 0;

void quit(int x, int y, bool isLeft, Controller& control) { exit(0); }

void finished(int x, int y, bool isLeft, Controller& control) {
	//cout.flush();
	Console::GetConsole()->toAdd = new Button("Exit", 4);
	Console::GetConsole()->toAdd->SetForeground(Color::White);
	Console::GetConsole()->toAdd->SetBorder(Border::Single);
	((Button*)(Console::GetConsole()->toAdd))->SetHandler(quit);
	Console::GetConsole()->secondaryPanel->addControl(Console::GetConsole()->toAdd, xp, yp);
	Console::GetConsole()->secondaryPanel->setFocused(Console::GetConsole()->toAdd);
	Console::GetConsole()->TogglePanel();
	Console::GetConsole()->SwitchPanel(Console::GetConsole()->secondaryPanel);
	Console::GetConsole()->TogglePanel();
	Console::GetConsole()->secondaryPanel = nullptr;
	Console::GetConsole()->RunPanel();
}

void addControl(int x, int y, bool isLeft, Controller& control) {
	Console::GetConsole()->secondaryPanel->addControl(Console::GetConsole()->toAdd, xp, yp);
	xp += 5; yp += 5;
	Console::GetConsole()->toAdd = nullptr;
}

void setButton(int x, int y, bool isLeft, Controller& control) {
	if (nullptr != Console::GetConsole()->toAdd) delete Console::GetConsole()->toAdd;
	Console::GetConsole()->toAdd = SEBuilder::GetBuilder()->BuildButton();
}

void setTextBox(int x, int y, bool isLeft, Controller& control) {
	if (nullptr != Console::GetConsole()->toAdd) delete Console::GetConsole()->toAdd;
	Console::GetConsole()->toAdd = SEBuilder::GetBuilder()->BuildTextBox();
}

void setLabel(int x, int y, bool isLeft, Controller& control) {
	if (nullptr != Console::GetConsole()->toAdd) delete Console::GetConsole()->toAdd;
	Console::GetConsole()->toAdd = SEBuilder::GetBuilder()->BuildLabel();
}

Console* Console::consoleApp = nullptr;


Console::Console(): mainPanel(nullptr), engine(), secondaryPanel(nullptr), toAdd(nullptr) {
}


Console::Console(const Console& console): Console() {
}


Console::~Console() {
	delete Console::consoleApp;
}


void Console::run() {
	SEBuilder* builder = SEBuilder::GetBuilder();
	builder->SetOstream(&cout);

	Panel defaultPanel;
	mainPanel = &defaultPanel;
	secondaryPanel = new Panel();

	mainPanel->ToggleRunnable();

	Label title(5, "Menu:");
	title.SetForeground(Color::White);
	title.SetBorder(Border::Single);

	Button btn1("Add Button", 15), btn2("Add TextBox", 15), btn3("Add Label", 15);
	btn1.SetForeground(Color::White);
	btn1.SetHandler(setButton);
	btn2.SetForeground(Color::White);
	btn2.SetHandler(setTextBox);
	btn3.SetForeground(Color::White);
	btn3.SetHandler(setLabel);

	Button add("add", 3), done("Done", 4);
	done.SetHandler(finished);
	done.SetForeground(Color::White);
	done.SetBorder(Border::Single);
	add.SetHandler(addControl);
	add.SetForeground(Color::White);
	add.SetBorder(Border::Single);

	radioBox options(10, 20, 0, 0, &btn1, &btn2, &btn3, mainPanel);
	options.SetForeground(Color::White);

	Label label1(6, "Text:"), label2(6, "Width:");
	label1.SetForeground(Color::White);
	label2.SetForeground(Color::White);

	TextBox param1(10), param2(10);
	param1.SetForeground(Color::White);
	param2.SetForeground(Color::White);
	param1.SetBorder(Border::Single);
	param2.SetBorder(Border::Single);

	builder->AddField("text", &param1);
	builder->AddField("width", &param2);

	mainPanel->addControl(&title, 35, 0);
	mainPanel->addControl(&options, 0, 10);
	mainPanel->addControl(&label1, 20, 5);
	mainPanel->addControl(&label2, 20, 10);
	mainPanel->addControl(&param1, 30, 5);
	mainPanel->addControl(&param2, 30, 10);
	mainPanel->addControl(&add, 0, 17);
	mainPanel->addControl(&done, 35, 17);
	mainPanel->setFocused(&title);

	engine.run(*mainPanel);
}
