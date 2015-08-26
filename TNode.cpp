#include "TNode.h"
#include "stdafx.h"
typedef int elementtype;
TNode::TNode(void)
{
    item = new elementtype();
    leftchildpointer = NULL;
    rightchildpointer= NULL;

}


TNode::TNode(elementtype* dataptr, TNode *lefttree, TNode *righttree)
{
	item = new elementtype();
	leftchildpointer = lefttree;
    rightchildpointer = righttree;
    item = dataptr;    

}


TNode::~TNode(void)
{
}
