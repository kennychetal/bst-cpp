#pragma once
#include "TNode.h"

typedef int elementtype;
//ampersand idicates that you are altering memory address location value.
class BinarySearchTree
{
public:

	BinarySearchTree(void);
	/* Determines whether a binary search tree is empty.
	* @return True if the tree is empty; otherwise returns false.
	*/
	bool isEmpty();
	
	/* Inserts an item into binary search tree.
	* @pre The item to be inserted into the tree is newitem.
	* @post newitem is in its proper order in the tree.
	* @throw Tree exception if memory allocation fails.
	*/
	void searchTreeInsert(elementtype* newitem);
	/* Deletes an item with a given search key from a binary search tree.
	* @pre searchkey is the searchkey of the item to be deleted.
	* @post If the item whose search key equals searchkey that exists in the tree, the item is deleted. Otherwise, the tree is unchanged.
	* @throw Tree exception if searchKey is not found in the tree.
	*/
	void searchTreeDelete(int searchkey);
	/* Retrieves an item with a given search key from a binary search tree.
	* @pre searchkey is the searchkey of the item to be retrieved.
	* @post If the retrieval was successful, treeitem contains the retrieved item.
	* @throw Tree exception if no such item exists.
	*/
	void searchTreeRetrieve(int searchkey, elementtype* treeitem);

	/* Traverses a binary search tree in sorted order, calling
	* @pre searchkey is the searchkey of the item to be retrieved.
	* @post If the retrieval was successful, treeitem contains the retrieved item.
	* @throw Tree exception if no such item exists.
	*/
	void inorderTraverse();

protected:
	/* Recursively inserts an item into a binary search tree.
	* @pre treeptr points to a binary search tree, newitem is the item to be inserted.
	* @post If the item whose search key equals searchkey that exists in the tree, the item is deleted. Otherwise, the tree is unchanged.
	* @throw Tree exception if searchKey is not found in the tree.
	*/
	void insertItem(TNode*& treeptr, elementtype* newitem);
	/* Recursively deletes an item from a binary search tree.
	* @pre treeptr points to a binary search tree, searchkey is the search key of the item to be deleted.
	* @post If the item whose search key equals searchkey that exists in the tree, the item is deleted. Otherwise, the tree is unchanged.
	* @throw Tree exception if no such item exists.
	*/
	void deleteItem(TNode*& treeptr, int searchkey);
	/* Deletes the item in the root (parent) of a given tree.
	* @pre nodeptr points to a node in a binary search tree; nodePtr!=null.
	* @post The item in the root of the given tree is deleted.
	* @throw NONE.
	*/
	void deleteNodeItem(TNode*& nodeptr);
	/* Deletes the item in the root (parent) of a given tree.
	* @pre nodeptr points to a node in a binary search tree; nodePtr!=null.
	* @post treeitem contains the item in the leftmost descendant of the node to which nodeptr points.
	* the left most descendant of nodePtr is deleted.
	* @throw NONE.
	*/
	void processLeftmost(TNode* nodeptr,elementtype* item);
	/* Recursively retrieves an item from a binary search tree.
	* @pre treeptr points to a binary search tree, searchkey is the search key of the item to be retrieved.
	* @post If the retrieval was successful, treeitem contains the retrieved item.
	* @throw NONE.
	*/
	void retrieveItem(TNode* treeptr, int searchkey, elementtype* item);
	void inorder(TNode* treeptr);
	TNode* rootptr();
	void setRootPtr();
	void getChildPtrs(TNode* nodeptr, TNode* leftchildptr, TNode* rightchildptr);
	void setChildPtrs(TNode* nodeptr, TNode* leftchildptr, TNode* rightchildptr);

private:
	TNode *root;
	~BinarySearchTree(void);
};

