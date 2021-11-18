#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "MothurPlugin.h"

void MothurPlugin::input(std::string file) {
 myInputFile = file;
 std::string extension = myInputFile.substr(myInputFile.length()-4);
 if (extension == ".txt") {
	 myIterMode = true;
	  std::ifstream ifile(myInputFile.c_str(), std::ios::in);
 while (!ifile.eof()) {
	 std::cout << "HI" << std::endl;
   std::string key, value;
   ifile >> key;
   ifile >> value;
   parameters[key] = value;
 }

 }
 else
	 myIterMode = false;
}

void MothurPlugin::run() {}

void MothurPlugin::output(std::string file) {
 std::string myOutputFile = file;
 std::string myCommand = "";
 if (!myIterMode) {
myCommand += "mothur";
myCommand += " ";
myCommand += myInputFile + " ";
 }
 else {
   if (parameters["pattern"][0] != '/') {
      parameters["pattern"] = std::string(PluginManager::prefix())+"/"+parameters["pattern"];
   }
   if (parameters.count("suffix") != 0) {// && parameters["prefix"] == "true") {
   myCommand += "for g in "+parameters["pattern"]+"; do ";
       myCommand += "NAME=\"$(basename $g "+parameters["suffix"]+")\"; ";
      myCommand += "DIR=\"$(dirname $g)\"; ";
      myCommand += "f=$DIR/$NAME; ";
   }
   else
   myCommand += "for f in "+parameters["pattern"]+"; do ";

		   
		myCommand += "mothur \"#";
  //myCommand += "set.dir(output="+file+"); ";
  std::ifstream ifile(std::string(PluginManager::prefix())+parameters["file"].c_str(), std::ios::in);
  std::string line;
  std::cout << std::string(PluginManager::prefix())+parameters["file"].c_str() << std::endl;
 while (!ifile.eof()) {
	 getline(ifile, line);
	 if (line.length() > 0) {
	 myCommand += line;
	 myCommand += "; ";
	 }
 }
 myCommand += "\"; ";
 myCommand += "done";
 }
 std::cout << myCommand << std::endl;
 system(myCommand.c_str());
}

PluginProxy<MothurPlugin> MothurPluginProxy = PluginProxy<MothurPlugin>("Mothur", PluginManager::getInstance());
