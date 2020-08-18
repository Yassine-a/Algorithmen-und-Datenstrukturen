/*************************************************
* ADS Praktikum 2.1
* Ring.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .cpp
#include "Ring.h"
#include <iostream>

// Ihr Code hier:

void Ring::gettingOlder()
{
	RingNode* tmp = anker;
	int _cp = AnzahlNodes;
	while (_cp > 0)
	{

		tmp->setAge((tmp->getAge()) + 1);
		tmp = tmp->getNext();
		_cp--;
	}
}

void Ring::addNode(string Beschreibung, string Data) {
	RingNode *neu = new RingNode(0, Beschreibung, Data);

	if (anker == nullptr) {
		anker = neu;
		AnzahlNodes++;
		neu->setNext(neu);
	}
	else {
		gettingOlder();

		if (AnzahlNodes == 6) {
			RingNode* tmp = anker->getNext();
			anker->setNext(neu);
			neu->setNext(tmp->getNext());
			anker = neu;
			delete tmp;
			tmp = 0;
		}
		else {
			AnzahlNodes++;
			RingNode* tmp = anker->getNext();
			anker->setNext(neu);
			neu->setNext(tmp);
			anker = neu;
		}
	}


}


bool Ring::search(string Data) {
	RingNode* tmp = anker;
	bool flag = false;
	for (int i = 0; i < AnzahlNodes; i++) {
		if (tmp->getData() == Data) {
			flag = true; break;
		}
		tmp = tmp->getNext();
	}
	return flag;
}


void Ring::print() {

	cout << anker;
}


ostream & operator<<(ostream & stream, Ring ref)
{

	RingNode* tmp = ref.anker;
	int c = ref.AnzahlNodes;
	for (int i = 0; i < ref.AnzahlNodes; i++)
	{
		stream << tmp;
		cout << "-----------------------------------" << endl;
		for (int j = c - 1; j > 0; j--)
		{
			tmp = tmp->getNext();
		}

	}
	return stream;
}


//
////////////////////////////////////
