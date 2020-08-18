/*************************************************
* ADS Praktikum 2.1
* main.cpp
* 
*************************************************/
#define CATCH_CONFIG_RUNNER

#include <iostream>
#include <string>
#include "Ring.h"
#include "catch.hpp"

using namespace std;


int main()
{
	int result = Catch::Session().run();
	// Ihr Code hier:

	char wahl = '0';
	string text, data, gesucht;
	Ring file;
	bool Flag = 0;

	cout << "1) Backup einfuegen" << endl
		<< "2) Backup suchen" << endl
		<< "3) Alle Backups ausgeben" << endl;


	while (wahl != '99')
	{


		cout << "?>";
		cin >> wahl;
		switch (wahl)
		{
		case '1':

			cout << "+Neuen Datensatz einfuegen" << endl;
			cout << "Beschreibung ?> "; cin >> text;
			cout << "Daten ?> "; cin >> data;
			file.addNode(text, data);
			cout << "Ihr Datensatz wurde hinzugefuegt\n";
			continue;
		case '2':

			cout << "+Nach welchen Daten soll gesucht werden? " << endl;
			cin >> gesucht;
			Flag = file.search(gesucht);
			if (!Flag) cout << "+ Datensatz konnte nicht gefunden werden.";
			continue;

		case '3':
			std::cout << file;
		}
		cin.clear();

	}

	//
	///////////////////////////////////////
	system("Pause");
	return 0;
}
