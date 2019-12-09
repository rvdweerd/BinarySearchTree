#include "BinSearchTree.h"
#include <vector>

void test()
{
	std::vector<int> list = { 12,5,15,3,7,13,17,3,9,14,20,8,11,18 };
	//std::vector<int> list = { 5,2,6,7 };
	TreeNode* tree = nullptr;
	for (int v : list)
	{
		insert(tree, v);
	}
	std::cout << "\n== TEST 1 - printing ==================================================\n";
	printTreeChart(tree);
	std::cout << "Print pre-order: "; printPre(tree); std::cout << std::endl;
	std::cout << "Print in-order:  "; printIn(tree); std::cout << std::endl;
	std::cout << "Print post-order:"; printPost(tree); std::cout << std::endl;
	std::cout << "Print top-down:  "; printLevelTopDown(tree); std::cout << std::endl;
	std::cout << "Print bottom-up: "; printLevelBottomUp(tree); std::cout << std::endl;
	
	std::cout << "\n== TEST 2.1 - contains() ================================================\n";
	std::cout << "tree contains 4? " << (findNode(tree, 4) != nullptr) << std::endl;
	std::cout << "tree contains 11? " << (findNode(tree, 11) != nullptr) << std::endl;
	std::cout << "tree contains 1? " << (findNode(tree, 1) != nullptr) << std::endl;
	std::cout << "tree contains 18? " << contains(tree, 18) << std::endl;
	std::cout << "\n== TEST 2.2 - findParent() ================================================\n";
	std::cout << "Parent of 7?  "; if (findParent(tree, 7 ) == nullptr) std::cout << "No parent.\n"; else std::cout << findParent(tree, 7 )->value << std::endl;
	std::cout << "Parent of 12? "; if (findParent(tree, 12) == nullptr) std::cout << "No parent.\n"; else std::cout << findParent(tree, 12)->value << std::endl;
	std::cout << "Parent of 11? "; if (findParent(tree, 11) == nullptr) std::cout << "No parent.\n"; else std::cout << findParent(tree, 11)->value << std::endl;
	std::cout << "Parent of 1?  "; if (findParent(tree, 1 ) == nullptr) std::cout << "No parent.\n"; else std::cout << findParent(tree, 1 )->value << std::endl;
	std::cout << "Parent of 18? "; if (findParent(tree, 18) == nullptr) std::cout << "No parent.\n"; else std::cout << findParent(tree, 18)->value << std::endl;

	std::cout << "\n== TEST 3 - min/max value =============================================\n";
	std::cout << "Tree minimum: "; std::cout << getMin(tree) << std::endl;;
	std::cout << "Tree maximum: "; std::cout << getMax(tree) << std::endl;;

	std::cout << "\n== TEST 4 - node depth (root=0) =======================================\n";
	int count;
	count = 0; getNodeDepth(tree, 11, count); std::cout << "Number 11 is at depth: " << count << std::endl;
	count = 0; getNodeDepth(tree, 12, count); std::cout << "Number 12 is at depth: " << count << std::endl;
	count = 0; getNodeDepth(tree, 15, count); std::cout << "Number 15 is at depth: " << count << std::endl;
	count = 0; getNodeDepth(tree, 20, count); std::cout << "Number 20 is at depth: " << count << std::endl;
	count = 0; getNodeDepth(tree, 9, count); std::cout << "Number 9 is at depth: " << count << std::endl;
	count = 0; getNodeDepth(tree, 18, count); std::cout << "Number 18 is at depth: " << count << std::endl;
	std::cout << "The Tree contains " << getNumberOfNodes(tree) << " elements.\n";
	std::cout << "The Tree Height is: " << getTreeHeight(tree) << std::endl;
	
	std::cout << "\n== TEST 5 - insert() ==================================================\n";
	std::cout << "Inserted 19.\n"; insert(tree, 19);
	printTreeChart(tree);
	std::cout << "The Tree contains " << getNumberOfNodes(tree) << " elements.\n";
	std::cout << "The Tree Height is: " << getTreeHeight(tree) << std::endl;
	std::cout << "The number of nodes at depth 0: " << getNumberOfElementsAtDepth(tree, 0) << std::endl;
	std::cout << "The number of nodes at depth 1: " << getNumberOfElementsAtDepth(tree, 1) << std::endl;
	std::cout << "The number of nodes at depth 2: " << getNumberOfElementsAtDepth(tree, 2) << std::endl;
	std::cout << "The number of nodes at depth 3: " << getNumberOfElementsAtDepth(tree, 3) << std::endl;
	std::cout << "The number of nodes at depth 4: " << getNumberOfElementsAtDepth(tree, 4) << std::endl;
	std::cout << "The number of nodes at depth 5: " << getNumberOfElementsAtDepth(tree, 5) << std::endl;

	std::cout << "\n== TEST 6.1 - remove() - Leafs =========================================\n";
	std::cout << "Removing 8, 11, 19.\n";
	remove(tree, 8); remove(tree, 11); remove(tree, 19);
	printTreeChart(tree);
	std::cout << "\n== TEST 6.2 - remove() - One Child Nodes (L and R) =====================\n";
	std::cout << "Removing 13, 20.\n";
	remove(tree, 13); 
	remove(tree, 20);
	printTreeChart(tree);
	std::cout << "\n== TEST 6.3 - remove() - Full Node======================================\n";
	std::cout << "Removing 12.\n";
	remove(tree, 12);
	printTreeChart(tree);
	std::cout << "Removing 14.\n";
	remove(tree, 14);
	printTreeChart(tree);
	std::cout << "Removing 5.\n";
	remove(tree, 5);
	printTreeChart(tree);


}

int main()
{
	test();
	

	


	std::cin.get();
	return 0;
}