#pragma once
#include "Data.h"
#include <iostream>
#include <fstream>

template <class T>
class Node
{
public:
	//c.contructor, contructor, deconstructor
	Node() : next(nullptr) {}
	inline Node(Node<T>* ptr, T newData) : data(newData), next(ptr) {}
	Node(const Node<T>& rhs);
	~Node();

	//setters & get
	void setData(T newData)			{ data = newData; }
	void setNext(Node<T>* pNext)	{ next = pNext; }

	T* getData() { return &data; }
	Node<T>* getNext() { return this->next; }

private:
	T data;//Holds all data
	Node<T>* next;
};

template<class T>
Node<T>::Node(const Node<T>& rhs)
{
	data = rhs.data;
	next = new Node<T>(rhs.next);
}
template<class T>
Node<T>::~Node()
{
	delete next;
}
