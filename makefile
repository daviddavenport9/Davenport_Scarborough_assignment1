CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 $(DEBUG) -O0 -pedantic-errors
LFLAGS = -Wall $(DEBUG)

main: main.cpp Student.cpp Instructor.cpp
        $(CC) $(CFLAGS) -o main main.cpp
        $(CC) $(CFLAGS) -o Student Student.cpp
        $(CC) $(CFLAGS) -o Instructor Instructor.cpp

student: Student.cpp
        $(CC) $(CFLAGS) -o Student Student.cpp

instructor: Instructor.cpp
        $(CC) $(CFLAGS) -o Instructor Instructor.cpp
clean:
        rm -rf main
        rm -rf Instructor
        rm -rf Student
        rm -rf *.o
