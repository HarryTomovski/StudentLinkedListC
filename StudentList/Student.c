#include "Student.h"
#include <stdlib.h>
#include <string.h>
student_p createStudent(char* firstName, char* lastname, int studentId, char* nationality)
{
	student_p _newStudent =(Student*)calloc(sizeof(Student), 1);
	if (_newStudent!=NULL)
	{
		strcpy(_newStudent->firstName, firstName,sizeof(_newStudent->firstName)-1);
		strcpy(_newStudent->lastName, lastname, sizeof(_newStudent->lastName) - 1);
		_newStudent->studentId = studentId;
		strcpy(_newStudent->nationality, firstName, sizeof(_newStudent->nationality) - 1);
		
	}
	else
	{
		_newStudent = NULL;
	}
	return _newStudent;
}
void printInfo();