//
// Class Roster definition
//
#ifndef ROSTER_H
#define ROSTER_H
#include "CallOnApp.h"
#include "Student.h"
#include <random>
#include <string>
#include <vector>

class Roster
{
 public:
    Roster();
    bool addStudent(Student* student);
    Student* selectStudent();
    void callOccurred();
    void saveRoster(const std::string& filename = "_loadfile_") const;
    bool loadFile(const std::string& filename);

 private:
    std::vector<Student*> roster;
    int count;
    int totalCalls;
    int* callOnSequence = 0;
    unsigned int callIndex = 0;
    std::string dataFilename;
    std::mt19937* randomGen;
};

#endif // ROSTER_H
