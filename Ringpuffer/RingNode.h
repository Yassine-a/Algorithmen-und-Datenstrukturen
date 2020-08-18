/*************************************************
* ADS Praktikum 2.1
* RingNode.h
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#pragma once
#include <string>
#include <iostream>
using namespace std;

class RingNode{
	
private:
	// Ihr Code hier:
	int OldAge;
	std::string Description;
	std::string symbolicData;
	RingNode* next;

	//	
public:
	// Ihr Code hier:
	RingNode();
	RingNode(int age, std::string str1, std::string str2);
	int getAge();
	void setAge(int age);
	std::string getDescription();
	void setDescription(std::string des);
	std::string getData();
	void setData(std::string data);
	RingNode* getNext();
	void setNext(RingNode* ptr);
	friend ostream& operator << (ostream& stream, RingNode* ptr);

	//
};
