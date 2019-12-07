#include "BinSearchTree.h"
#include <queue>
#include <stack>

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

void printPre(TreeNode* node)
{
	if (node != nullptr)
	{
		std::cout << node->value << ", ";
		printPre(node->leftNode);
		printPre(node->rightNode);
	}
	return;
}

void printIn(TreeNode* node)
{
	if (node != nullptr)
	{
		printIn(node->leftNode);
		std::cout << node->value << ", ";
		printIn(node->rightNode);
	}
	return;
}

void printPost(TreeNode* node)
{
	if (node != nullptr)
	{
		printPost(node->leftNode);
		printPost(node->rightNode);
		std::cout << node->value << ", ";
	}
	return;
}

void printLevelTopDown(TreeNode* node)
{
	std::queue<TreeNode*> queue;
	if (node != nullptr) queue.emplace(node);
	while (!queue.empty())
	{
		TreeNode* current = queue.front();
		queue.pop();
		std::cout << current->value<<", ";
		if (current->leftNode != nullptr) queue.emplace(current->leftNode);
		if (current->rightNode != nullptr) queue.emplace(current->rightNode);
	}
}

void printLevelBottomUp(struct TreeNode* node)
{
	std::queue<TreeNode*> queue;
	std::stack<TreeNode*> stack;
	if (node != nullptr) queue.emplace(node);
	while (!queue.empty())
	{
		TreeNode* current = queue.front();
		stack.emplace(current);
		queue.pop();
		if (current->rightNode != nullptr) queue.emplace(current->rightNode);
		if (current->leftNode != nullptr) queue.emplace(current->leftNode);
	}
	while (!stack.empty())
	{
		std::cout << stack.top()->value << ", ";
		stack.pop();
	}
}