#include <iostream>
#include <string>
#include "tree_node.hpp"

using namespace std;

int main() {
	int capacity = 10;
	string root_node = "hello 1";
	string second_node = "hello 2";
	string third_node = "hello 3";
	string forth_node = "hello 4";
	string five_node = "hello 5";
	string six_node = "hello 6";
	string seven_node = "hello 7";
	string eight_node = "hello 8";
	string nine_node = "hello 9";
	TripleLinearTree<string> tree = TripleLinearTree<string>::InitTripleLinearTree(capacity);
	cout << "AddTreeNode(&root_node): " << tree.AddTreeNode(&root_node) << endl;
	cout << "AddTreeNode(&second_node): " << tree.AddTreeNode(&second_node) << endl;
	cout << "AddTreeNode(&third_node): " << tree.AddTreeNode(&third_node) << endl;
	cout << "AddTreeNode(&forth_node): " << tree.AddTreeNode(&forth_node) << endl;
	cout << "AddTreeNode(&five_node): " << tree.AddTreeNode(&five_node) << endl;
	cout << "AddTreeNode(&six_node): " << tree.AddTreeNode(&six_node) << endl;
	cout << "AddTreeNode(&seven_node): " << tree.AddTreeNode(&seven_node) << endl;
	cout << "AddTreeNode(&eight_node): " << tree.AddTreeNode(&eight_node) << endl;
	cout << "AddTreeNode(&nine_node): " << tree.AddTreeNode(&nine_node) << endl;
	tree.PreOrderTraverse(); 
	cout << "~!@#$%^&*()_+" << endl;
	tree.InOrderTraverse(); 
	cout << "~!@#$%^&*()_+" << endl;
	tree.PostOrderTraverse(); 
	return 0;
}
