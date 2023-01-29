#pragma once
#include <iostream>
#include "Node.cpp"
using namespace std;

class LinkedList
{
private:
	Node* head;
	Node* tail;

public:
	LinkedList() = default;


	Node* getHead() const { return head; }
	Node* getTail() const { return tail; }


	void addFirst(int data)
	{
		Node* newNode = new Node(data);

		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->setNext(head);
			head->setPrev(newNode);
			head = newNode;
		}
	}

	void addLast(int data) 
	{
		Node* newNode = new Node(data);

		if (head == nullptr)
		{
			head = tail = newNode;
			return;
		}
		
		tail->setNext(newNode);
		newNode->setPrev(tail);
		tail = newNode;
	}

	void deleteFirst()
	{
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}

		if (head->getNext() == nullptr)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			return;
		}

		Node* current = head->getNext();
		delete head;
		head = current;
		head->setPrev(nullptr);
	}

	void deleteLast()
	{
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}

		if (head->getNext() == nullptr)
		{
			delete head;
			head = tail = nullptr;
			return;
		}

		Node* prev = tail->getPrev();
		delete tail;
		tail = prev;
		tail->setNext(nullptr);
	}

	void findData(int data)
	{
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}
		
		Node* current = head;

		while (current != nullptr && current->getData() != data)
		{
			current = current->getNext();
		}

		if(current == nullptr)
			cout << "Data NOT found: " << data << endl;
		else
			cout << "Data found: "<< data << endl;
	}
	
	void printList()
	{
		if (head == nullptr)
		{
			cout << "List is empty" << endl;
			return;
		}
		
		cout << "List contains: " << endl;
		Node* current = head;

		while (current != nullptr)
		{
			cout << " " << current->getData() << endl;
			current = current->getNext();
		}
		cout << endl;
	}

	void freeList()
	{
		if (head == nullptr && tail == nullptr)
		{
			std::cout << "List is empty." << std::endl;
			return;
		}

		Node* current = head;
		Node* temp = nullptr;
		while (current != nullptr)
		{
			temp = current->getNext();
			delete current;
			current = temp;
		}

		head = nullptr;
		tail = nullptr;
	}

	friend ostream& operator<<(ostream& out, const LinkedList& list)
	{
		if (list.head == nullptr)
		{
			out << "List is empty." << endl;
			return out;
		}

		Node* current = list.head;
		out << "Elements: " << endl;
		while (current != nullptr)
		{
			out << "  " << current->getData() << endl;
			current = current->getNext();
		}
		out << endl;
		return out;
	}
};
