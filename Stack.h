#pragma once
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::find;

//The Stack class must support push (), pop (), peek (), and isEmpty () operations
template <typename T>
class Stack
{
public:
	//c.contructor, contructor, deconstructor
	inline Stack() { absenceDate = new vector<T>(); }
	inline Stack(Stack& rhs) { }
	inline ~Stack() {}

	inline void push(T newDate) { absenceDate->emplace_back(newDate); }
	void pop() { absenceDate->pop_back(); }
	T peek();
	bool isEmpty() { return absenceDate->empty(); }
	size_t size() { return absenceDate->size(); }
	size_t find(const T data);
	inline T at(size_t pos) { return absenceDate->at(pos); }


private:
	/*student absence date*/
	vector<T>* absenceDate;
};

template <class T>
T Stack<T>::peek()
{
	if (!isEmpty()) {
		return absenceDate->front();
	}
	else {
		return T();
	}
}

template <class T>
size_t Stack<T>::find(const T data) {
	auto pos = std::find(absenceDate->begin(), absenceDate->end(), data);

	if (pos != absenceDate->end()) {
		size_t index = pos - absenceDate->begin();
		return index;
	}
	else {
		return -1;
	}
}