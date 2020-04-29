#pragma once
#include "List.h"
typedef struct StudentList
{
	list_p adaptee;
}StudentList;
typedef struct Student* student_p;
typedef struct StudentList* studentList_p;
studentList_p create_StudentList();
list_ReturnCode_t adapter_addStudent(studentList_p list,student_p student);
list_ReturnCode_t getStudentAtIndex(studentList_p list, student_p student,uint16_t index);
list_ReturnCode_t removeStudent(studentList_p list, student_p student);
uint16_t numberOfStudents(studentList_p list);
