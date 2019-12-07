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

void insert(struct TreeNode*& Node, int val);
void printPre(struct TreeNode* node);
void printIn(struct TreeNode* node);
void printPost(struct TreeNode* node);
void printLevelTopDown(struct TreeNode* node);
void printLevelBottomUp(struct TreeNode* node);



