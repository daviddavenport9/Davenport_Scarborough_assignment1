#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <iostream>
#include <string.h>
#include <string>
#include "Student.h"

using namespace std;
class Instructor {
public:
bool login(string username, string password);
string getInstructorName();
Student getStudent(string username);
Student getMinStudent(int gradeType);
Student getMaxStudent(int gradeType);
double getAvg(int gradeType);

private:
string fullName;


};//Instructor
#endif
