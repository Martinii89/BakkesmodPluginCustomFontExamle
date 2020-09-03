#include "pch.h"
#include "FontExample.h"


BAKKESMOD_PLUGIN(FontExample, "write a plugin description here", plugin_version, PLUGINTYPE_FREEPLAY)


void FontExample::onLoad()
{
	cvarManager->log("Plugin loaded!");
}

void FontExample::onUnload()
{
}