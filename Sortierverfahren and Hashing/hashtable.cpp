#include "hashtable.h"
#include <iostream>

using namespace std;


class Node {
public:
	int e;
	Node *next;
	
};

HashTable::HashTable(int size) {

	vector<int> ht(40,-1);
	hashTable = new vector<int>(size,-1);
	this->size = size;
	elements = 0;
	collisionCount = 0;

}

HashTable::~HashTable()
{
	hashTable->clear();
	delete hashTable;
}

int HashTable::hashValue(int item) {
	
	int index = item % size;
	int i = 0;

	if (hashTable->at(index) != -1) {
		while (hashTable->at(index) != -1) {
			collisionCount++;
			i++;
			index = (item + i * i) % size;
		}

	}
	Node* l;
	l = new Node[90];
	l->e = -1;
	l[15].e = -1;
	return index;

	
	
}

int HashTable::insert(int item) {
	
	int index = this->hashValue(item);
	hashTable->at(index) = item;
	elements++;

	return 0; //dummy return
}


int HashTable::at(int i) {
	return hashTable->at(i);
}

int HashTable::getCollisionCount() {
	return this->collisionCount;
}

int HashTable::getSize() {
	return this->size;
}

int HashTable::getElements() {
	return this->elements;
}
