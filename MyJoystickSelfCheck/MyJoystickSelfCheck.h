#pragma once

#include "GuiBase.h"
#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"
#include "bakkesmod/plugin/PluginSettingsWindow.h"

#include "version.h"
constexpr auto plugin_version = stringify(VERSION_MAJOR) "." stringify(VERSION_MINOR) "." stringify(VERSION_PATCH) "." stringify(VERSION_BUILD);

using namespace std;

#define INPUT_HISTORY_LENGTH 120

#define CVAR_JOYSTICK_VIZ_ENABLED "joystick_viz_enabled"
#define CVAR_JOYSTICK_VIZ_SIZE "joystick_viz_size"

class MyJoystickSelfCheck: public BakkesMod::Plugin::BakkesModPlugin
	,public SettingsWindowBase // Uncomment if you wanna render your own tab in the settings menu
	//,public PluginWindowBase // Uncomment if you want to render your own plugin window
{

	std::shared_ptr<bool> enabled;
	std::shared_ptr<int> joystickVizSize;
	std::vector<ControllerInput> inputHistory;

	//Boilerplate
	void onLoad() override;
	void onUnload() override; // Uncomment and implement if you need a unload method

	void OnSetInput(CarWrapper cw, void* params);
	void Render(CanvasWrapper canvas);

public:
	void RenderSettings() override; // Uncomment if you wanna render your own tab in the settings menu
	//void RenderWindow() override; // Uncomment if you want to render your own plugin window
};
