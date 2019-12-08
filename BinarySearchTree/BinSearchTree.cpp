#include "BinSearchTree.h"
#include <queue>
#include <stack>
#include <vector>

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

bool contains(TreeNode* node, int val)
{
	return (findNode(node, val) != nullptr);
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
		return findNode(node->leftNode, val);
	}
	else if (val > node->value)
	{
		return findNode(node->rightNode, val);
	}
	else return nullptr;
}

int getMin(TreeNode* node)
{
	try
	{
		if (node == nullptr)
		{
			throw std::exception("Error, tree is empty /");
		}
		while (node->leftNode != nullptr)
		{
			node = node->leftNode;
		}
		return node->value;
	}
	catch(std::exception& e)
	{
		std::cout << e.what();
		return -1;
	}
}

int getMax(TreeNode* node)
{
	try
	{
		if (node == nullptr)
		{
			throw std::exception("Error, tree is empty /");
		}
		while (node->rightNode != nullptr)
		{
			node = node->rightNode;
		}
		return node->value;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
		return -1;
	}
}

void getNodeDepth(TreeNode* node, int val, int& count)
{
	if (node == nullptr) return;
	if (val == node->value)
	{
		return;
	}
	else if (val < node->value)
	{
		return getNodeDepth(node->leftNode, val, ++count);
	}
	else if (val > node->value)
	{
		return getNodeDepth(node->rightNode, val, ++count);
	}
	else return;
}

int getTreeDepth(TreeNode* node)
{
	if (node != nullptr)
	{
		return 1 + std::max(getTreeDepth(node->leftNode), getTreeDepth(node->rightNode));
	}
	else
	{
		return -1;
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