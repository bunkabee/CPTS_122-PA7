#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"
using std::fstream;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::stoi;
// data class
class Data
{
private:
	int record;
	int id;
	size_t totalAbsence;
	string lastName;
	string firstName;
	string email;
	string units;
	string program;
	string level;
	Stack<string>* absence;
public:
	//c.contructor, contructor, deconstructor
	Data();
	inline Data(Data& rhs) : record(rhs.record), id(rhs.id), totalAbsence(rhs.totalAbsence),
					  lastName(rhs.lastName), firstName(rhs.firstName),
					  email(rhs.email), units(rhs.units), program(rhs.program),
					  level(rhs.level) 
			{
			absence = new Stack<string>(*rhs.absence);
			}
	~Data();
	//setters & getter
	inline void setRecord(int newRec)		{ record = newRec; }
	inline void setId(int newId)			{ id = newId; }
	inline void setLastName(string newN)	{ lastName = newN; }
	inline void setFirstName(string newN)	{ firstName = newN; }
	inline void setEmail(string newE)		{ email = newE; }
	inline void setUnits(string newU)		{ units = newU; }
	inline void setProgram(string newP)		{ program = newP; }
	inline void setLevel(string newL)		{ level = newL; }
	inline void setAbsence(string newAbs)	{ absence->push(newAbs); }
	
	inline void findAbs(string date) { this->absence->find(date); }

	inline int getRecord()			{ return this->record; }
	inline int getId()				{ return this->id; }
	inline string getLastName()		{ return this->lastName; }
	inline string getFirstName()	{ return this->firstName; }
	inline string getEmail()		{ return this->email; }
	inline string getUnits()		{ return this->units; }
	inline string getProgram()		{ return this->program; }
	inline string getLevel()		{ return this->level; }
	inline size_t getTotalAbs()		{ return this->absence->size(); }
	inline string getAbsence()		{ return absence->peek(); }

	void modifyAbsnce(const string& oldDate, const string& newDate);

};
