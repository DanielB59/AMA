#include "stdafx.h"
#include "SEBuilder.h"


SEBuilder* SEBuilder::instance = nullptr;


Button* SEBuilder::BuildButton() {
	string str;
	int width;

	/*
	*out << "enter Button text:" << endl;
	cin >> str;
	*out << "enter Button Width:" << endl;
	cin >> width;

	out->flush();
	*/

	str = "hello";
	width = 6;

	Button* result = new Button(str, width);
	result->SetForeground(Color::White);
	result->SetBorder(Border::Single);

	return result;
}


checklist* SEBuilder::BuildChecklist() {
	int x_size, y_size, x_pos, y_pos;

	*out << "checklist:" << endl;

	*out << "enter x size:" << endl;
	cin >> x_size;
	*out << "enter y size:" << endl;
	cin >> y_size;

	*out << "enter x pos:" << endl;
	cin >> x_pos;
	*out << "enter y pos:" << endl;
	cin >> y_pos;

	out->flush();

	return new checklist(x_size, y_size, x_pos, y_pos, BuildButton(), BuildButton(), BuildButton(), BuildPanel());
}


Label* SEBuilder::BuildLabel() {
	string str;
	int width;

	/*
	*out << "enter Label text:" << endl;
	cin >> str;
	*out << "enter Label Width:" << endl;
	cin >> width;

	out->flush();
	*/

	str = "world";
	width = 6;

	Label* result = new Label(width, str);
	result->SetForeground(Color::White);

	return result;
}


NumericBox* SEBuilder::BuildNumericBox() {
	int x_pos, y_pos, minVal, maxVal;

	*out << "NumericBox:" << endl;

	*out << "enter x pos:" << endl;
	cin >> x_pos;
	*out << "enter y pos:" << endl;
	cin >> y_pos;

	*out << "enter min value:" << endl;
	cin >> minVal;
	*out << "enter max value:" << endl;
	cin >> maxVal;

	out->flush();

	return new NumericBox(BuildButton(), BuildButton(), x_pos, y_pos, BuildLabel(), minVal, maxVal, BuildPanel());
}


Panel* SEBuilder::BuildPanel() {
	return new Panel();
}


radioBox* SEBuilder::BuildRadioBox() {
	int x_size, y_size, x_pos, y_pos;

	*out << "RadioBox:" << endl;

	*out << "enter x size:" << endl;
	cin >> x_size;
	*out << "enter y size:" << endl;
	cin >> y_size;

	*out << "enter x pos:" << endl;
	cin >> x_pos;
	*out << "enter y pos:" << endl;
	cin >> y_pos;

	out->flush();

	return new radioBox(x_size, y_size, x_pos, y_pos, BuildButton(), BuildButton(), BuildButton(), BuildPanel());
}


TextBox* SEBuilder::BuildTextBox() {
	int width;

	/*
	*out << "enter TextBox width:" << endl;
	cin >> width;

	out->flush();
	*/

	width = 6;

	TextBox* result = new TextBox(width);
	result->SetBorder(Border::Single);
	result->SetForeground(Color::White);

	return result;
}