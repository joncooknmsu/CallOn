//
// Class Roster and Student definitions
//
#include "Roster.h"
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

Roster::Roster()
{
    // roster = new std::vector<Student*>;
    count = 0;
    totalCalls = 0;
    std::random_device seeder;
    randomGen = new std::mt19937(seeder());
}

bool Roster::addStudent(Student* student)
{
    roster.push_back(student);
    count++;
    totalCalls += student->calls();
    return true;
}

Student* Roster::selectStudent()
{
    // New method: create a sequence just for this execution, then use it over and over
    // 8/21/2023
    if (!callOnSequence) {
        //std::cerr << "Creating call on sequence: " << roster.size() << "\n";
        int maxCalls = 0, totalCalls = 0, ccount;
        for (auto student : roster) {
            ccount = student->calls();
            if (ccount > maxCalls)
                maxCalls = ccount;
            totalCalls += ccount;
        }
        maxCalls++; // so that max can be selected too
        callOnSequence = new int[roster.size() + 1];
        for (unsigned int i = 0; i < roster.size(); i++) {
            int r;
            do {
                //r = (*randomGen)() % roster.size();
                //for (int j = 0; j < i; j++) {
                //    if (r == callOnSequence[j])
                //        r = -1;
                //}
                int randomRange = (maxCalls * roster.size()) - totalCalls;
                int selValue = (*randomGen)() % (randomRange + 1);
                //std::cerr << "randomRange: " << randomRange
                //          << "  selValue: " << selValue << "\n";
                r = 0;
                for (auto student : roster) {
                    if (selValue <= (maxCalls - student->calls()))
                        break;
                    selValue -= maxCalls - student->calls();
                    r++;
                }
                if (r >= (int)roster.size())
                    r = roster.size() - 1;
                //std::cerr << "Selected r: " << r << "\n";
                for (unsigned int j = 0; j < i; j++) {
                    if (r == callOnSequence[j])
                        r = -1;
                }
            } while (r < 0);
            //std::cerr << "Adding index " << r << " in position " << i << "\n";
            callOnSequence[i] = r;
        }
        callIndex = 0;
    }
    if (callIndex >= roster.size())
        callIndex = 0;
    //std::cerr << "Returning selection at " << callIndex << ": "
    //          << callOnSequence[callIndex] << "\n";
    return roster[callOnSequence[callIndex++]];
    // ---- NOT USED BELOW HERE ---------
    //int selValue = (*randomGen)() % roster.size();
    //return roster[selValue];
    // TODO: add weighting to help balance out selections
    // If a student has been selected too often, reduce them
    // int selValue = ((*randomGen)() % totalCalls) + 1;
    // - this is possibly done 4/18/2023
    int maxCalls = 0, totalCalls = 0, ccount;
    for (auto student : roster) {
        ccount = student->calls();
        if (ccount > maxCalls)
            maxCalls = ccount;
        totalCalls += ccount;
    }
    std::cerr << "totalCalls: " << totalCalls << "  maxCalls: " << maxCalls
              << "\n";
    int randomRange = (maxCalls * roster.size()) - totalCalls;
    int selValue = (*randomGen)() % randomRange + 1;
    std::cerr << "randomRange: " << randomRange << "  selValue: " << selValue
              << "\n";
    for (auto student : roster) {
        if (selValue <= (maxCalls - student->calls()))
            return student;
        selValue -= maxCalls - student->calls();
    }
    return 0;
}

void Roster::callOccurred()
{
    totalCalls++;
}

void Roster::saveRoster(const std::string& filename) const
{
    std::string usedFilename = filename;
    if (filename == "_loadfile_") {
        usedFilename = dataFilename;
    }
    std::ofstream dataf(usedFilename);
    dataf << "Student,Calls,Absences,AvgScore\n";
    for (auto student : roster) {
        dataf << student->saveString() << "\n";
    }
    dataf.close();
}
bool Roster::loadFile(const std::string& filename)
{
    dataFilename = filename;
    std::ifstream dataf(filename);
    std::string line;
    int isFirstLine = true;
    if (!dataf)
        return false;
    while (std::getline(dataf, line)) {
        // std::cout << "line is [" << line << "]\n";
        if (line.length() < 2)
            continue; // probably at end of file
        std::istringstream ss(line);
        std::string piece;
        while (std::getline(ss, piece, ',')) {
            // std::cout << "  piece [" << piece << "]\n";
        }
        if (isFirstLine) {
            isFirstLine = false;
            continue;
        }
        auto student = new Student(line);
        // std::cout << "student is [" << student->saveString() << "]\n";
        addStudent(student);
    }
    dataf.close();
    if (roster.size() < 1)
        return false;
    return true;
}
