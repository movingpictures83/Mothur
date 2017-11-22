#ifndef MOTHURPLUGIN_H
#define MOTHURPLUGIN_H

#include "Plugin.h"
#include "PluginProxy.h"
#include <string>

class MothurPlugin : public Plugin
{
public: 
 std::string toString() {return "Mothur";}
 void input(std::string file);
 void run();
 void output(std::string file);

private: 
 std::string myInputFile;

};

#endif
