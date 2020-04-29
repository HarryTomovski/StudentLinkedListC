#pragma once
typedef struct Student
{
	char* firstName[30];
	char* lastName[30];
	int studentId;
	char* nationality[30];
}Student;
typedef struct Student* student_p;
student_p createStudent(char* firstName, char* lastname, int studentId, char* nationality);
void printInfo();