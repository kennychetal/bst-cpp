#pragma once

typedef int elementtype;
class TNode
{
public:
	/* Constructor for tree with no children with corresponding data.
	* @pre That current node has no children.
	* @post That current node has been created with corresponding data.
	* @throw 
	*/
	TNode(void);
	/* Constructor for tree with arguments. Adds left tree to parent and right tree to parent with corresponding data.
	* @pre That current node is a parent node.
	* @post Parent node has left child and right child attached. 
	* @throw 
	*/
	TNode(elementtype* dataptr, TNode *lefttree, TNode *righttree);
	//info: pointer node for left tree (left child).
	TNode* leftchildpointer;
	//info: pointer node for left tree (left child).
	TNode* rightchildpointer;
	//info: Data for node.
	elementtype* item;
	~TNode(void);
};

