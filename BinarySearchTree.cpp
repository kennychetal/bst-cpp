#include "BinarySearchTree.h"
#include "stdafx.h"
#include <iostream>
using namespace std;
BinarySearchTree::BinarySearchTree(void)
{
	root = NULL;
}


bool BinarySearchTree::isEmpty(){
	
	return (root==NULL);
}


void BinarySearchTree::searchTreeInsert(elementtype* newitem){
	
	insertItem(root,newitem);
}

void BinarySearchTree::insertItem(TNode*& treeptr, elementtype* newitem){
	
	if (treeptr == NULL){
	//position of insertion found; insert after leaf
		//create a new node
		treeptr = new TNode(newitem, NULL, NULL);
		
	}

	//else search for tree position
	else if(newitem->getKey()<treeptr->item->getKey())
		insertItem(treeptr->leftchildpointer,newitem);
	else
		insertItem(treeptr->rightchildpointer,newitem);
}

void BinarySearchTree::searchTreeDelete(int searchkey){
	
	deleteItem(root,searchkey);
}

void BinarySearchTree::deleteItem(TNode*& treeptr, int searchkey){
	if (treeptr==NULL)
		cout<<"Tree is empty";
	else if (searchkey==treeptr->item->getKey())
		deleteNodeItem(treeptr);
	else if(searchkey < treeptr->item->getKey())
		deleteItem(treeptr->leftchildpointer,searchkey);
	else
		deleteItem(treeptr->rightchildpointer,searchkey);

}

void BinarySearchTree::deleteNodeItem(TNode*& nodeptr){
	//Algorithm note: There are four cases to consider:
	// 1. The root is a leaf.
	// 2. The root has no left child.
	// 3. The root has no right child.
	// 4. The root has two children
	//calls: processLeftmost.

	TNode* delptr;
	elementtype* replacementitem;
	if ((nodeptr->leftchildpointer==NULL)&&(nodeptr->rightchildpointer==NULL)){
		delete nodeptr;
		nodeptr = NULL;
	}

	else if (nodeptr->leftchildpointer == NULL)
	{
		delptr = nodeptr;
		nodeptr = nodeptr->rightchildpointer;
		delptr->rightchildpointer=NULL;
		delete delptr;
		//end if no left child
		//test for no right child
	}
	else if (nodeptr->rightchildpointer==NULL){
		delptr = nodeptr;
		nodeptr = nodeptr->leftchildpointer;
		delptr->leftchildpointer=NULL;
		delete delptr;
	}
	else{
		processLeftmost(nodeptr->rightchildpointer, replacementitem);
		nodeptr->item = replacementitem;
		
	}
}

void BinarySearchTree::processLeftmost(TNode* nodeptr, elementtype* treeitem){
	if (nodeptr->leftchildpointer==NULL){
		treeitem = nodeptr->item;
		TNode* delptr = nodeptr;
		nodeptr = nodeptr->rightchildpointer;
		delptr->rightchildpointer=NULL;
		delete delptr;
	}
	else
		processLeftmost(nodeptr->leftchildpointer,treeitem);

	
}
//error lnk2019 means something hasnt been defined yet usually
void BinarySearchTree::inorderTraverse(){
	inorder(root);
}

void BinarySearchTree::inorder(TNode* treeptr){
	if(treeptr!=NULL)
	 {
		 if (treeptr->leftchildpointer)
			 inorder(treeptr->leftchildpointer);
		 cout<<treeptr->item<<":"<<treeptr->item;

			if (treeptr->rightchildpointer)
				inorder(treeptr->rightchildpointer);


}

}

TNode* BinarySearchTree::rootptr(){
	return root;

}

BinarySearchTree::~BinarySearchTree(void)
{
}
