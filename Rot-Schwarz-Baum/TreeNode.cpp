/*************************************************
* ADS Praktikum 2.2
* TreeNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <string>


////////////////////////////////////
// Ihr Code hier:
using namespace std;

TreeNode::TreeNode(int NodePosID, int NodeID, std::string Name, int Alter, double Einkommen, int PLZ) {
	this->NodePosID = Alter /*+ PLZ + int(Einkommen)*/;
	this->NodeID = NodeID;
	this->Name = Name;
	this->Alter = Alter;
	this->Einkommen = Einkommen;
	this->PLZ = PLZ;
}

int TreeNode::getNodePosID() const {
	return NodePosID;
}

int TreeNode::getNodeID() const {
	return NodeID;
}

std::string TreeNode::getName() const {
	return Name;
}

void TreeNode::setName(std::string Name) {
	this->Name = Name;
}

int TreeNode::getAlter() const {
	return Alter;
}

void TreeNode::setAlter(int Alter) {
	this->Alter = Alter;
}

double TreeNode::getEinkommen() const {
	return Einkommen;
}

void TreeNode::setEinkommen(double Einkommen) {
	this->Einkommen = Einkommen;
}

int TreeNode::getPLZ() const {
	return PLZ;
}

void TreeNode::setPLZ(int PLZ) {
	this->PLZ = PLZ;
}

TreeNode *TreeNode::getLeft() const {
	return left;
}

TreeNode* TreeNode::getRight() const {
	return right;
}

void TreeNode::setLeft(TreeNode *left) {
	this->left = left;
}

void TreeNode::setRight(TreeNode *right) {
	this->right = right;
}

//void TreeNode::print() {
//	std::cout << "NodeID: " << NodeID << ", Name: " << Name << ", Alter: " << Alter << ", Einkommen: " << Einkommen
//		<< ", PLZ: " << PLZ << ", PosID: " << NodePosID << std::endl;
//}

bool TreeNode::getRed() const {
	return red;
}

void TreeNode::setRed(bool red) {
	this->red = red;
}

TreeNode *& TreeNode::refLeft() {
	return left;
}
TreeNode *& TreeNode::refRight() {
	return right;
}

//
////////////////////////////////////


