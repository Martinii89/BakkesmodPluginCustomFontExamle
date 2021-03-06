#pragma once

#include "bakkesmod/plugin/bakkesmodplugin.h"
#include "bakkesmod/plugin/pluginwindow.h"

constexpr auto plugin_version = "1.0";

class FontExample: public BakkesMod::Plugin::BakkesModPlugin, public BakkesMod::Plugin::PluginWindow
{

	//Boilerplate
	virtual void onLoad();
	virtual void onUnload();

	// Inherited via PluginWindow
	
	ImFont* myFont;


	bool isWindowOpen_ = false;
	bool isMinimized_ = false;
	std::string menuTitle_ = "FontExample";

	virtual void Render() override;
	virtual std::string GetMenuName() override;
	virtual std::string GetMenuTitle() override;
	virtual void SetImGuiContext(uintptr_t ctx) override;
	virtual bool ShouldBlockInput() override;
	virtual bool IsActiveOverlay() override;
	virtual void OnOpen() override;
	virtual void OnClose() override;
	
	
};

