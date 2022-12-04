/*
    BLACKPINK

    To, Claire
    Vo, Leanne
    Ha, Tri

    Fall 2022
    CS A250 - C++ 2
    Project: CS Courses
*/

#include "CourseList.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Definition function addCourse
void CourseList::addCourse(const Course& newCourse)
{
    insertInOrder(new Node(newCourse, nullptr));
}

// Definition function addCourse
void CourseList::addCourse(int newCourseNumber, const string& newCourseName,
                           int newCourseUnits, const set<int>& newPrereqs)
{
    insertInOrder(new Node(Course(newCourseNumber,
                                  newCourseName, newCourseUnits,
                                  newPrereqs), nullptr));
}

// Definition function getPrefix
string CourseList::getPrefix()
{
    return Course::getPrefix();
}

// Definition function getNumberOfCourses
bool CourseList::getNumberOfCourses() const
{
    return count;
}

// Definition function isEmpty
bool CourseList::isEmpty() const
{
    return (count == 0);
}

// Definition function searchCourse (courseNumber)
// Assume list is non-empty.
Node* CourseList::searchCourse(int aCourseNumber) const
{
    return getCourseLocation(aCourseNumber);
}

// Definition function searchCourse (courseNumber, courseName)
// Assume list is non-empty.
void CourseList::searchCourse(int aCourseNumber, std::string& aCourseName) const
{
    aCourseName = getCourseLocation(aCourseNumber)->getCourse().getCourseName();
}

// Definition function searchCourse(courseNumber, course) 
// Assume list is non-empty.
void CourseList::searchCourse(int aCourseNumber, Course& aCourseObj) const
{
    aCourseObj = getCourseLocation(aCourseNumber)->getCourse();
}

// Definition deleteCourse
// Assume list is non-empty.
// Assume course is in the list.
void CourseList::deleteCourse(int aCourseNumber)
{
    Node* current = first;
    bool found = false;
    while (current != nullptr && !found)
    {
        if (current->getCourse().getCourseNumber() == aCourseNumber)
        {
            found = true;
            delete current;
            current = nullptr;
        }
        current = current->getNext();
    }
}

// Definition retrieveAllCourses
// Assume list is non-empty.
void CourseList::retrieveAllCourses(string& courses) const
{
    ostringstream out;
    Node* current = first;
    while(current != nullptr)
    {
        out << getPrefix()
            << current->getCourse().getCourseNumber()
            << " - " << current->getCourse().getCourseName() << endl;
    }
    courses = out.str();
}

// Definition clearList
void CourseList::clearList()
{
    Node* temp = first;
    while (first != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }
    count = 0;
    last = first;
}

// Definition function getCourseLocation
Node* CourseList::getCourseLocation(int aCourseNumber) const
{
    Node* current = first;
    while (current != nullptr)
    {
        if (current->getCourse().getCourseNumber() == aCourseNumber)
        {
            return current;
        }
        current = current->getNext();
    }
}

