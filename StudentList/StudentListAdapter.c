#include "StudentList.h"
#include <stdint.h>
#include "List.h"

studentList_p create_StudentList()
{
	studentList_p _newList = calloc(sizeof(StudentList), 1);
	if (_newList != NULL)
	{
		_newList->adaptee = list_create();
		
	}
	
	return _newList;
}
list_ReturnCode_t adapter_addStudent(studentList_p list, student_p student)
{
	return list_addItem(list->adaptee,student);
}
list_ReturnCode_t getStudentAtIndex(studentList_p list, student_p student,uint16_t index)
{
	return list_getItem(list->adaptee, student, index);

}
list_ReturnCode_t removeStudent(studentList_p list,  student_p student)
{
	return list_removeItem(list->adaptee, student);
}

uint16_t numberOfStudents(studentList_p list)
{
	return list_noOfItems(list->adaptee);
}