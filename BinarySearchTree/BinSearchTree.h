#pragma once
#include <iostream>

struct TreeNode
{
	int value;
	TreeNode* leftNode = nullptr;
	TreeNode* rightNode = nullptr;
};

enum class PrintOption
{
	PreOrder, // preorder traverse print
	InOrder,
	PostOrder
};

void insert(TreeNode*& Node, int val);
void print(TreeNode* node, PrintOption opt = PrintOption::PreOrder);



