#pragma once
#include "Student.h"
#include "StudentList.h"
typedef struct StudentHandler
{
	studentList_p studentList;
}StudentHandler;
typedef struct StudentHandler* studenthandler_p;
studenthandler_p create_StudentHandler();
void printStudentInfo(studenthandler_p handler, student_p self, uint16_t index);
void printAllStudents(studenthandler_p handler);
void addStudent(studenthandler_p handler,student_p self);