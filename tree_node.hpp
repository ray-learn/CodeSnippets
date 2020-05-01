#include <vector>

using std::vector;

template<typename T>
class TripleTreeNode {
private:
	int height;
	int depth;
	TripleTreeNode<T>* parent;
	TripleTreeNode<T>* left;
	TripleTreeNode<T>* middle;
	TripleTreeNode<T>* right;
	T data;

public:
	TripleTreeNode(): parent{nullptr},left{nullptr},right{nullptr},middle{nullptr} {}
	bool IsRoot();
	bool IsLeaf();
};

template <typename T>
bool TripleTreeNode<T>::IsRoot() {
	return parent == nullptr; 
}

template <typename T>
bool TripleTreeNode<T>::IsLeaf() {
	return left == nullptr && middle == nullptr && right == nullptr;
}

template<typename T>
class TripleLinearTree {
public:
	int height;
	int total;
	vector<TripleTreeNode<T>*> node_array;

	TripleLinearTree() {
	}

	bool IsNull();
};

template <typename T>
bool TripleLinearTree<T>::IsNull() {
	return node_array.size() == 0;
};
