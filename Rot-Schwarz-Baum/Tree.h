/*************************************************
* ADS Praktikum 2.2
* Tree.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>
#include "TreeNode.h"
#include "catch.h"

using namespace std;

class Tree {

private:
	///////////////////////////////////////
	// Ihr Code hier:	
	TreeNode* anker = nullptr;
	int NodeIDCounter;

	bool rotateTreeRight(TreeNode *ptr1, TreeNode *ptr2);

	bool rotateTreeLeft(TreeNode *ptr1, TreeNode *ptr2);

	inline TreeNode *searchParent(TreeNode *ptr);

	inline void swapColour(TreeNode *ptr1, TreeNode *ptr2);

	void RedBlackInsert(TreeNode *&h, TreeNode *node);

	//
	////////////////////////////////////	

public:
	///////////////////////////////////////
	// Ihr Code hier:	
	void addNode(string Name, int Alter, double Einkommen, int PLZ);

	bool balanceTree(TreeNode* &h);

	bool searchNode(string Name);

	void printAll(void);

	void print(TreeNode* ptr);

	void printLevelOrder();

	void printnode(TreeNode* ptr);

	bool isBST() { return isBST(anker); }
	bool isBST(TreeNode* ptr);

	void search(string name, TreeNode * ptr, bool& value);
	//
	////////////////////////////////////
	// friend-Funktionen sind für die Tests erforderlich und müssen unangetastet bleiben! 
	friend TreeNode * get_anker(Tree& TN);
};
