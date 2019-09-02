#include "Student.h"

bool Student::login(string username, string password){
  return true;
}

string Student::getStudentName(){
  return fullName;
}

int Student::getProjectGrade(){
  return projectGrade;
}

int Student::getQuizGrade(){
  return quizGrade;
}

int Student::getMidtermGrade(){
  return midtermGrade;
}

int Student::getFinalGrade(){
  return finalGrade;
}

double Student::getOverallGrade(){
  return ((projectGrade * 0.30) + (quizGrade * 0.10) + (midtermGrade * 0.20) + (finalGrade * 0.40));
}

void Student::setStudentName(string fullName){
  this->fullName = fullName;
}

void Student::setProjectGrade(int grade){
  projectGrade = grade;
}

void Student::setQuizGrade(int grade){
  quizGrade = grade;
}

void Student::setMidtermGrade(int grade){
  midtermGrade = grade;
}

void Student::setFinalGrade(int grade){
  finalGrade = grade;
}
