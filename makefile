CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 $(DEBUG) -O0 -pedantic-errors
LFLAGS = -Wall $(DEBUG)

main: main.cpp student.cpp instructor.cpp
        $(CC) $(CFLAGS) -o main main.cpp
        $(CC) $(CFLAGS) -o student student.cpp
        $(CC) $(CFLAGS) -o instructor instructor.cpp

student: student.cpp
        $(CC) $(CFLAGS) -o student student.cpp

instructor: instructor.cpp
        $(CC) $(CFLAGS) -o instructor instructor.cpp
clean:
        rm -rf main
        rm -rf instructor
        rm -rf student
        rm -rf *.o
