/*************************************************
* ADS Praktikum 2.2
* TreeNode.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once
#include <string>

using namespace std;

class TreeNode{
	
	private:
		///////////////////////////////////////
		// Ihr Code hier:	
		int NodePosID;
		int NodeID;
		string Name;
		int Alter;
		double Einkommen;
		int PLZ;
		TreeNode* left = nullptr;
		TreeNode* right = nullptr;

		//
		////////////////////////////////////
	
	public:
		///////////////////////////////////////
		// Ihr Code hier:
		TreeNode(int NodePosID, int NodeID, string Name, int Alter, double Einkommen, int PLZ);


		int getNodePosID(void);
		int getNodeID(void);
		string getName(void);
		void setName(string name);
		int getAlter(void);
		void setAlter(int alter);
		double getEinkommen(void);
		void setEinkommen(double einkommen);
		int getPLZ(void);
		void setPLZ(int plz);

		void print(void);

		TreeNode* getLeft(void);
		TreeNode* getRight(void);
		void setLeft(TreeNode* ptr);
		void setRight(TreeNode* ptr);

		//
		////////////////////////////////////
};
