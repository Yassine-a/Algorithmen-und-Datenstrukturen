/*************************************************
* ADS Praktikum 2.2
* TreeNode.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "TreeNode.h"
#include <iostream>
#include <string>


////////////////////////////////////
// Ihr Code hier:

TreeNode::TreeNode(int NodePosID, int NodeID, string Name, int Alter, double Einkommen, int PLZ) {
	this->NodePosID = NodePosID;
	this->NodeID = NodeID;
	this->Name = Name;
	this->Alter = Alter;
	this->Einkommen = Einkommen;
	this->PLZ = PLZ;
}


int TreeNode::getNodePosID(void) {
	return NodePosID;
}


int TreeNode::getNodeID(void) {
	return NodeID;
}


string TreeNode::getName(void) {
	return Name;
}


void TreeNode::setName(string name){
	this->Name = name;
}


int TreeNode::getAlter(void) {
	return Alter;
}


void TreeNode::setAlter(int alter) {
	this->Alter = alter;
}


double TreeNode::getEinkommen(void) {
	return Einkommen;
}


void TreeNode::setEinkommen(double einkommen) {
	this->Einkommen = einkommen;
}


int TreeNode::getPLZ(void) {
	return PLZ;
}


void TreeNode::setPLZ(int plz) {
	this->PLZ = plz;
}


void TreeNode::print(void) {

}


TreeNode* TreeNode::getLeft(void){
	return this->left;
}

TreeNode* TreeNode::getRight(void) {
	return this->right;
}


void TreeNode::setLeft(TreeNode* ptr) {
	this->left = ptr;
}


void TreeNode::setRight(TreeNode* ptr) {
	this->right = ptr;
}

//
////////////////////////////////////
