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

bool Instructor::checkUsername(string username){
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
     return true;
    }//if
  }//while
  return false;
}

Student Instructor::getMinStudent(int gradeType){
  Student student;
  string usernameStudent, passwordStudent, firstName, lastName;
  int projectGrade, quizGrade, midtermGrade, finalGrade, overallGrade;
  int min = 100;
  ifstream file("students.txt");
   if (file.fail()){
     cerr << "Unable to open file." << endl;
     exit(1);
   } // if                                                                                                                                                                                           
   while (file >> usernameStudent >> passwordStudent >> firstName >> lastName >> projectGrade >> quizGrade >> midtermGrade >> finalGrade){
     if(gradeType == 1){ // project                                                                                                                                                                  
       if(projectGrade <= min){
         min = projectGrade;
         student.setStudentName(firstName + " " + lastName);
         student.setProjectGrade(min);
       } // if                                                                                                                                                                                       
     }if(gradeType == 2){ // quiz                                                                                                                                                                    
       if(quizGrade <= min){
         min = quizGrade;
         student.setStudentName(firstName + " " + lastName);
         student.setQuizGrade(min);
       } // if                                                                                                                                                                                       
     }if(gradeType == 3){ // midterm                                                                                                                                                                 
       if(midtermGrade <= min){
         min = midtermGrade;
         student.setStudentName(firstName + " " + lastName);
         student.setMidtermGrade(min);
       } // if                                                                                                                                                                                       
     }if(gradeType == 4){ // final                                                                                                                                                                   
       if(finalGrade <= min){
         min = finalGrade;
         student.setStudentName(firstName + " " + lastName);
         student.setFinalGrade(min);
       } // if                                                                                                                                                                                       
     }if(gradeType == 5){ // overall - need to get average of every student to compare to min. . .                                                                                                                                                                  
       if(overallGrade <= min){
         min = overallGrade;
         student.setStudentName(firstName + " " + lastName);
         student.setOverallGrade(min);
       } // if                                                                                                                                                                                       
     } // if                                                                                                                                                                                         
   }//while                                                                                                                                                                                          
   return student;
} // getMineStudent                                         

Student Instructor::getMaxStudent(int gradeType){

}

double Instructor::getAvg(int gradeType){

}

void Instructor::setInstructorName(string fullName){
  this->fullName = fullName;
}
