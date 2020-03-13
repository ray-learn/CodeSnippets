#include <iostream>
#include <string>

using namespace std;

template<class T>
class BinNode {
public:
	T data;
	BinNode<T>* parent;
	BinNode<T>* left_child;
	BinNode<T>* right_child;
};

int main() {
	BinNode<string> bn;
	bn.data = "Hello World";
	cout << bn.data;
	return 0;
}
