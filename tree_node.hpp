#include <vector>
#include <cmath>

using std::vector;
using std::ceil;

template<typename T>
class TripleLinearTree {
private:
	int height;
	int total;
	int capacity;
	vector<T*> node_array;

	TripleLinearTree(int capacity) :capacity(capacity),total(0) {
		node_array.reserve(capacity);
	}

public:
	static TripleLinearTree InitTripleLinearTree(int capacity){
		return TripleLinearTree(capacity);	
	}
	bool AddTreeNode(T* node);
	bool UpdateTreeNode(T* node, int rank);
	bool DeleteTreeNode(int rank);
	T* GetTreeNode(int rank);
	bool IsEmpty();
	bool IsRoot(int rank);
	bool IsLeaf(int rank);
	int GetHeight(int rank);
};

template <typename T>
bool TripleLinearTree<T>::IsEmpty() {
	return node_array.empty();
};

template <typename T>
bool TripleLinearTree<T>::IsRoot(int rank) {
	if (total == 0) {
		return false;
	}
	if (rank == 0) {
		return true;
	}
	return false;
};

template <typename T>
bool TripleLinearTree<T>::IsLeaf(int rank) {
	if (3 * rank > total) {
		return true;
	}
	return false;
};

template <typename T>
int TripleLinearTree<T>::GetHeight(int rank) {
	if (rank > total) {
		return -1;
	}
	return ceil(float(rank)/3);
};

template <typename T>
bool TripleLinearTree<T>::AddTreeNode(T* node) {
	if (total == capacity) {
		capacity = 2 * capacity;
		node_array.reserve(capacity);
	}
	node_array.push_back(node);
	total += 1;
	return true;
};

template <typename T>
T* TripleLinearTree<T>::GetTreeNode(int rank) {
	if (rank > total) {
		return nullptr;
	}
	return node_array[rank];
};

template <typename T>
bool TripleLinearTree<T>::UpdateTreeNode(T* node, int rank) {
	if (rank > total) {
		return false;
	}
	node_array[rank] = node;
	return true; 
};

template <typename T>
bool TripleLinearTree<T>::DeleteTreeNode(int rank) {
	if (rank == (total-1)) {
		node_array[rank] = nullptr;
		total -= 1;
		return true;
	}
	for (int i = rank; i < total-1; i++) {
		node_array[i] = node_array[i+1];
	}
	node_array[total-1] = nullptr;
	total -= 1;
	return true; 
};
