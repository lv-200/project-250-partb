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

// Definition function insertInOrder
// Assume there are no duplicates.
void CourseList::insertInOrder(Node* aNode)
{
    if (count == 0)
    {
        first = last = aNode;
    }
    else if (aNode->getCourse().getCourseNumber() <
        first->getCourse().getCourseNumber())
    {
        aNode->setNext(first);
        first = aNode;
    }
    else if (aNode->getCourse().getCourseNumber() >
             last->getCourse().getCourseNumber())
    {
        last = aNode;
        first->setNext(aNode);
    }
    else
    {
        Node* current = first->getNext();
        bool indexFound = false;

        while (current != nullptr && !indexFound)
        {
            if (current->getNext()->getCourse().getCourseNumber()
                > aNode->getCourse().getCourseNumber())
            {
                indexFound = true;
                Node* tempNode = current->getNext();
                current->setNext(aNode);
                aNode->setNext(tempNode);
            }
            else
            {
                current = current->getNext();
            }
        }
    }

    count++;
}