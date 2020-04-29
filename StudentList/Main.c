#include <stdio.h>
#include "Student.h"
#include "StudentHandler.h"
#include "StudentList.h"
#include "StudentHandler.h"



int main()
{
	
	
	StudentHandler* handler = create_StudentHandler();
	Student* Dummy = createStudent("Dummy", "Dummy", 280015, "Dummy");
	Student* Kiril = createStudent("Kiril", "Iliev", 280016, "Bulgarian");
	Student* Karla =  createStudent("Karla", "Jajic", 280017, "Croation");
	Student* Harry = createStudent("Harry", "Tomovski", 280018, "Bulgarian");
	

	addStudent(handler, Harry);
	addStudent(handler, Karla);
	addStudent(handler, Kiril);
	
	printf("Number of students in list: %d\n", numberOfStudents(handler->studentList));
	printf("First name: %s Last name: %s Nationality: %s StudentId: %d\n\n", Dummy->firstName, Dummy->lastName, Dummy->nationality, Dummy->studentId);
	printStudentInfo(handler,&Dummy,1);
	printf("First name: %s Last name: %s Nationality: %s StudentId: %d\n\n", Dummy->firstName, Dummy->lastName, Dummy->nationality, Dummy->studentId);
	
	printAllStudents(handler);
	

}