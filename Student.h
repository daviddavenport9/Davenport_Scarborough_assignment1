#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;
class Student {

public:
bool login(string username, string password);
string getStudentName();
int getProjectGrade();
int getQuizGrade();
int getMidtermGrade();
int getFinalGrade();
double getOverallGradeCalc();
double getOverallGrade();
void setStudentName(string fullName);
void setProjectGrade(int grade);
void setMidtermGrade(int grade);
void setQuizGrade(int grade);
void setFinalGrade(int grade);
void setOverallGrade(double term);


private:

string fullName;
int projectGrade;
int quizGrade;
int midtermGrade;
int finalGrade;
double overallGrade;



}; //Student
#endif
