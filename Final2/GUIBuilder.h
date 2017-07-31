#pragma once

#include "Controller.h"

class GUIBuilder {
public:
	GUIBuilder() {}
	~GUIBuilder() {}

	void SetOstream(ostream* stream) { out = stream; }

	virtual Controller* BuildButton() = 0;
	virtual Controller* BuildChecklist() = 0;
	virtual Controller* BuildLabel() = 0;
	virtual Controller* BuildNumericBox() = 0;
	virtual Controller* BuildPanel() = 0;
	virtual Controller* BuildRadioBox() = 0;
	virtual Controller* BuildTextBox() = 0;
protected:
	ostream* out;
};
