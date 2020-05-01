#include <iostream>
#include <string>
#include "tree_node.hpp"

using namespace std;

int main() {
	TripleTreeNode<string> node;
	cout << "IsRoot: " << node.IsRoot() << endl;
	cout << "IsLeaf: " << node.IsLeaf() << endl;

	TripleLinearTree<string> tree;
	cout << "IsNull: " << tree.IsNull() << endl;
	return 0;
}
		
