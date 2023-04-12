#include "Data.h"
// data field
Data::Data()
{
	this->email = "";
	this->lastName = "";
	this->firstName = "";
	this->id = 0;
	this->level = "";
	this->program = "";
	this->record = 0;
	this->units = "";
	this->totalAbsence = 0;
	this->absence = new Stack<string>();
}
//deconstructor
Data::~Data()
{
}

void Data::modifyAbsnce(const string& oldDate, const string& newDate) {
	Stack<string> temp;
	bool found = false;

	while (!absence->isEmpty()) {
		string date = absence->peek();
		if (date == oldDate) {
			temp.push(newDate);
			found = true;
		}
		else {
			temp.push(date);
		}
		absence->pop();
	}
	if (found) {
		while (!temp.isEmpty()) {
			absence->push(temp.peek());
		}
	}
	else {
		absence->push(newDate);
	}
}