#include <iostream>
#include <string>
#include "tree_node.hpp"

using namespace std;

int main() {
	int capacity = 10;
	string root_node = "hello root";
	string child_node = "hello child";
	string update_node = "hello update";
	TripleLinearTree<string> tree = TripleLinearTree<string>::InitTripleLinearTree(capacity);
	cout << "IsEmpty: " << tree.IsEmpty() << endl;
	cout << "IsRoot: " << tree.IsRoot(0) << endl;
	cout << "GetHeight(10): " << tree.GetHeight(10) << endl;
	cout << "AddTreeNode(&root_node): " << tree.AddTreeNode(&root_node) << endl;
	cout << "AddTreeNode(&child_node): " << tree.AddTreeNode(&child_node) << endl;
	cout << "GetTreeNode(0): " << *tree.GetTreeNode(0) << endl;
	cout << "UpdateTreeNode: " << tree.UpdateTreeNode(&update_node, 0) << endl;
	cout << "GetTreeNode(0): " << *tree.GetTreeNode(0) << endl;
	cout << "GetTreeNode(1): " << *tree.GetTreeNode(1) << endl;
	cout << "DeleteTreeNode(0): " << tree.DeleteTreeNode(0) << endl;
	cout << "GetTreeNode(0): " << *tree.GetTreeNode(0) << endl;
	return 0;
}
