#include "StudentHandler.h"
#include "StudentList.h"
#include <stdio.h>


studenthandler_p create_StudentHandler()
{
	studenthandler_p _newHandler = calloc(sizeof(StudentHandler), 1);
	if (_newHandler != NULL)
	{
		_newHandler->studentList = create_StudentList();

	}

	return _newHandler;
}
void printStudentInfo(studenthandler_p handler, student_p student_out,uint16_t index)
{
		getStudentAtIndex(handler->studentList, student_out, index);
		//printf("First name: %s Last name: %s Nationality: %s StudentId: %d", *student_out->firstName, *student_out->lastName, *student_out->nationality, student_out->studentId);

}
void printAllStudents(studenthandler_p handler)
{
	Student* out;
	for (size_t i = 0; i < numberOfStudents(handler->studentList); i++)
	{
		getStudentAtIndex(handler->studentList, &out, i);
		printf("First name: %s Last name: %s Nationality: %s StudentId: %d\n", out->firstName, out->lastName, out->nationality, out->studentId);
	}
}

void addStudent(studenthandler_p list, student_p student)
{
	//Student* _newStudent = createStudent(self->firstName, self->lastName, self->studentId, self->nationality);
	list_ReturnCode_t code = adapter_addStudent(list->studentList,student);
	printf("List return code for addStudent: %d\n", code);
}
