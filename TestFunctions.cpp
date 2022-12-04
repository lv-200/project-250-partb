/*
	(name header)
*/

#include "CourseList.h"
#include "CourseList.cpp" //remove!! for all three below
#include "Course.h"
#include "Course.cpp"

#include <iostream>
using namespace std;

void testCourseList()
{
	// Create an object of the class CourseList.
	CourseList courseList1;

	// Call function CourseList::isEmpty and print a message.
	cout << courseList1.isEmpty();

	// NOTE: To properly test the functions, it is 
	// recommended you use the course number 
	// suggested in this guideline.


	// Create three objects of the class Course using
	// the overloaded constructor.
	// Courses: 250, 150, 200
	Course course1(250,"C++ 2", 4, set<int>{150, 170});
	Course course2(150, "C++ 1", 4, set<int>{170});
	Course course3(200, "Data Structures", 4, set<int>{250});

	// Call function CourseList::addCourse(Course) to add the three courses.
	courseList1.addCourse(course1);
	courseList1.addCourse(course2);
	courseList1.addCourse(course3);

	// Call function CourseList::addCourse(int, string, int, set)
	// to add three additional courses: 131, 272, 216
	courseList1.addCourse(131, "Python", 4, set<int>{100});
	courseList1.addCourse(262, "Discrete Structures", 4, set<int>{250});
	courseList1.addCourse(216, "Computer Architecture", 4, set<int>{150, 170});

	// Create a string and use it as a parameter to 
	// call function CourseList::retrieveAllCourses().
	// Print the string.
	string testRetrieveAllCourses = "";
	courseList1.retrieveAllCourses(testRetrieveAllCourses);

	// Call CourseList::search(int) to search for 150.
	courseList1.searchCourse(150);

	// Create a string to store a course name, and 
	// call CourseList::search(int, string) to 
	// retrieve the name of the course and print it.
	string cpp = "C++ 1";
	courseList1.searchCourse(150, cpp);
	
	// Create an empty course by using the default constructor.
	Course course;

	// Call function CourseList::search(int, Course) to 
	// retrieve the course and print the prefix, the number
	// the name and the units.
	courseList1.searchCourse(131, course);

	// Call function CourseList::deleteCourse to delete 131.
	courseList1.deleteCourse(131);

	// Call function CourseList::deleteCourse to delete 272.
	courseList1.deleteCourse(272);

	// Call function CourseList::deleteCourse to delete 150.
	courseList1.deleteCourse(150);

	// Call function CourseList::deleteCourse to delete 250.
	courseList1.deleteCourse(250);

	// Print all courses to see what is left in the list.
	courseList1.retrieveAllCourses(testRetrieveAllCourses);
}
