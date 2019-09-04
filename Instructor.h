#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <iostream>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>
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
void setInstructorName(string fullName);
bool checkUsername(string username);

private:
string fullName;


};//Instructor
#endif
