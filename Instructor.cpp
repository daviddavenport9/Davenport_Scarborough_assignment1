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
  string usernameStudent, passwordStudent, firstName, lastName;
  int projectGrade, quizGrade, midtermGrade, finalGrade;
  ifstream file("students.txt");
   if (file.fail()) {
    cerr << "Unable to open file." << endl;
    exit(1);
  }
  while (file >> usernameStudent >> passwordStudent >> firstName >> lastName >> projectGrade >> quizGrade >> midtermGrade >> finalGrade)
  {
  if (usernameStudent == username)
    {
      fullName = firstName + " " + lastName;
      student.setStudentName(fullName);
      student.setProjectGrade(projectGrade);
      student.setQuizGrade(quizGrade);
      student.setMidtermGrade(midtermGrade);
      student.setFinalGrade(finalGrade);
      return student;
    }//if
  }//while
  
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
