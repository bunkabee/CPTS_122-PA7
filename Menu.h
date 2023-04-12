#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Data.h"
#include "List.h"
#include <ctime>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <chrono>
using std::fstream;
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::stoi;
using std::to_string;


//class menu
class Menu
{
public:
	//c.contructor, contructor, deconstructor
	Menu() : masterList(new List<Data>()) {}
	Menu(Menu& rhs) { masterList = rhs.masterList; }
	~Menu() {}
	// Menu
	void clearScreen();
	void displayMenu();
	void runMenu();
	string parseInput(string& data, const char& delim);
	string fixName(string& name);
	void printList();
	void loadList();
	void importList();
	void storeList();
	void reportAll();
	void reportMarked();
	void editAbsence();//bonus
	string getDate();
	string markAbs(string name);
	void markAbs();
private:
	List<Data>* masterList; // all student list
};