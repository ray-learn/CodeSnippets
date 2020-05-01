#include <iostream>
#include <string>
#include "bin_node.hpp"

using namespace std;

int main() {
	BinNode<string> bn;
	bn.data = "Hello World";
	cout << bn.data;
	return 0;
}
