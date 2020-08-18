/*************************************************
* ADS Praktikum 2.2
* main.cpp
*
*************************************************/
#define CATCH_CONFIG_RUNNER
#include <iostream>
#include <string>
#include <fstream>
#include "Tree.h"
#include "catch.h"

using namespace std;

	///////////////////////////////////////
	// Hilfsmethoden fürs Menü hier:
struct Person
{
	string Name;
	string Alter;
	string Einkommen;
	string PLZ;
};

istream& read(istream& in, Person& p)
{
	getline(in, p.Name, ';');
	getline(in, p.Alter, ';');
	getline(in, p.Einkommen, ';');
	getline(in, p.PLZ, '\n');
	return in;
}


	//
	///////////////////////////////////////
int main() {

	int result = Catch::Session().run();

	///////////////////////////////////////
	// Ihr Code hier:

	int postid;
	char select, wahl;
	string Name;
	int Alter;
	double Einkommen;
	int PLZ;
	Tree file;

	cout << "1) Datensatz einfuegen, manuell" << endl <<
		"2) Datensatz einfuegen, CSV Datei" << endl <<
		"3) Datensatz loeschen" << endl <<
		"4) Suchen" << endl <<
		"5) Datenstruktur anzeigen" << endl <<
		"?>" << endl;

	while (true)
	{
		cout << "------------------------------------------------------------------------------------" << endl << "?> ";
		cin.clear();
		//	cin.ignore(10000, '/n');

		while (cin >> select)
		{

			switch (select)
			{

			case '1':
				cout << "+ Bitte geben Sie die den Datensatz ein" << endl;
				if (cout << "Name ?> " && !(cin >> Name) || cout << "Alter ?> " && !(cin >> Alter) ||
					cout << "Einkommen ?> " && !(cin >> Einkommen) ||
					cout << "PLZ ?> " && !(cin >> PLZ))
				{
					std::cin.clear(); //clear bad input flag
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
					std::cout << "Ihr Datensatz wurde nicht hinzugefuegt\n";
					break;
				}

				file.addNode(Name, Alter, Einkommen, PLZ);
				std::cin.clear(); //clear bad input flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
				cout << "+ Ihr Datensatz wurde eingefuegt" << endl;
				break;

			case '2':
				cout << "+ Moechten Sie die Daten aus der Datei ""ExportZielanalyse"" importieren (j/n) ?> "; cin >> wahl;
				if (wahl == 'j')
				{
					bool c = 0;
					ifstream csvread("ExportZielanalyse.csv");
					if (!csvread.is_open())
						cerr << "Fehler beim Oeffnen der Datei!" << endl;
					else {

						for (Person person; read(csvread, person); )
							file.addNode(person.Name, stoi(person.Alter), stoi(person.Einkommen), stoi(person.PLZ));
						/*		{
									if () {

										c = 1;
									}
									else
									{
										cout << "+ Ihr Datensatz wurde NICHT eingefugt " << endl;
									}}
							} if (c) { cout << "+ Ihr Datensatz wurde eingefugt " << endl; }
			*/
						cout << "+ Daten wurden dem Baum hinzugefuegt." << endl;
					}
				}
				else
				{

					cout << "+ Daten wurden dem Baum nicht hinzugefuegt." << endl;
				}


				break;
			case '3':
				cout << "+ Bitte geben Sie den zu loeschenden Datensatz an" << endl << "PosID ?> "; cin >> postid;
				file.deleteNode(postid);
				break;

			case '4':
				cout << "+ Bitte geben Sie den zu suchenden Datensatz an" << endl << "Name ?> "; cin >> Name;
				cout << "+ Fundstellen:" << endl;
				file.searchNode(Name);
				break;
			case '5':
				cout << "ID  | Name      | Alter | Einkommen | PLZ    | Position \n"
					<< "----+-----------+-------+-----------+--------+----------\n";
				file.printAll();
				cout << "----+-----------+-------+-----------+--------+----------" << endl;
				break;
			case '6':
				cout << file.isBST() << endl;
				break;
			}

			break;
		}

	}

	//
	///////////////////////////////////////
	std::system("PAUSE");

	return 0;
}
