#include "Menu.h"

const string INFILE = "classList.csv";
const string OUTFILE = "master.csv";

void Menu::clearScreen() {
	for (int i = 0; i < 50; i++) {
		cout << endl;
	}
}

string Menu::parseInput(string& data, const char& delim) {
	string parsed = "";

	parsed = data.substr(0, data.find(delim));

	data.erase(0, data.find(delim) + 1);

	return parsed;
}

void Menu::displayMenu() {

	cout << std::setw(79) << std::setfill('*') << " " << std::endl << std::setfill(' ');
	cout << std::setw(45) << "Attendance Tracker" << std::endl;
	cout << std::setw(79) << std::setfill('*') << " " << std::endl << std::endl << std::setfill(' ');

	cout << "1. Import Course List" << endl;
	cout << "2. Load master list" << endl;
	cout << "3. Store master list" << endl;
	cout << "4. Mark absences" << endl;
	cout << "5. Edit absences" << endl;
	cout << "6. Generate report" << endl;
	cout << "7. Exit" << endl << endl;

	cout << "Please enter choice: ";

}
/*----------------------------------------------------------------------------run menu-------------------------------------------------------------------------------------------*/
void Menu::runMenu()
{
	int choice = 0;
	int subChoice = 0;

	while (choice != 7)
	{
		displayMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			clearScreen();
			importList();
			break;
		case 2:
			clearScreen();
			loadList();
			break;
		case 3:
			clearScreen();
			storeList();
			break;
		case 4:
			clearScreen();
			markAbs();
			break;
		case 5:
			clearScreen();
			editAbsence();
			break;
		case 6:
			clearScreen();
			cout << "1. Generate report for all students\n ";
			cout << "2. Generate report for matched input (e.g 1) ";
			cin >> subChoice;
			if (subChoice == 1)
			{
				clearScreen();
				reportAll();
				break;
			}
			else
			{
				clearScreen();
				reportMarked();
				break;
			}
		}
	}
	cout << "Exiting Program..." << endl;
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------print list--------------------------------------------------------------------------------------------*/
void Menu::printList()
{
	Node<Data>* seek = masterList->getHead();

	while (seek != nullptr)
	{
		//stack overflow refrence
		cout << seek->getData()->getRecord() << "," << seek->getData()->getId() << ",\"" << seek->getData()->getLastName() << "," << seek->getData()->getFirstName() << "\"," << seek->getData()->getEmail() << "," <<
			seek->getData()->getUnits() << "," << seek->getData()->getProgram() << "," << seek->getData()->getLevel() << "[" << seek->getData()->getTotalAbs() << "," <<
			seek->getData()->getAbsence() << "]" << endl;	seek = seek->getNext();
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-------------------------------------------------------------------------import List-----------------stack overflow refrence-----------------------------------------------------------------------------*/

void Menu::importList()
{
	fstream infile;
	string line = "";
	Data* newData;
	infile.open(INFILE);

	getline(infile, line);
	if (infile) {

		if (!masterList->isEmpty()) {
			cout << "Destroying current list...." << endl;
			masterList->destroyList();
		} 

		while (getline(infile, line)) {
			newData = new Data();

			newData->setRecord(stoi(parseInput(line, ',')));
			newData->setId(stoi(parseInput(line, ',')));
			parseInput(line, '\"');
			newData->setLastName(parseInput(line, ','));
			newData->setFirstName(parseInput(line, '\"'));
			parseInput(line, ',');
			newData->setEmail(parseInput(line, ','));
			newData->setUnits(parseInput(line, ','));
			newData->setProgram(parseInput(line, ','));
			newData->setLevel(parseInput(line, ','));

			masterList->insert(newData);
		}
	}
	else {
		std::cerr << "Could not open file to import master list. Please try again." << endl;
	}
	infile.close();
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------Load List------------------------------------------------------------------------------------------------*/
void Menu::loadList()
{
	fstream infile;
	string line = "";
	Data* newData;
	infile.open(INFILE);

	getline(infile, line);
	if (infile) {
		while (getline(infile, line)) {
			newData = new Data();

			newData->setRecord(stoi(parseInput(line, ',')));
			newData->setId(stoi(parseInput(line, ',')));
			parseInput(line, '\"');
			newData->setLastName(parseInput(line, ','));
			newData->setFirstName(parseInput(line, '\"'));
			parseInput(line, ',');
			newData->setEmail(parseInput(line, ','));
			newData->setUnits(parseInput(line, ','));
			newData->setProgram(parseInput(line, ','));
			newData->setLevel(parseInput(line, ','));

			masterList->insert(newData);
		}


		infile.close();
	}
	else {
		std::cerr << "Could not open file to import master list. Please try again." << endl;
	}
}

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------Store List-------------------------------------------------------------------------------------------------*/
void Menu::storeList()
{
	Node<Data>* current = masterList->getHead();
	fstream outfile;
	outfile.open(OUTFILE, std::ofstream::out | std::ofstream::trunc);

	if (outfile.is_open())
	{
		if (!masterList->isEmpty()) {
			while (current != nullptr)
			{
				outfile << current->getData()->getRecord() << ",";
				outfile << current->getData()->getId() << ",\"";
				outfile << current->getData()->getLastName() << ",";
				outfile << current->getData()->getFirstName() << "\",";
				outfile << current->getData()->getEmail() << ",";
				outfile << current->getData()->getUnits() << ",";
				outfile << current->getData()->getProgram() << ",";
				outfile << current->getData()->getLevel() << ",";
				outfile << current->getData()->getTotalAbs() << ",";
				outfile << current->getData()->getAbsence() << endl;
				current = current->getNext();
			}
			cout << "List Stored" << endl;
		}
		else {
			std::cerr << "The list is empty. Cannot store." << endl;
			outfile.close();
		}
	}
	else {
		std::cerr << "Could not open " << OUTFILE << " to write to." << endl;
	}
}
string Menu::getDate() {

	string date = " ";
	// Get the current time point
	auto now = std::chrono::system_clock::now();

	// Convert the time point to a time_t object
	std::time_t t = std::chrono::system_clock::to_time_t(now);

	// Convert the time_t object to a tm object representing the local time
	std::tm* local_time = std::localtime(&t);

	// Extract the date components from the tm object
	string year = to_string(local_time->tm_year + 1900);
	string month = to_string(local_time->tm_mon + 1);
	string day = to_string(local_time->tm_mday);

	date = month + "/" + day + "/" + year;

	// Output the date in YYYY-MM-DD format
	//std::cout << date << endl;

	return date;
}

void Menu::markAbs()
{
	char choice = ' ';
	string date = getDate();
	string name = " ";

	auto current = masterList->getHead();

	while (current != nullptr) {
		name = current->getData()->getFirstName() + " " + current->getData()->getLastName();

		cout << "Is " << name << " present on " << date << "?" << endl;
		cout << "Enter Y if present and N if absent. ";
		cin >> choice;

		if (choice == 'n' || choice == 'N') {
			current->getData()->setAbsence(date);
		}
		current = current->getNext();
	}
}
/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------reportAll-------------------------------------------------------------------------------------------*/
void Menu::reportAll()
{
	Node<Data>* seek = masterList->getHead();
	fstream outfile;
	outfile.open("reportAll.txt", std::ofstream::out | std::ofstream::trunc);
	if (outfile.is_open())
	{
		while (seek != nullptr)
		{
			outfile << "Absence Report for: " << seek->getData()->getFirstName() << " " << seek->getData()->getLastName() << endl;
			outfile << "Days Absent: " << seek->getData()->getTotalAbs() << endl << "Date of Absense: " << seek->getData()->getAbsence() << endl;
			outfile << "-------------------------------------------" << endl;
			seek = seek->getNext();
		}
	}
	outfile.close();

}

void Menu::reportMarked()
{
	int choice = 0;
	Node<Data>* seek = masterList->getHead();
	fstream outfile;
	outfile.open("reportMarked.txt", std::ofstream::out | std::ofstream::trunc);

	cout << "Total days absent: ";
	cin >> choice;

	if (outfile.is_open())
	{
		while (seek != nullptr)
		{
			if (seek->getData()->getTotalAbs() >= choice)
			{
				//outfile << "Absence Report for: " << seek->getData()->getName() << endl;
				outfile << "Total Days Absent: " << seek->getData()->getTotalAbs() << endl << "Date of Absense: " << seek->getData()->getAbsence() << endl;
				outfile << "-------------------------------------------" << endl;
			}
			seek = seek->getNext();
		}
	}

	outfile.close();

}

void Menu::editAbsence()
{
	Node<Data>* seek = masterList->getHead();
	int id = 0;
	string date;
	cout << "Use Student Id to Search for Absense: ";
	cin >> id;


	while (seek != nullptr)
	{
		/*BONUS: Edit absences - The user of the program should be able to access each studentfs record and edit absences.
		A search (linear time) through the master list based on student ID or name must be supported. If a student was
		initially marked absent for a date, but later was determined to be present, then the absence should be removed from
		the record. This includes updating the number of absences field. Be sure to add an Edit option to your menu!  */
		if (seek->getData()->getId() == id)
		{
			//cout << "Student: " << seek->getData()->getName() << endl;
			cout << "Enter exact date to edit: ";
			cin >> date;
			seek->getData()->findAbs(date);
			//seek->getData()->setTotalAbs();
			//cout << seek->getData()->getName() << " Is no longer marked Absent for" << date << endl;
			cout << "Total Days Absent: " << seek->getData()->getTotalAbs() << endl << "Date of Absence: "
				<< seek->getData()->getAbsence() << endl;
			cout << "-------------------------------------------" << endl;
			break;
		}
		seek = seek->getNext();
	}
}