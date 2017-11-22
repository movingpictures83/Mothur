#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MothurPlugin.h"

void MothurPlugin::input(std::string file) {
 myInputFile = file;
}

void MothurPlugin::run() {}

void MothurPlugin::output(std::string file) {
 std::string myOutputFile = file;
 std::string myCommand = "";
myCommand += "mothur";
myCommand += " ";
myCommand += myInputFile + " ";
 system(myCommand.c_str());
}

PluginProxy<MothurPlugin> MothurPluginProxy = PluginProxy<MothurPlugin>("Mothur", PluginManager::getInstance());
