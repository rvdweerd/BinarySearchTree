#include "BinSearchTree.h"

void insert(TreeNode*& Node, int val)
{
	if (Node == nullptr)
	{
		Node = new TreeNode;
		Node->value = val;
		return;
	}

	if (val > Node->value)
	{
		insert(Node->rightNode, val);
	}
	if (val < Node->value)
	{
		insert(Node->leftNode, val);
	}
	return;
}
