//
// Student class
//
#include "Student.h"
#include <sstream>

Student::Student(const std::string dataString)
{
    std::istringstream dstream(dataString);
    std::string datum;
    name = "Unknown";
    avgScore = calledOnCount = numAbsences = 0;
    if (std::getline(dstream, datum, ','))
        name = datum;
    if (std::getline(dstream, datum, ','))
        calledOnCount = std::stoi(datum);
    if (std::getline(dstream, datum, ','))
        numAbsences = std::stoi(datum);
    if (std::getline(dstream, datum, ','))
        avgScore = std::stof(datum);
}
bool Student::selected(int selValue) const
{
    if (selValue <= calledOnCount)
        return true;
    return false;
}
const std::string Student::displayString() const
{
    return name;
}
int Student::calls() const
{
    return calledOnCount;
}
const std::string Student::saveString() const
{
    return name + "," + std::to_string(calledOnCount) + "," +
           std::to_string(numAbsences) + "," + std::to_string(avgScore);
}
bool Student::countResponse(int response)
{
    calledOnCount++;
    if (response == 0) {
        numAbsences++;
        return true;
    }
    double oldTotal = avgScore * (calledOnCount - 1);
    avgScore = (oldTotal + response) / (double)calledOnCount;
    return true;
}
