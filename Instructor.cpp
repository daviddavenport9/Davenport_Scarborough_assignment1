#include "Instructor.h"


bool Instructor::login(string username, string password){
  string usernameInstruct, passwordInstruct, firstName, lastName;
  ifstream file("instructors.txt");
   if (file.fail()) {
    cerr << "Unable to open file." << endl;
    exit(1);
  }
  while (file >> usernameInstruct >> passwordInstruct >> firstName >> lastName)
  {
  if ((usernameInstruct == username) && (passwordInstruct ==  password))
    {
      fullName = firstName + " " + lastName;
      return true;
    }//if
  }//while
  cout << "Login as instructor failed" << endl;
  return false;
}

string Instructor::getInstructorName(){
  return fullName;
}

Student Instructor::getStudent(string username){
  Student student;
}

Student Instructor::getMinStudent(int gradeType){

}

Student Instructor::getMaxStudent(int gradeType){

}

double Instructor::getAvg(int gradeType){

}

void Instructor::setInstructorName(string fullName){
  this->fullName = fullName;
}
