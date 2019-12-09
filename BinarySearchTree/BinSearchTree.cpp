#include "BinSearchTree.h"
#include <queue>
#include <stack>
#include <vector>
#include <numeric>
#include <cmath>

template <class T>
int numDigits(T number)
{
	int digits = 0;
	if (number < 0) digits = 1; // remove this line if '-' counts as a digit
	while (number) {
		number /= 10;
		digits++;
	}
	return digits;
}

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

int getTreeHeight(TreeNode* node)
{
	if (node != nullptr)
	{
		return 1 + std::max(getTreeHeight(node->leftNode), getTreeHeight(node->rightNode));
	}
	else
	{
		return 0;
	}
}

int getNumberOfNodes(TreeNode* node)
{
	if (node == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + getNumberOfNodes(node->leftNode) + getNumberOfNodes(node->rightNode);
	}
}

int getNumberOfElementsAtDepth(TreeNode* node, int depth)
{
	std::queue<TreeNode*> queue;
	std::vector<int> nodeDepthValues = {};
	if (node != nullptr) queue.emplace(node);
	while (!queue.empty())
	{
		TreeNode* current = queue.front();
		queue.pop();
		int count = 0;
		getNodeDepth(node, current->value, count);
		nodeDepthValues.push_back(count);
		if (current->leftNode != nullptr) queue.emplace(current->leftNode);
		if (current->rightNode != nullptr) queue.emplace(current->rightNode);
	}
	return std::accumulate(nodeDepthValues.begin(), nodeDepthValues.end(), 0, [&depth](int cum, int val)
		{
			if (val == depth) cum++;
			return cum++;
		});
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

void printLevelBottomUp(TreeNode* node)
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

void printTreeChart(TreeNode* node)
{
	// Print parameters
	// ----------------
	// Set print parameters (maximum printable depth, spacing between nodes depending on #digits)
	//===========================================================================================
	bool printable = true;
	const int height = getTreeHeight(node);
	int maxValueInTree = getMax(node);
	int minValueInTree = getMin(node);
	int maxDigits = std::max(numDigits(minValueInTree),numDigits(maxValueInTree));
	bool minDigits = 1; // [1] = puts a '.' when node is empty, [0] = no '.' printed for empty nodes 
	int whitespacePrintFactor = 0; int maxPrintableHeight = std::min(0, height);
	if      (maxDigits <=2 ) { whitespacePrintFactor = 2; maxPrintableHeight = std::min(7, height); }
	else if (maxDigits == 3) { whitespacePrintFactor = 2; maxPrintableHeight = std::min(7, height); }
	else if (maxDigits == 4) { whitespacePrintFactor = 3; maxPrintableHeight = std::min(6, height); }
	else if (maxDigits == 5) { whitespacePrintFactor = 3; maxPrintableHeight = std::min(6, height); }
	else if (maxDigits == 6) { whitespacePrintFactor = 4; maxPrintableHeight = std::min(6, height); }
	else { printable = false; }
	
	if (!printable)
	{
		std::cout << "Tree is not printable in chart format.";
	}
	else
	{	
		// lookupArray
		// -----------
		// Create helper array lookupArray, with size treeCapacity, that contains i entries 
		// (i= is capacity at depth d) with value d. 
		// For example, for depth 2: [0,1,1,2,2,2,2]
		//=======================================================================================
		std::vector<int> lookupArray;
		int treeCapacity = 0;
		for (int d = 0; d < height; d++)
		{
			for (int i = 0; i < int(std::pow(2, d)); i++)
			{
				lookupArray.push_back(d);
				treeCapacity++;
			}
		}
		
		// treeGrid
		// --------
		// Create helper 2d vector treeGrid that contains all node values ordererd by row (depth) 
		// and column (placement Left & Right under parent), sentinel 'x' used for empty nodes.
		// Queue used as helper container when traversing the tree.
		// For example, tree with three nodes and depth 2, loaded with (5,2,6,7):
		//	[	[ 5 ]
		//		[ 2, 6 ]
		//		[ x, x, x, 7 ]	]
		//=======================================================================================
		std::vector<std::vector<int>> treeGrid;
		treeGrid.resize(height);
		int nodecount = 0;
		TreeNode* emptyNode = new TreeNode;
		std::queue<TreeNode*> queue;
		queue.emplace(node);
		while (nodecount < treeCapacity)
		{
			TreeNode* current = queue.front();
			queue.pop(); nodecount++;
			if (current == nullptr)
			{

				treeGrid[lookupArray[nodecount - 1]].push_back(SENTINEL);
				queue.emplace(emptyNode);
				queue.emplace(emptyNode);
			}
			else
			{
				treeGrid[lookupArray[nodecount - 1]].push_back(current->value);
				queue.emplace(current->leftNode);
				queue.emplace(current->rightNode);
			}
		}
		delete emptyNode; emptyNode = nullptr;

		// printGrid
		// ---------
		// Create helper 2d vector printGrid that contains, per depth level, the number of spaces between different nodes.
		// The number of spaces depends on two print parameters initialized above (start of function)
		//   a) maxPrintableHeight - depth level that is printed, 
		//   b) whitespacePrintFactor - a scaling factor that depends on the largest number of digits for the a node.
		// For example, tree with full capacity and depth 2:
		//
		//	[	[ 7 ]					to create:		.......a			(7 spaces before node1)
		//		[ 3, 7 ]								...b.......c		(3 spaces before node2, 7 spaces before node3)
		//		[ 1, 3, 3, 3 ]	]						.d...e...f...g		(etc.)
		//
		//=======================================================================================
		std::vector<std::vector<int>> printGrid;
		printGrid.resize(maxPrintableHeight);
		for (int i = 0; i < maxPrintableHeight; i++)
		{
			printGrid[i].push_back(whitespacePrintFactor * int(std::pow(2, maxPrintableHeight - i - 1)) - 1);
			for (int j = 1; j < std::pow(2, i); j++)
			{
				printGrid[i].push_back(whitespacePrintFactor * int(std::pow(2, maxPrintableHeight - i)) - 1);
			}
		}

		// Console output
		// --------------
		// Actual loop to print the tree to screen
		//=======================================================================================
		for (int i = 0; i < maxPrintableHeight; i++)
		{
			int reduce_from_next = 0;
			for (int j = 0; j < std::pow(2, i); j++)
			{
				std::cout << std::string(printGrid[i][j] - reduce_from_next, ' ');
				reduce_from_next = 0;
				if (treeGrid[i][j] == SENTINEL)
				{
					std::cout << std::string(minDigits, '.');
					reduce_from_next = minDigits - 1;
				}
				else
				{
					std::cout << treeGrid[i][j];
					int addDigits = 0;
					if (numDigits(treeGrid[i][j]) < int(minDigits))
					{
						addDigits = std::max(minDigits - numDigits(treeGrid[i][j]),0);
						std::cout << std::string(addDigits, '.');
					}
					reduce_from_next = numDigits(treeGrid[i][j]) - 1 + addDigits;
				}
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
	}
}