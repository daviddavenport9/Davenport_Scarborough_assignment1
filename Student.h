#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
class Student {

public:
bool login(string username, string password);
string getStudentName();
int getProjectGrade();
int getQuizGrade();
int getMidtermGrade();
int getFinalGrade();
double getOverallGrade();

private:

string fullName;
int projectGrade;
int quizGrade;
int midtermGrade;
int finalGrade;




}; //Student
#endif
