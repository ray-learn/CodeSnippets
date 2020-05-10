#include <iostream>
#include <string>
#include "tree_node.hpp"

using namespace std;

int main() {
	int total_node = 10;
	string node = "hello node";
	TripleLinearTree<string> tree = TripleLinearTree<string>::InitTripleLinearTree(total_node);
	cout << "IsEmpty: " << tree.IsEmpty() << endl;
	cout << "IsRoot: " << tree.IsRoot(0) << endl;
	cout << "GetHeight: " << tree.GetHeight(10) << endl;
	cout << "AddTreeNode: " << tree.AddTreeNode(&node) << endl;
	return 0;
}
		
