#pragma once
#include "GUIBuilder.h"

#include "Button.h"
#include "checklist.h"
#include "Label.h"
#include "NumericBox.h"
#include "Panel.h"
#include "radioBox.h"
#include "TextBox.h"

class SEBuilder:public GUIBuilder {
public:
	~SEBuilder() {}

	static SEBuilder* GetBuilder() {
		if (nullptr == instance)
			return instance = new SEBuilder();
		else
			return instance;
	}

	Button* BuildButton();
	checklist* BuildChecklist();
	Label* BuildLabel();
	NumericBox* BuildNumericBox();
	Panel* BuildPanel();
	radioBox* BuildRadioBox();
	TextBox* BuildTextBox();

	void AddField(string key, TextBox* control) {
		if ("text" == key)
			text = control;
		else
			width = control;
	}
private:
	SEBuilder() {}
	SEBuilder(const SEBuilder& ob) {}

	static SEBuilder* instance;

	TextBox *text, *width;
};

