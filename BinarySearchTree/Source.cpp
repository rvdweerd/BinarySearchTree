#include "BinSearchTree.h"
#include <vector>

int main()
{
	std::vector<int> list = { 17,4,1,6,32,24,81 };


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

	std::cin.get();
	return 0;
}