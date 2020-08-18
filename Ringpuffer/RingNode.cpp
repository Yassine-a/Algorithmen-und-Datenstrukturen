/*************************************************
* ADS Praktikum 2.1
* RingNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "RingNode.h"


// Ihr Code hier:

RingNode::RingNode() {

}

RingNode::RingNode(int age, std::string desc, std::string syData) {
	this->OldAge = age;
	this->Description = desc;
	this->symbolicData = syData;
}

int  RingNode::getAge() { return this->OldAge; }


void RingNode::setAge(int age) { this->OldAge = age; }


std::string RingNode::getDescription() { return this->Description; }


void RingNode::setDescription(std::string des) { this->Description = des; }


std::string RingNode::getData() { return this->symbolicData;  }


void RingNode::setData(std::string data) { this->symbolicData = data;}


RingNode* RingNode::getNext() { return this->next; }


void RingNode::setNext(RingNode* ptr) { this->next = ptr; }


ostream& operator<<(ostream &stream, RingNode* ref)
{
	stream << "OldAge " << ref->getAge() <<
		", Desc: " << ref->getDescription() <<
		", Data : " << ref->getData() << endl;

	return stream;
}

// 
////////////////////////////////////