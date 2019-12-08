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
	std::cout << "tree contains 18? " << (findNode(tree, 18) != nullptr) << std::endl;

	std::cin.get();
	return 0;
}