/*************************************************
* ADS Praktikum 2.2
* Tree.cpp
* Erweiterung um Hilfsfunktionen gestattet.
*************************************************/
#include "Tree.h"
#include "TreeNode.h"
#include <iostream>
#include <iomanip>

using namespace std;

////////////////////////////////////
// Ihr Code hier:
void Tree::addNode(string Name, int Alter, double Einkommen, int PLZ) {

	int NPosID = (int)Einkommen + PLZ + Alter;
	TreeNode* neu = new TreeNode(NPosID, NodeIDCounter++,Name, Alter,Einkommen,PLZ);

	if (anker == nullptr) {
		anker = neu;
		return;
	}

	TreeNode* current = anker;
	TreeNode* parent = nullptr;

	while (current != nullptr) {
		parent = current;

		if (NPosID < current->getNodePosID()) current = current->getRight();
		else current = current->getLeft();
	}

	if (NPosID < parent->getNodePosID()) parent->setLeft(neu);
	else parent->setRight(neu);
	
}


void Tree::deleteNode(int NodePosID) {

	deleteNod(anker, NodePosID);
}


//----- Hilfsfunktion fuer Delete ---------//

TreeNode* Tree::minValueNod(TreeNode* tmp) {
	TreeNode* ptr = tmp;
	while (ptr->getLeft()) ptr = ptr->getLeft();
	return ptr;
	
}

TreeNode* Tree::searchforparentnode(TreeNode* pTB, int PosID)
{
	// Special case if the anker is the node to be deleted
	if (anker->getNodePosID() == PosID) return nullptr;

	// Dead case
	if (pTB->getLeft() == nullptr && pTB->getRight() == nullptr)
		return nullptr;

	// check left TB
	if (pTB->getLeft() && pTB->getLeft()->getNodePosID() == PosID)
		return pTB;

	// check right TB
	if (pTB->getRight() && pTB->getRight()->getNodePosID() == PosID)
		return pTB;


	if (pTB->getLeft() && pTB->getNodePosID() > PosID)
		return searchforparentnode(pTB->getLeft(), PosID);


	if (pTB->getRight() && pTB->getNodePosID() < PosID)
		return searchforparentnode(pTB->getRight(), PosID);

}

TreeNode* Tree::deleteNod(TreeNode* ptr, int PosID)
{
	if (ptr == nullptr) return ptr;

	if (PosID < ptr->getNodePosID()) {
		ptr->setLeft(deleteNod(ptr->getLeft(), PosID));
	}
	else if (PosID > ptr->getNodePosID()) {
		ptr->setRight(deleteNod(ptr->getRight(), PosID));
	}
	else {
		// node w/out left and right 
		if (ptr->getLeft() == nullptr && ptr->getRight() == nullptr) {
			if (ptr == anker) anker = nullptr;
			delete ptr;
			ptr = nullptr;
			return nullptr;
		}
		else if (ptr->getLeft() == nullptr) {
			// node with just right node >> no left node <<
			TreeNode* temp = ptr->getRight();
			if (ptr == anker) anker = temp;
			delete ptr;
			return temp;
		}
		else if (ptr->getRight() == nullptr) {
			// node with just left node >> no right node <<
			TreeNode* temp = ptr->getLeft();
			if (anker == ptr) anker = temp;
			delete ptr;
			return temp;
		}
		else {
			// nodes with two nodes
			// search for min number in right TB
			TreeNode* minRTB = minValueNod(ptr->getRight()); 
			TreeNode* minRTBparent = searchforparentnode(anker, minRTB->getNodePosID()); //minRTB Parent to reconnect it to nullptr or minRTB->right()
			
			TreeNode* parentptr = searchforparentnode(anker, ptr->getNodePosID()); // parent of the current node to reconnt it to minRTB after deleting ptr
			
			// Case 1: Check if the ptr and minRTB are neighbours or not
			if(ptr->getRight() == minRTB) minRTB->setLeft(ptr->getLeft()); // in case the current node and minRTB neighbours || Zeiger umbiegen EaZy || we can only compare it the right side
			else { // otherwise they are not connected to each other
				
				if(minRTB->getRight()!=nullptr) // minRTB can only have right side, so we check if it is connected to it
					minRTBparent->setLeft(minRTB->getRight()); // In case minRTB has a right node then connect the parent of minRTB to minRTB to the right side of mintRTB

				else 
					minRTBparent->setLeft(nullptr); // If minRTB has no childreenminRTB

					// Secure the nodes of ptr and connect them to 
					minRTB->setLeft(ptr->getLeft()); // connect the left child of current node to minRTB
					minRTB->setRight(ptr->getRight()); // connect the right child of current node to minRTB
			}

			// the node to be deleted
			ptr->setLeft(nullptr); // set the current node as a leaf node, to be eraced easily
			ptr->setRight(nullptr);
			deleteNod(anker, ptr->getNodePosID());

			if (parentptr==nullptr) anker = minRTB; // In case to be removed is the anker just replace it with minRTB | mod of anker
			else { // Otherwise deppending on the value of the PosID set the parent of the poninter to be deleted to the minRTB
				if (parentptr->getNodePosID() < minRTB->getNodePosID()) parentptr->setRight(minRTB);
				else parentptr->setLeft(minRTB);
			}
			ptr = minRTB;
			return ptr;
		}
	}

}



bool Tree::searchNode(string Name) {
	bool flag = false;
	search(Name, anker,flag);
	return flag;
}

void Tree::search(string name, TreeNode * ptr, bool& flag) {

	TreeNode* tmp = ptr;
	if (name == ptr->getName()) {
		cout << "NodeID: " << tmp->getNodeID() << ", Name : " << tmp->getName() << ", Alter : " << tmp->getAlter() <<
			", Einkommen : " << tmp->getEinkommen() << ", PLZ : " << tmp->getPLZ() << ", PosID : " << tmp->getNodePosID() << endl;
		flag = true;
	}

	if (tmp->getLeft())   search(name, tmp->getLeft(),flag);
	if (tmp->getRight())  search(name, tmp->getRight(),flag);
}


void Tree::printAll(void) {
	print(anker);
}

void Tree::print(TreeNode* ptr) {
	if (ptr != nullptr) {

		cout << std::setw(4) << ptr->getNodeID() << "|" << std::setw(11) << ptr->getName() << "|" << std::setw(7) <<
			ptr->getAlter() << "|" << std::setw(10) << ptr->getEinkommen() << " | " << setw(6) <<
			ptr->getPLZ() << " |   " << setw(7) << ptr->getNodePosID() << endl;

		if (ptr->getLeft() != nullptr) { print(ptr->getLeft()); }
		if (ptr->getRight() != nullptr) { print(ptr->getRight()); }

	}
}

bool Tree::isBST(TreeNode* ptr) {
	if (ptr == nullptr) return true;
	return (ptr->getAlter() > ptr->getLeft()->getAlter());
	return (ptr->getAlter() < ptr->getRight()->getAlter());
}


//
////////////////////////////////////