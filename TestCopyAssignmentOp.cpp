/*
    (name header)
*/

#include "CourseList.h"
#include "CourseList.cpp"

#include <iostream>
using namespace std;

void testOpEqualEmptyObjs()
{
    // TEST ASSIGNMENT OPERATOR: PARAMETER OBJECT IS EMPTY
    
    // To print, create a variable of type string and use it
    // as an argument to call the function retrieveAllCourses().
    string tester = "";

    // Create two objects of the class CourseList:
    // courseList1 and courseList2
    CourseList courseList1;
    CourseList courseList2;

    // Print courseList1 (should be empty)
    courseList1.retrieveAllCourses(tester);
    // Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(tester);
    // CALL: courseList1 = courseList2;
    //courseList1.copyCallingObjIsEmpty(courseList2);
    courseList1 = courseList2;
    // Print courseList1 (should be empty)
    courseList1.retrieveAllCourses(tester);
    // Print courseList2 (should be empty)
    courseList1.retrieveAllCourses(tester);
}

void testOpEqSameLengthObjs()
{
    //TEST ASSIGNMENT OPERATOR: OBJECTS HAVE SAME LENGTH

    // To print, create a variable of type string and use it
    // as an argument to call the function retrieveAllCourses().
    string tester = "";

    // Create courseList1 with two courses: 131 and 272
    CourseList courseList1;
    courseList1.addCourse(131, "Python", 4, set<int>{100});
	courseList1.addCourse(262, "Discrete Structures", 4, set<int>{250});
    
    // Create courseList2 with two courses: 150 and 250
    CourseList courseList2;
    courseList2.addCourse(150, "C++ 1", 4, set<int>{170});
    courseList2.addCourse(250,"C++ 2", 4, set<int>{150, 170});
	
    // Print courseList1 (should show 131 and 272)
    courseList1.retrieveAllCourses(tester);

    // Print courseList2 (should show 150 and 170)
    courseList2.retrieveAllCourses(tester);

    // CALL: courseList1 = courseList2
    courseList1 = courseList2;

    // Print courseList1 (should show 150 and 170)
    courseList1.retrieveAllCourses(tester);

    // Print courseList2 (should show 150 and 170)
    courseList2.retrieveAllCourses(tester);

    // CLEAR courseList2
    courseList2.clearList();

    // Print courseList1 (should show 150 and 170)
    courseList1.retrieveAllCourses(tester);

    // Print courseList2 (should be empty)
    courseList1.retrieveAllCourses(tester);

}

void testOpEqCallingLonger()
{
    //TEST ASSIGNMENT OPERATOR : CALLING OBJ IS LONGER

    // To print, create a variable of type string and use it
    // as an argument to call the function retrieveAllCourses().
    string tester = "";

    // Create courseList1 with four courses: 131, 170, 257, and 272
    CourseList courseList1;
    courseList1.addCourse(131, "Python", 4, set<int>{100});
	courseList1.addCourse(170, "Java", 4, set<int>{});
	courseList1.addCourse(257, "Boolean Algebra and Logic", 4, set<int>{150});
    courseList1.addCourse(262, "Discrete Structures", 4, set<int>{150});

    // Create courseList2 with two courses: 150, and 250
    CourseList courseList2;
    courseList2.addCourse(150, "C++ 1", 4, set<int>{170});
    courseList2.addCourse(250,"C++ 2", 4, set<int>{150, 170});

    // Print courseList1 (should show 131, 170, 257, 272)
    courseList1.retrieveAllCourses(tester);

    // Print courseList2 (should show 150 and 170)
    courseList2.retrieveAllCourses(tester);

    // CALL: courseList1 = courseList2
    courseList1 = courseList2;

    // Print courseList1 (should show 150 and 170)
    courseList1.retrieveAllCourses(tester);

    // Print courseList2 (should show 150 and 170)
    courseList1.retrieveAllCourses(tester);

    // CLEAR courseList2
    courseList2.clearList();

    // Print courseList1 (should show 150 and 170)
    courseList1.retrieveAllCourses(tester);

    // Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(tester);

}

void testOpEqCallingShorter()
{
    //TEST ASSIGNMENT OPERATOR: CALLING OBJ IS SHORTER

    // To print, create a variable of type string and use it
    // as an argument to call the function retrieveAllCourses().
    string tester = "";

    // Create courseList1 with two courses: 131, 272
    CourseList courseList1;
    courseList1.addCourse(131, "Python", 4, set<int>{100});
	courseList1.addCourse(262, "Discrete Structures", 4, set<int>{150});

    // Create courseList2 with four courses: 150, 170, 250, and 257
    CourseList courseList2;
	courseList2.addCourse(150, "C++ 1", 4, set<int>{170});
    courseList2.addCourse(170, "Java", 4, set<int>{});
    courseList2.addCourse(250,"C++ 2", 4, set<int>{150, 170});
	courseList2.addCourse(257, "Boolean Algebra and Logic", 4, set<int>{150});
    
    // Print courseList1 (should show 131 and 272)
    courseList1.retrieveAllCourses(tester);

    // Print courseList2 (should show 150, 170, 250, 257)
    courseList2.retrieveAllCourses(tester);

    // CALL: courseList1 = courseList2
    courseList1 = courseList2;

    // Print courseList1 (should show 150, 170, 250, 257)
    courseList1.retrieveAllCourses(tester);

    // Print courseList2 (should show 150, 170, 250, 257)
    courseList1.retrieveAllCourses(tester);

    // CLEAR courseList2
    courseList2.clearList();

    // Print courseList1 (should show 150, 170, 250, 257)
    courseList1.retrieveAllCourses(tester);

    // Print courseList2 (should be empty)
    courseList2.retrieveAllCourses(tester);

}