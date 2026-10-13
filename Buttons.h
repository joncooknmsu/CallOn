#ifndef BUTTONS_H
#define BUTTONS_H
#include "CallOnApp.h"
#include <FL/Fl_Button.H>

class CallOnApp;

class RatingButton : public Fl_Button
{
 public:
    RatingButton(CallOnApp* app, int rating, int x, int y, int w, int h,
                 const char* label)
          : Fl_Button(x, y, w, h, label)
    {
        this->rating = rating;
        this->app = app;
    }
    virtual int handle(int event);
    bool rateStudent(int rating);

 private:
    int rating;
    CallOnApp* app;
};

class NewStudentButton : public Fl_Button
{
 public:
    NewStudentButton(CallOnApp* app, int x, int y, int w, int h,
                     const char* label)
          : Fl_Button(x, y, w, h, label)
    {
        this->app = app;
    }
    virtual int handle(int event);

 private:
    CallOnApp* app;
};

#endif // BUTTONS_H
