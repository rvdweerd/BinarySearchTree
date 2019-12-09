#pragma once
#include <iostream>

static constexpr int SENTINEL = -999999;

struct TreeNode
{
	int value = SENTINEL;
	TreeNode* leftNode = nullptr;
	TreeNode* rightNode = nullptr;
};

void insert(TreeNode*& node, int val);
void remove(TreeNode*& node, int val);
bool contains(TreeNode* node, int val);
TreeNode* findNode(TreeNode* node, int val);
TreeNode* findParent(TreeNode* node, int val);
int getMin(TreeNode* node);
int getMax(TreeNode* node);
void getNodeDepth(TreeNode* node, int val, int& count);
int getTreeHeight(TreeNode* node);
int getNumberOfNodes(TreeNode* node);

int getNumberOfElementsAtDepth(TreeNode* node, int depth);
void printPre(TreeNode* node);
void printIn(TreeNode* node);
void printPost(TreeNode* node);
void printLevelTopDown(TreeNode* node);
void printLevelBottomUp(TreeNode* node);
void printTreeChart(TreeNode* node);



