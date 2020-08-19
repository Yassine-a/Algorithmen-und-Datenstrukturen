/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>


////////////////////////////////////
// Ihr Code hier:

void Tree::addNode(std::string Name, int Alter, double Einkommen, int PLZ) {
	TreeNode *newNode = new TreeNode{ 0, NodeIDCounter++, Name, Alter, Einkommen, PLZ };
	RedBlackInsert(anker, newNode);
}

void Tree::RedBlackInsert(TreeNode *&x, TreeNode *node) {
	if (anker == nullptr) node->setRed(false);
	if (x == nullptr) // we've reached the bottom, add the node
	{
		x = node;
		return;
	}
	// Top Down Verfahren : when both the right and the left nodes are red then change color
	if ((x->getLeft() && x->getRight()) && x->getLeft()->getRed() && x->getRight()->getRed()) {
		x->getLeft()->setRed(false);
		x->getRight()->setRed(false);
		if (x != anker) x->setRed(true);
		else
			x->setRed(false); //Anker node.red = schwarz
	}

	// Travasierung Rechts oder Links
	if (node->getNodePosID() < x->getNodePosID()) RedBlackInsert(x->refLeft(), node);
	else RedBlackInsert(x->refRight(), node);

	// Bottom Up meaning that we check if there is any rotation neccesary
	balanceTree(x);

}

bool Tree::balanceTree(TreeNode *&h) {
	// Left node - Right Subtree
	if (h->getLeft() && h->getLeft()->getRed()) {

		if ((h->getLeft()->getRight() && h->getLeft()->getRight()->getRed())) // Wenn wir den Fall haben dass left node red ist und left->right node also red ist
			rotateTreeLeft(h->getLeft(), h->getLeft()->getRight());           // left rotation of parent and child
		if (h->getLeft()->getLeft() && h->getLeft()->getLeft()->getRed()) {   // incase left is red "and" also left->left ist red 
			rotateTreeRight(h, h->getLeft());                                 // right rotation of grandparent and parent
			return true;                                                      // the balance occurs just when the parent and the grandparent are reconstructed
		}
	}
	// Right node - left subtree
	else if (h->getRight() && h->getRight()->getRed()) {                      // Chekc if right node is red
		if (h->getRight()->getLeft() && h->getRight()->getLeft()->getRed())   // Check if it has a right->left node and if this right->left node is red
			rotateTreeRight(h->getRight(), h->getRight()->getLeft());         // right rotation of parent and child
		if (h->getRight()->getRight() && h->getRight()->getRight()->getRed()) { // check if the node h has left->left and if is red
			rotateTreeLeft(h, h->getRight());                                  // left roation of grandparent and parent
			return true;
		}
	}
	return false;
}


bool Tree::rotateTreeRight(TreeNode *ptr1, TreeNode *ptr2) {
	TreeNode *parent = searchParent(ptr1);
	if (parent)
		if (ptr1 == parent->getLeft()) parent->setLeft(ptr2);
		else parent->setRight(ptr2);
	else
		anker = ptr2; // Parent of ptr1 is a nullptr


	ptr1->setLeft(ptr2->getRight());
	ptr2->setRight(ptr1);

	
	bool tmp = ptr1->getRed();
	ptr1->setRed(ptr2->getRed());
	ptr2->setRed(tmp);
	return true;
}

bool Tree::rotateTreeLeft(TreeNode *ptr1, TreeNode *ptr2) {
	TreeNode *parent = searchParent(ptr1);
	if (parent)
		if (ptr1 == parent->getRight()) parent->setRight(ptr2);
		else  parent->setLeft(ptr2);
	else
		anker = ptr2;


	ptr1->setRight(ptr2->getLeft());
	ptr2->setLeft(ptr1);

	//Umfärben
	bool tmp = ptr1->getRed();
	ptr1->setRed(ptr2->getRed());
	ptr2->setRed(tmp);
	return true;
}

TreeNode *Tree::searchParent(TreeNode *ptr) {
	TreeNode *parent = nullptr;
	TreeNode *curr = anker;
	while (curr != ptr) {
		parent = curr;
		if (ptr->getNodePosID() > curr->getNodePosID()) curr = curr->getRight();
		else  curr = curr->getLeft();
	}
	return parent;
}


bool Tree::searchNode(string Name) {
	bool flag = false;
	search(Name, anker, flag);
	return flag;
}

void Tree::search(string name, TreeNode * ptr, bool& flag) {

	TreeNode* tmp = ptr;
	if (name == ptr->getName()) {
		cout << "NodeID: " << tmp->getNodeID() << ", Name : " << tmp->getName() << ", Alter : " << tmp->getAlter() <<
			", Einkommen : " << tmp->getEinkommen() << ", PLZ : " << tmp->getPLZ() << ", PosID : " << tmp->getNodePosID() << endl;
		flag = true;
	}

	if (tmp->getLeft())   search(name, tmp->getLeft(), flag);
	if (tmp->getRight())  search(name, tmp->getRight(), flag);
}


void Tree::printAll(void) {
	print(anker);
}

void Tree::print(TreeNode* ptr) {
	if (ptr != nullptr) {

		std::cout << std::setw(3) << ptr->getNodeID() << '|' << std::setw(12) << ptr->getName() << '|'
			<< std::setw(7) << ptr->getAlter() << '|' << std::setw(11) << ptr->getEinkommen() << '|'
			<< std::setw(7) << ptr->getPLZ() << '|' << std::setw(7) << ptr->getNodePosID() << '|'
			<< std::setw(2) << ptr->getRed() << std::endl;


		if (ptr->getLeft() != nullptr) { print(ptr->getLeft()); }
		if (ptr->getRight() != nullptr) { print(ptr->getRight()); }

	}
}

void Tree::printnode(TreeNode* node) {
	std::cout << std::setw(3) << node->getNodeID() << '|' << std::setw(12) << node->getName() << '|'
		<< std::setw(7) << node->getAlter() << '|' << std::setw(11) << node->getEinkommen() << '|'
		<< std::setw(7) << node->getPLZ() << '|' << std::setw(7) << node->getNodePosID() << '|'
		<< std::setw(2) << node->getRed() << std::endl;
}

void Tree::printLevelOrder() {
	if (!anker) return;
	else {

		TreeNode *ptr = anker;
		std::queue<TreeNode *> nodeStack;
		nodeStack.push(anker);
		while (!nodeStack.empty()) {
			ptr = nodeStack.front();
			nodeStack.pop();


			if (ptr->getLeft() && (ptr->getLeft()->getRed())) {
				printnode(ptr->getLeft());
				if(ptr->getLeft()->getLeft())
					nodeStack.push(ptr->getLeft()->getLeft());
				if (ptr->getLeft()->getRight())
					nodeStack.push(ptr->getLeft()->getRight());
			}
			else if (ptr->getLeft() && !(ptr->getLeft()->getRed()))
				nodeStack.push(ptr->getLeft());

			printnode(ptr);


			if (ptr->getRight() && (ptr->getRight()->getRed())) {
				printnode(ptr->getRight());
				if (ptr->getRight()->getLeft())
					nodeStack.push(ptr->getRight()->getLeft());
				if (ptr->getRight()->getRight())
					nodeStack.push(ptr->getRight()->getRight());
			}
			else if (ptr->getRight() && !(ptr->getRight()->getRed()))
				nodeStack.push(ptr->getRight());
		}
	}
}

bool Tree::isBST(TreeNode* ptr) {
	if (ptr == nullptr) return true;
	return (ptr->getAlter() > ptr->getLeft()->getAlter());
	return (ptr->getAlter() < ptr->getRight()->getAlter());
}

//
////////////////////////////////////

