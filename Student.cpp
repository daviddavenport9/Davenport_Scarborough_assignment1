#include "Student.h"

bool Student::login(string username, string password){
  string usernameStudent, passwordStudent, firstName, lastName;
  ifstream file("students.txt"); // open file
   if (file.fail()) {
    cerr << "Unable to open file." << endl;
    exit(1);
  } // if
  while (file >> usernameStudent >> passwordStudent >> firstName >> lastName >> projectGrade >> quizGrade >> midtermGrade >> finalGrade) // get each token
  {
    if ((usernameStudent == username) && (passwordStudent ==  password)){ // if valid login
      fullName = firstName + " " + lastName; // concatenate name
      return true;
    }//if
  }//while
  cout << "Login as Student failed" << endl;
  return false;
} // login

string Student::getStudentName(){
  return fullName;
} // getStudentName
  
int Student::getProjectGrade(){
  return projectGrade;
} // getProjectGrade

int Student::getQuizGrade(){
  return quizGrade;
} // getQuizGrade

int Student::getMidtermGrade(){
  return midtermGrade;
} // getMidtermGrade

int Student::getFinalGrade(){
  return finalGrade;
} // getFinalGrade

double Student::getOverallGradeCalc(){
  overallGrade = ((projectGrade * 0.30) + (quizGrade * 0.10) + (midtermGrade * 0.20) + (finalGrade * 0.40));
  return overallGrade;
} // getOverallGradeCalc

double Student::getOverallGrade(){
  return overallGrade;
} // getOverallGrade


void Student::setStudentName(string fullName){
  this->fullName = fullName;
} // setStudentName

void Student::setProjectGrade(int grade){
  projectGrade = grade;
} // setProjectGrade

void Student::setQuizGrade(int grade){
  quizGrade = grade;
} // setQuizGrade

void Student::setMidtermGrade(int grade){
  midtermGrade = grade;
} // setMidtermGrade

void Student::setFinalGrade(int grade){
  finalGrade = grade;
} // setFinalGrade

void Student::setOverallGrade(double term){
  overallGrade = term;
} // setOverallGrade
