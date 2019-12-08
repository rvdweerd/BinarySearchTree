#include "BinSearchTree.h"
#include <vector>

int main()
{
	//std::vector<int> list = { 17,4,1,6,32,24,81 };
	std::vector<int> list = { 12,5,15,3,7,13,17,1,9,14,20,8,11,18 };

	TreeNode* tree = nullptr;
	for (int v : list)
	{
		insert(tree, v);
	}
	
	printPre(tree); std::cout << std::endl;
	printIn(tree); std::cout << std::endl;
	printPost(tree); std::cout << std::endl;
	printLevelTopDown(tree); std::cout << std::endl;
	printLevelBottomUp(tree); std::cout << std::endl;
	std::cout << "tree contains 4? " << (findNode(tree, 4) != nullptr) << std::endl;
	std::cout << "tree contains 11? " << (findNode(tree, 11) != nullptr) << std::endl;
	std::cout << "tree contains 1? " << (findNode(tree, 1) != nullptr) << std::endl;
	std::cout << "tree contains 18? " << contains(tree, 18) << std::endl;
	std::cout << "Tree minimum: "; std::cout << getMin(tree) << std::endl;;
	std::cout << "Tree maximum: "; std::cout << getMax(tree) << std::endl;;
	int count;
	count = 0; getNodeDepth(tree, 11, count); std::cout << "Numer 11 is at depth: " << count << std::endl;
	count = 0; getNodeDepth(tree, 12, count); std::cout << "Numer 12 is at depth: " << count << std::endl;
	count = 0; getNodeDepth(tree, 15, count); std::cout << "Numer 15 is at depth: " << count << std::endl;
	count = 0; getNodeDepth(tree, 20, count); std::cout << "Numer 20 is at depth: " << count << std::endl;
	count = 0; getNodeDepth(tree, 9, count); std::cout << "Numer 9 is at depth: " << count << std::endl;
	count = 0; getNodeDepth(tree, 18, count); std::cout << "Numer 18 is at depth: " << count << std::endl;
	std::cout << "The Tree Depth is: " << getTreeDepth(tree)<<std::endl;
	std::cout << "Inserting 19, "; insert(tree, 19);
	std::cout << "The Tree Depth is: " << getTreeDepth(tree) << std::endl;
	std::cin.get();
	return 0;
}