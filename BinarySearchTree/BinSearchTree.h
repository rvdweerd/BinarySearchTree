#pragma once
#include <iostream>

struct TreeNode
{
	int value=0;
	TreeNode* leftNode = nullptr;
	TreeNode* rightNode = nullptr;
};

void insert(struct TreeNode*& node, int val);
bool contains(TreeNode* node, int val);
TreeNode* findNode(TreeNode* node, int val);
int getMin(TreeNode* node);
int getMax(TreeNode* node);
void getNodeDepth(TreeNode* node, int val, int& count);
int getTreeDepth(TreeNode* node);
void printPre(struct TreeNode* node);
void printIn(struct TreeNode* node);
void printPost(struct TreeNode* node);
void printLevelTopDown(struct TreeNode* node);
void printLevelBottomUp(struct TreeNode* node);



