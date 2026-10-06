#include "CallOnApp.h"
#include <iostream>

int RatingButton::handle(int event)
{
    if (event != FL_PUSH) {
        // return Fl_Widget::handle(event);
        return Fl_Button::handle(event);
        // or should we just return 0?
    }
    //std::cout << "Rating student: " << app->callee();
    //std::cout << " with a " << rating << '\n';
    app->rateStudent(rating);
    return 1; // 1 indicates we handled it
}

int NewStudentButton::handle(int event)
{
    if (event != FL_PUSH)
        return Fl_Button::handle(event);
    app->selectNewStudent();
    return 1; // 1 indicates we handled it
}
