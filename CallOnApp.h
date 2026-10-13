#ifndef CALLONAPP_H
#define CALLONAPP_H
#include "Buttons.h"
#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>

class Roster;
class Student;

class CallOnApp : public Fl_Window
{
 public:
    CallOnApp(Roster& roster)
          : // create a GUI window object
            Fl_Window(400, 300, "Call On Me!"), roster(roster)
    {
        curStudent = 0;
    }
    const char* callee() { return calleeName->value(); }
    void createWindow(int argc, char* argv[]);
    bool rateStudent(int rating);
    bool selectNewStudent();

 private:
    Roster& roster;
    Student* curStudent;
    Fl_Output* calleeName;
    Fl_Button* nextCallee;
    RatingButton* notHere;
    RatingButton* goodEffort;
    RatingButton* weakEffort;
    RatingButton* sosoEffort;
};

#endif // CALLONAPP_H
