#include "Instructor.h"


bool Instructor::login(string username, string password){
  string usernameInstruct, passwordInstruct, firstName, lastName;
  ifstream file("instructors.txt"); // open file
  if (file.fail()) {
    cerr << "Unable to open file." << endl;
    exit(1);
  } // if
  while (file >> usernameInstruct >> passwordInstruct >> firstName >> lastName){ // get tokens
    if ((usernameInstruct == username) && (passwordInstruct ==  password)){ // if login success
      fullName = firstName + " " + lastName;
      return true;
    }//if
  }//while
  cout << "Login as instructor failed" << endl;
  return false;
} // login

string Instructor::getInstructorName(){
  return fullName;
} // getInstructorName

Student Instructor::getStudent(string username){
  Student student;
  string usernameStudent, passwordStudent, firstName, lastName;
  int projectGrade, quizGrade, midtermGrade, finalGrade;
  ifstream file("students.txt"); // open file
  if (file.fail()){ // if fail
    cerr << "Unable to open file." << endl;
    exit(1);
  } // if
  while (file >> usernameStudent >> passwordStudent >> firstName >> lastName >> projectGrade >> quizGrade >> midtermGrade >> finalGrade){ // get tokens
  if (usernameStudent == username){ // if correct username
    fullName = firstName + " " + lastName; // concatenate names
    // set up Student object
    student.setStudentName(fullName);
    student.setProjectGrade(projectGrade);
    student.setQuizGrade(quizGrade);
    student.setMidtermGrade(midtermGrade);
    student.setFinalGrade(finalGrade);
    return student;
    }//if
  }//while
  return student;
} // getStudent

bool Instructor::checkUsername(string username){
  string usernameStudent, passwordStudent, firstName, lastName;
  int projectGrade, quizGrade, midtermGrade, finalGrade;
  ifstream file("students.txt"); // open file
  if (file.fail()){ // if fail 
    cerr << "Unable to open file." << endl;
    exit(1);
  } // if
  while (file >> usernameStudent >> passwordStudent >> firstName >> lastName >> projectGrade >> quizGrade >> midtermGrade >> finalGrade){ // get tokens
    if (usernameStudent == username){ // if success
      return true;
    }//if
  }//while
  return false;
} // checkUsername

Student Instructor::getMinStudent(int gradeType){
  Student student;
  string usernameStudent, passwordStudent, firstName, lastName;
  int projectGrade, quizGrade, midtermGrade, finalGrade, overallGrade;
  int min = 100;
  ifstream file("students.txt");
  if(file.fail()){
   cerr << "Unable to open file." << endl;
   exit(1);
   } // if
   while (file >> usernameStudent >> passwordStudent >> firstName >> lastName >> projectGrade >> quizGrade >> midtermGrade >> finalGrade){ // get tokens
     overallGrade = ((projectGrade * 0.30) + (quizGrade * 0.10) + (midtermGrade * 0.20) + (finalGrade * 0.40)); // create overall grade of each student
     if(gradeType == 1){ // project
       if(projectGrade <= min){ // if new min
         min = projectGrade;
         student.setStudentName(firstName + " " + lastName); // get student's name for output
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
     }if(gradeType == 5){ // overall
       if(overallGrade <= min){
         min = overallGrade;
         student.setStudentName(firstName + " " + lastName);
         student.setOverallGrade(min);
       } // if                         
     } // if 
   }// while 
   return student;
} // getMinStudent                                         

Student Instructor::getMaxStudent(int gradeType){
Student student;
  string usernameStudent, passwordStudent, firstName, lastName;
  int projectGrade, quizGrade, midtermGrade, finalGrade;
  int max = 0;
  double overallGrade = 0;
  ifstream file("students.txt");
  if (file.fail()){
   cerr << "Unable to open file." << endl;
   exit(1);
  } // if 
  while (file >> usernameStudent >> passwordStudent >> firstName >> lastName >> projectGrade >> quizGrade >> midtermGrade >> finalGrade){
   overallGrade = ((projectGrade * 0.30) + (quizGrade * 0.10) + (midtermGrade * 0.20) + (finalGrade * 0.40));
   if(gradeType == 1){ // project                                                                                                                               
     if(projectGrade >= max){
       max = projectGrade;
       student.setStudentName(firstName + " " + lastName);
       student.setProjectGrade(max);
     } // if
   }if(gradeType == 2){ // if
     if(quizGrade >= max){
       max = quizGrade;
       student.setStudentName(firstName + " " + lastName);
       student.setQuizGrade(max);
     } // if
   }if(gradeType == 3){ // midterm
     if(midtermGrade >= max){
       max = midtermGrade;
       student.setStudentName(firstName + " " + lastName);
       student.setMidtermGrade(max);
     } // if
   }if(gradeType == 4){ // final 
     if(finalGrade >= max){
       max = finalGrade;
       student.setStudentName(firstName + " " + lastName);
       student.setFinalGrade(max);
     } // if
   }if(gradeType == 5){ // overall                                                                
     if(overallGrade >= max){
       max = overallGrade;
       student.setStudentName(firstName + " " + lastName);
       student.setOverallGrade(max);
     } // if
   } // if
   }//while 
   return student;
} // getMaxStudent

double Instructor::getAvg(int gradeType){
  string usernameStudent, passwordStudent, firstName, lastName;
  int projectGrade, quizGrade, midtermGrade, finalGrade;
  double projectSum = 0;
  double quizSum = 0;
  double midtermSum = 0;
  double finalSum = 0;
  double overallSum = 0;
  double average;
  double overallGrade = 0;
  ifstream file("students.txt");
  if (file.fail()) {
    cerr << "Unable to open file." << endl;
    exit(1);
  }//if
  while (file >> usernameStudent >> passwordStudent >> firstName >> lastName >> projectGrade >> quizGrade >> midtermGrade >> finalGrade){ // get tokens
    overallGrade = ((projectGrade * 0.30) + (quizGrade * 0.10) + (midtermGrade * 0.20) + (finalGrade * 0.40)); // get overall grade
    projectSum += projectGrade;
    quizSum += quizGrade;
    midtermSum += midtermGrade;
    finalSum += finalGrade;
    overallSum += overallGrade;
  }//while
  if (gradeType == 1){
    average = projectSum / 20;
  }if (gradeType == 2){
    average = quizSum / 20;
  }if (gradeType == 3){
    average = midtermSum / 20;
  }if (gradeType == 4){
  average = finalSum / 20;
  }if (gradeType == 5){
    average = overallSum / 20;
  } // if
   return average;
  
}//getAvg

void Instructor::setInstructorName(string fullName){
  this->fullName = fullName;
} // setInstructorName
