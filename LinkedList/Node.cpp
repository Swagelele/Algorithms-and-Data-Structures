#pragma once
#include <iostream>

class Node
{
private:
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;

public:
    Node() = default;
    Node(int data) : data(data) {}

    int getData() const { return data; }
    Node* getNext() const { return next; }
    Node* getPrev() const { return prev; }

    void setNext(Node* next) { this->next = next; }
    void setPrev(Node* prev) { this->prev = prev; }
    void setData(int data) { this->data = data; }

};
