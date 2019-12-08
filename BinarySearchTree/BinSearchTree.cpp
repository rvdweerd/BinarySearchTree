#include "BinSearchTree.h"
#include <queue>
#include <stack>

void insert(TreeNode*& node, int val)
{
	if (node == nullptr)
	{
		node = new TreeNode;
		node->value = val;
		return;
	}

	if (val > node->value)
	{
		insert(node->rightNode, val);
	}
	if (val < node->value)
	{
		insert(node->leftNode, val);
	}
	return;
}

TreeNode* findNode(TreeNode* node, int val)
{
	if (node != nullptr) std::cout << "[" << node << ":" << node->value << "]"; else std::cout << "[" << node << "]";
	
	if (node == nullptr) return nullptr;
	if (val == node->value)
	{
		return node;
	}
	else if (val < node->value)
	{
		return findNode(node->leftNode,val);
	}
	else if (val > node->value)
	{
		return findNode(node->rightNode,val);
	}
	
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