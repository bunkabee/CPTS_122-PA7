#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
using std::fstream;
using std::cout;
using std::cin;


template <class T>
class List
{
public:
	List();
	List(List<T>& rhs);
	~List() { destroyList(); }

	inline void setHead(Node<T>* pHead) { head = pHead; }

	inline Node<T>* getHead() { return head; }
	
	inline void insert(T* newData);
	inline bool isEmpty() { return head == nullptr; }

	void destroyList();


private:
	Node<T>* head;
};

template <class T>
List<T>::List()
{
	this->head = nullptr;
}

template <class T>
List<T>::List(List<T>& rhs) {
	if (rhs.head == nullptr) {
		head = nullptr;
		return;
	}
	head = new Node<T>(*rhs.head);
	Node<T>* current = head;
	Node<T>* rhsCurrent = rhs.head->getNext();

	while (rhsCurrent != nullptr) {
		current->setNext(new Node<T>(*rhsCurrent));
		current = current->getNext();
		rhsCurrent = rhsCurrent->getNext();
	}
}

template <class T>
void List<T>::insert(T* newData)
{
	Node<T>* newNode = new Node<T>();
	newNode->setData(*newData);
	newNode->setNext(head);
	head = newNode;
}

template <class T>
void List<T>::destroyList() {
	Node<T>* current = head;

	while (current != nullptr) {
		Node<T>* temp = current;

		current = current->getNext();

		delete temp;
	}
	head = nullptr;
}