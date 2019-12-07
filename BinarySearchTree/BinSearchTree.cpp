#include "BinSearchTree.h"
enum class PrintOption;
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

void print(TreeNode* node, PrintOption opt)
{
	if (node != nullptr)
	{
		if (opt == PrintOption::PreOrder) std::cout << node->value << std::endl;
		print(node->leftNode, opt);
		if (opt == PrintOption::InOrder) std::cout << node->value << std::endl;
		print(node->rightNode, opt);
		if (opt == PrintOption::PostOrder) std::cout << node->value << std::endl;
	}
}
