#pragma once
#include <iostream>

struct TreeNode
{
	int value;
	TreeNode* leftNode = nullptr;
	TreeNode* rightNode = nullptr;
};

void insert(struct TreeNode*& node, int val);
TreeNode* findNode(TreeNode* node, int val);
void printPre(struct TreeNode* node);
void printIn(struct TreeNode* node);
void printPost(struct TreeNode* node);
void printLevelTopDown(struct TreeNode* node);
void printLevelBottomUp(struct TreeNode* node);



