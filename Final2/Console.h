#pragma once

#include "SimpleBorderFactory.h"
#include "EventEngine.h"
#include "SEBuilder.h"

class Console {
private:
	Console();
	Console(const Console&);

	static Console* consoleApp;

	Panel* mainPanel;
	EventEngine engine;
public:
	~Console();

	void TogglePanel() { mainPanel->ToggleRunnable(); }
	void SwitchPanel(Panel* panel) { mainPanel = panel; }
	void RunPanel() { engine.run(*mainPanel); }

	void run();
	static Console* GetConsole() {
		if (nullptr == consoleApp)
			consoleApp = new Console();
		
		return consoleApp;
	}

	Panel* secondaryPanel;
	Controller* toAdd;
};

