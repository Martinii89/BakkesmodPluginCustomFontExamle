#include "pch.h"
#include "FontExample.h"
#include "bakkesmod/wrappers/GuiManagerWrapper.h"


// Do ImGui rendering here
void FontExample::Render()
{
	if (!myFont) {
		auto gui = gameWrapper->GetGUIManager();
		myFont = gui.GetFont("testfont3");
	}
	if (!ImGui::Begin(menuTitle_.c_str(), &isWindowOpen_, ImGuiWindowFlags_None))
	{
		// Early out if the window is collapsed, as an optimization.
		ImGui::End();
		return;
	}
	if (myFont) {
		ImGui::PushFont(myFont);
		ImGui::Text("This is using a custom font");
	}
	else
	{
		ImGui::Text("The custom font haven't been loaded yet");
	}



	if (myFont) {
		ImGui::PopFont();
	}

	ImGui::End();

	if (!isWindowOpen_)
	{
		cvarManager->executeCommand("togglemenu " + GetMenuName());
	}
}

// Name of the menu that is used to toggle the window.
std::string FontExample::GetMenuName()
{
	return "FontExample";
}

// Title to give the menu
std::string FontExample::GetMenuTitle()
{
	return menuTitle_;
}

// Don't call this yourself, BM will call this function with a pointer to the current ImGui context
void FontExample::SetImGuiContext(uintptr_t ctx)
{
	ImGui::SetCurrentContext(reinterpret_cast<ImGuiContext*>(ctx));
	auto gui = gameWrapper->GetGUIManager();

	// This syntax requires c++17
	auto [res, font] = gui.LoadFont("testfont3", "font.ttf", 40);

	if (res == 0) {
		cvarManager->log("Failed to load the font!");
	}
	else if (res == 1) {
		cvarManager->log("The font will be loaded");
	}
	else if (res == 2 && font) {
		myFont = font;
	}
}

// Should events such as mouse clicks/key inputs be blocked so they won't reach the game
bool FontExample::ShouldBlockInput()
{
	return ImGui::GetIO().WantCaptureMouse || ImGui::GetIO().WantCaptureKeyboard;
}

// Return true if window should be interactive
bool FontExample::IsActiveOverlay()
{
	return true;
}

// Called when window is opened
void FontExample::OnOpen()
{
	isWindowOpen_ = true;
}

// Called when window is closed
void FontExample::OnClose()
{
	isWindowOpen_ = false;
}

