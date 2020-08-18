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

class Tree{
	
	private: 
		///////////////////////////////////////
		// Ihr Code hier:	
		TreeNode* anker = nullptr;
		int NodeIDCounter;

		//
		////////////////////////////////////	
	
	public:
		///////////////////////////////////////
		// Ihr Code hier:	
		void addNode(string Name, int Alter, double Einkommen, int PLZ);


		bool isBST() { return isBST(anker); };
		bool isBST(TreeNode* ptr);
		void deleteNode(int NodePosID);
		bool searchNode(string Name);
		void printAll(void);
		void print(TreeNode* ptr);

		TreeNode* searchforparentnode(TreeNode* pRoot, int value);
		TreeNode* deleteNod(TreeNode* root, int key);
		TreeNode* minValueNod(TreeNode* tmp);
		void search(string name, TreeNode * ptr, bool& value);
		//
		////////////////////////////////////
		// friend-Funktionen sind für die Tests erforderlich und müssen unangetastet bleiben! 
		friend TreeNode * get_anker(Tree& TN);
};
