/*************************************************
* ADS Praktikum 2.1
* Ring.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
// Ring .h
#pragma once
#include<string>
#include "catch.hpp"
#include"RingNode.h"

class Ring{
	
	private:
		// Ihr Code hier:	
		int AnzahlNodes=0;
		RingNode* anker = nullptr;
		//
		////////////////////////////////////
	public:
		// Ihr Code hier:
		Ring(){}
		void gettingOlder();
		void addNode(std::string str1, std::string str2);
		bool search(std::string str);
		void print();
		friend ostream& operator << (ostream &stream, Ring ref);
		//
		////////////////////////////////////
		// friend Funktionen müssen unangetastet bleiben! 
		friend RingNode * get_anker(Ring& r);
		friend int get_AnzahlNodes(Ring& r);
};
