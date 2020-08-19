/*************************************************
* ADS Praktikum 2.2
* TreeNode.h
* Erweiterung um Hilfsattribute und -funktionen gestattet, wenn erforderlich.
*************************************************/
#pragma once

#include <string>

class TreeNode {

private:
	///////////////////////////////////////
	// Ihr Code hier:
	int NodePosID;
	int NodeID;
	bool red = true;
	std::string Name;
	int Alter;
	double Einkommen;
	int PLZ;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
	//
	////////////////////////////////////

public:
	///////////////////////////////////////
	// Ihr Code hier:
	TreeNode(int NodePosID, int NodeID, std::string Name, int Alter, double Einkommen, int PLZ);
	int getNodePosID() const;
	int getNodeID() const;
	std::string getName() const;
	void setName(std::string _Name);
	int getAlter() const;
	void setAlter(int _Alter);
	double getEinkommen() const;
	void setEinkommen(double _Einkommen);
	int getPLZ() const;
	void setPLZ(int _PLZ);
	TreeNode *&  refLeft();
	TreeNode *& refRight();
	TreeNode* getLeft() const;
	TreeNode* getRight() const;
	void setLeft(TreeNode *_left);
	void setRight(TreeNode *_right);
	void print();
	bool getRed() const;
	void setRed(bool _red);
	//
	////////////////////////////////////
};
