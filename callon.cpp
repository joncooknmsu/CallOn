//====================================================
// An in-class call-on-student manager
//====================================================
#include "CallOnApp.h"
#include "Roster.h"
#include <FL/Fl.H>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

//
// Main: create window and widget, and show
//
int main(int argc, char* argv[])
{
    Roster roster;
    std::string filename;
    if (argc > 1) {
        filename = argv[1];
    } else {
        filename = "trlist.csv";
    }
    if (!roster.loadFile(filename)) {
        std::cout << "Error: couldn't read input file\n";
        return -1;
    }
    /** auto student = roster.selectStudent();
   if (student)
   {
      std::cout << "selected: [" << student->saveString() << "]\n";
   }
   **/
    CallOnApp app(roster);
    //app.createWindow(argc, argv[2]);
    // fix the call for arguments, eventually
    app.createWindow(1, argv);
    // the standard way to run an FLTK GUI app
    return (Fl::run());
}
