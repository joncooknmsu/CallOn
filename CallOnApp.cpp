#include "CallOnApp.h"
#include "Roster.h"
#include "callon.xpm"
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_RGB_Image.H>

bool CallOnApp::rateStudent(int rating)
{
    if (!curStudent) {
        calleeName->value("  choose again!");
        return false;
    }
    curStudent->countResponse(rating);
    roster.callOccurred();
    calleeName->value("      processed!");
    //roster.saveRoster("roster.csv");
    roster.saveRoster();
    curStudent = 0;
    return true;
}

bool CallOnApp::selectNewStudent()
{
    curStudent = roster.selectStudent();
    calleeName->value(curStudent->displayString().c_str());
    return true;
}

void CallOnApp::createWindow(int argc, char* argv[])
{
    // labelsize(34); // seems not to inherit
    // begin window sub-components
    begin();
    calleeName = new Fl_Output(30, 20, 340, 50, 0);
    calleeName->value("   choose next");
    calleeName->textsize(28);
    nextCallee = new NewStudentButton(this, 125, 100, 150, 40, "Next Callee");
    nextCallee->labelsize(24);
    /*** remove 4-button UI and replace it with just two
    notHere = new RatingButton(this, 0, 30, 170, 150, 40, "Not Here");
    notHere->labelsize(24);
    goodEffort = new RatingButton(this, 3, 220, 170, 150, 40, "Good Effort");
    goodEffort->labelsize(24);
    weakEffort = new RatingButton(this, 1, 30, 240, 150, 40, "Weak Effort");
    weakEffort->labelsize(24);
    sosoEffort = new RatingButton(this, 2, 220, 240, 150, 40, "SoSo Effort");
    sosoEffort->labelsize(24);
    ***/
    goodEffort = new RatingButton(this, 3, 30, 170, 330, 40, "I'm good on that topic!");
    goodEffort->labelsize(24);
    weakEffort = new RatingButton(this, 1, 30, 240, 330, 40, "I need to study that more");
    weakEffort->labelsize(24);
    // declare the drawing area to be resizable
    // mainWindow.resizable(drawer);
    // end window sub-components
    end();
    // set window icon?
    Fl_Pixmap callon_xpm_icon(callon_xpm);
    Fl_RGB_Image callon_icon(&callon_xpm_icon, Fl_Color(0));
    icon(&callon_icon);
    xclass("CallOn");
    // display the window
    show(argc, argv);
}
