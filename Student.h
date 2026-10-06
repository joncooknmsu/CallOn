//
// Class Student definition
//
#ifndef STUDENT_H
#define STUDENT_H
//#include <fstream>
//#include <iostream>
#include <string>
//#include <sstream>
//#include <vector>
//#include <random>

class Student
{
 public:
    Student(const std::string dataString);
    bool selected(int selValue) const;
    const std::string displayString() const;
    int calls() const;
    const std::string saveString() const;
    bool countResponse(int response);

 private:
    std::string name;
    int calledOnCount;
    int numAbsences;
    float avgScore;
};

#endif // STUDENT_H
