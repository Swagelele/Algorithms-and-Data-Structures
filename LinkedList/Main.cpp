#include <iostream>
#include "LinkedList.cpp"
using namespace std;

int main()
{
    LinkedList* list = new LinkedList();

    // Add values to the tail of LinkedList
    for (int i = 1; i < 10; i++)
    {
        list->addLast(i);
    }
    
    cout << *list;
    
    // Find data
    list->findData(22);
    list->findData(7);
    
    // Delete first 2 elements
    list->deleteFirst();
    list->deleteFirst();
    cout << *list;

    // Add values to the head of LinkedList
    for (int i = 10; i < 20; i++)
    {
        list->addFirst(i);
    }
    cout << *list;

    // Delete last 2 elements
    list->deleteLast();
    list->deleteLast();
    cout << *list;

    // Delete list
    list->freeList();
    cout << *list;
}
