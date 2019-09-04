#include <iostream>
#include "Student.h"
#include "Instructor.h"
#include <string>

using namespace std;
int main(const int argc, const char * array[]){
  if (argc != 3) {
    cout << "Error: There are not 2 arguments being passed in" << endl;
    exit(0);
  }if ((strcmp(array[1], "instructors.txt") != 0) && (strcmp(array[2], "students.txt") == 0)){
    cout << "Error: cannot parse instructors information from file " << array[1] << endl;
    exit(0);
  }if ((strcmp(array[1], "instructors.txt") == 0) && (strcmp(array[2], "students.txt") != 0)){
    cout << "Error: cannot parse students information from file " << array[2] << endl;
    exit(0);
  }if ((strcmp(array[1], "instructors.txt") != 0) && (strcmp(array[2], "students.txt") != 0)){
    cout << "Error: cannot parse instructors information from file " << array[1] << " and students information from file " << array[2] <<  endl;
    exit(0);
  } // if                                                                                                                                                                                            
  int userType;
  string username;
  string password;
  string studentUsername;
  while (true){
    cout << "User types," << endl;
    cout << "  1 - Instructor" << endl;
    cout << "  2 - Student" << endl;
    cout << "Select a login user type or enter 3 to exit: ";
    cin >> userType;
    if (userType == 3){
      exit(0);
    }//if                                                                                                                                                                                            
    if((userType != 1) && (userType !=  2) && (userType != 3)) {
      cout << "Invalid option. Please enter a valid option" << endl;
      continue;
    }//if                                                                                                                                                                                            
    if (userType == 1) //flow for an instructor                                                                                                                                                      
      {
	cout << "Enter credentials to login," << endl;
        cout << "  Enter username: ";
	cin >> username;
        cout << "  Enter password: ";
        cin >> password;
        cout << "" << endl;//formatting                                                                                                                                                              
        Instructor instructor;
	if (instructor.login(username, password) != true)
          {
            continue;
          }//if                                                                                                                                                                                      
        cout << "You are now logged in as " << instructor.getInstructorName() << endl;
        cout << "" << endl;//formatting                                                                                                                                                              
        bool queryValue = true;
        while (queryValue){
          cout << "Query Options," << endl;
          cout << "  1 - View grades of a student" << endl;
          cout << "  2 - View stats" << endl;
          int queryOption;
          cout << "Enter option number: ";
          cin >> queryOption;
          if(queryOption == 1){
            cout << "Enter student username to view grades: ";
            cin >> studentUsername;
            if (instructor.checkUsername(studentUsername))
              {
                Student student = instructor.getStudent(studentUsername);
                cout << "Student name: "  << student.getStudentName() << endl;
                cout << "\tProject : "  << student.getProjectGrade() << "%" <<  endl;
                cout << "\tQuiz : "  << student.getQuizGrade() << "%" <<  endl;
                cout << "\tMidterm : "  << student.getMidtermGrade() << "%" <<  endl;
                cout << "\tFinal : "  << student.getFinalGrade() << "%" <<  endl;
                cout << "\tOverall : "  << student.getOverallGrade() << "%" <<  endl;
                queryValue = false;
              }//if                                                                                                                                                                                  
            else{
              cout << "Student username is not valid" << endl;
            } //else                                                                                                                                                                                 
          }//if                                                                                                                                                                                      
          if(queryOption == 2){//if query is 2                                                                                                                                                       
            int gradeType;
            cout << "Grade types" << endl;
            cout << "\t1- Project grade" << endl;
            cout << "\t2 - Quiz grade" << endl;
            cout << "\t3 - Midterm grade" << endl;
            cout << "\t4 - Final grade" << endl;
            cout << "\t5 - Overall grade" << endl;
            cout << "Select a grade type to view stats: ";
            cin >> gradeType;
            if((gradeType < 1) || (gradeType > 5)){
              cout << "Invalid Option. Please enter a valid option." << endl;
              queryValue = false;
            } // if                                                                                                                                                                                  
            Student student = instructor.getMinStudent(gradeType);
            if(gradeType == 1){ // project                                                                                                                                                           
              cout << "Project grade stats, " << endl;
              cout << "\tmin " << student.getProjectGrade() << "% (" << student.getStudentName() << ")" << endl;
            }if(gradeType == 2){ // quiz                                                                                                                                                             

            }if(gradeType == 3){ // midterm                                                                                                                                                          

            }if(gradeType == 4){ // final                                                                                                                                                            

            }if(gradeType == 5){ // overall                                                                                                                                                          

            } // if                                                                                                                                                                                  
          } // if                                                                                                                                                                                    
        }//while                                                                                                                                                                                     
      }//if                                                                                                                                                                                          


    if (userType == 2){//flow for a student                                                                                                                                                          
      cout << "Enter credentials to login," << endl;
      cout << "  Enter username: ";
      cin >> username;
      cout << "  Enter password: ";
      cin >> password;
      cout << "" << endl;//formatting                                                                                                                                                                
      Student student;
      if (student.login(username, password) != true){
        continue;
      }//if                                                                                                                                                                                          
      cout << "You are now logged in as " << student.getStudentName() << endl;
      cout << "" << endl;//formatting                                                                                                                                                                
      cout << "Do you want to view grades (y/n)?";
      string gradeResponse;
      cin >> gradeResponse;
      if (gradeResponse != "y"){
        continue;
      }//if                                                                                                                                                                                          
      cout << "Student name: " << student.getStudentName() << endl;
      cout << "\tProject" << student.getProjectGrade()  << "%" << endl;
      cout << "\tQuiz" << student.getQuizGrade()  << "%" << endl;
      cout << "\tMidterm" << student.getMidtermGrade()  << "%" << endl;
      cout << "\tFinal" << student.getFinalGrade() << "%" << endl;
      cout << "\tOverall" << student.getOverallGrade() << "%\n" << endl;                                                                                                                                                            
      continue;
    }//if                                                                                                                                                                                            


  }//while                                                                                                                                                                                           

  return EXIT_SUCCESS;
} // main                                                   
