#pragma once
#include <iostream>

struct TreeNode
{
	int value;
	TreeNode* leftNode = nullptr;
	TreeNode* rightNode = nullptr;
};

void insert(TreeNode*& Node, int val);


