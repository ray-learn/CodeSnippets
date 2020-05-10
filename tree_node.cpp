#include <iostream>
#include <string>
#include "tree_node.hpp"

using namespace std;

int main() {
	int total_node = 10;
	string node = "hello node";
	string update_node = "hello update";
	TripleLinearTree<string> tree = TripleLinearTree<string>::InitTripleLinearTree(total_node);
	cout << "IsEmpty: " << tree.IsEmpty() << endl;
	cout << "IsRoot: " << tree.IsRoot(0) << endl;
	cout << "GetHeight: " << tree.GetHeight(10) << endl;
	cout << "AddTreeNode: " << tree.AddTreeNode(&node) << endl;
	cout << "GetTreeNode: " << *tree.GetTreeNode(0) << endl;
	cout << "UpdateTreeNode: " << tree.UpdateTreeNode(&update_node, 0) << endl;
	cout << "GetTreeNode: " << *tree.GetTreeNode(0) << endl;
	return 0;
}
