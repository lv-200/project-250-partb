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
using namespace std;

// Copy constructor
CourseList::CourseList(const CourseList& otherList)
{
    if (count == 0)
    {
        this->copyCallingObjIsEmpty(otherList);
    }
    else if (count == otherList.count)
    {
        this->copyObjectsSameLength(otherList);
    }
    else if (count > otherList.count)
    {
        this->copyCallingObjLonger(otherList);
    }
    else
    {
        this->copyCallingObjShorter(otherList);
    }
}

// Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList& rightSide)
{
    count = rightSide.count;
    first = rightSide.first;
    last = rightSide.last;
    return *this;
}

// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& aCourseList)
{
    Node* ptrParam = aCourseList.first;
    while (ptrParam != nullptr)
    {
        first = new Node(ptrParam->getCourse(), nullptr);
        ptrParam = ptrParam->getNext();
    }
    last = ptrParam;
    count = aCourseList.count;
}

// Definition function copyObjectsSameLength
void CourseList::copyObjectsSameLength(const CourseList& aCourseList)
{
    Node* ptrCalling = first;
    Node* ptrParam = aCourseList.first;

    while (ptrParam != nullptr)
    {
        ptrCalling->setCourse(ptrParam->getCourse());
        ptrCalling = ptrCalling->getNext();
        ptrParam = ptrParam->getNext();
    }

    last = ptrCalling;
    count = aCourseList.count;
}

// Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger(const CourseList& aCourseList)
{
    Node* ptrCalling = first;
    Node* ptrParam = aCourseList.first;

    while(ptrParam != nullptr)
    {
        ptrCalling->setCourse(ptrParam->getCourse());
        ptrCalling = ptrCalling->getNext();
        ptrParam = ptrParam->getNext();
    }

    while(ptrCalling != nullptr)
    {
        delete ptrCalling;
        ptrCalling = ptrCalling->getNext();
    }

    ptrCalling = nullptr;
    last->setNext(nullptr);
    count = aCourseList.count;
}

// Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter(const CourseList& aCourseList)
{
    Node* ptrCalling = first;
    Node* ptrParam = aCourseList.first;

    while (ptrParam != nullptr)
    {
        while (ptrCalling != nullptr)
        {
            ptrCalling->setCourse(ptrParam->getCourse());
            ptrCalling = ptrCalling->getNext();
            ptrParam = ptrParam->getNext();
        }

        ptrCalling = new Node(ptrParam->getCourse(), ptrCalling);
        ptrCalling = ptrCalling->getNext();
        ptrParam = ptrParam->getNext();
    }

    last = ptrCalling;
    count = aCourseList.count;
}

// Destructor
CourseList::~CourseList()
{
    if (count != 0)
    {
        clearList();
    }
}