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
	
	print(tree);

	std::cin.get();
	return 0;
}