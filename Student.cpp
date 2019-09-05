#include "Student.h"

bool Student::login(string username, string password){
  string usernameStudent, passwordStudent, firstName, lastName;
  ifstream file("students.txt");
   if (file.fail()) {
    cerr << "Unable to open file." << endl;
    exit(1);
  }
  while (file >> usernameStudent >> passwordStudent >> firstName >> lastName >> projectGrade >> quizGrade >> midtermGrade >> finalGrade)
  {
  if ((usernameStudent == username) && (passwordStudent ==  password))
    {
      fullName = firstName + " " + lastName;
      return true;
    }//if
  }//while
  cout << "Login as Student failed" << endl;
  return false;
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

double Student::getOverallGradeCalc(){
  overallGrade = ((projectGrade * 0.30) + (quizGrade * 0.10) + (midtermGrade * 0.20) + (finalGrade * 0.40));
  return overallGrade;
}

double Student::getOverallGrade(){
  return overallGrade;
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

void Student::setOverallGrade(int term){
  overallGrade = term;
}
