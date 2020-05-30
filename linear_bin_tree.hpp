#include <vector>
#include <stack>
#include <cmath>

using std::endl;
using std::cout;
using std::vector;
using std::stack;
using std::ceil;

const int ROOT_INDEX = 1;
const int NULL_INDEX = -1;

template<typename T>
class LinearBinTree {
private:
	int height;
	int total;
	int capacity;
	vector<T*> node_array;

	LinearBinTree(int capacity) :capacity(capacity),total(0) {
		node_array.reserve(capacity);
	}

public:
	static LinearBinTree InitLinearBinTree(int capacity){
		return LinearBinTree(capacity);	
	}
	bool AddTreeNode(T* node);
	bool UpdateTreeNode(T* node, int rank);
	bool DeleteTreeNode(int rank);
	T* GetTreeNode(int rank);
	int GetTreeNodeRank(T* node);
	bool IsEmpty();
	bool IsRoot(int rank);
	bool IsLeaf(int rank);
	int GetHeight(int rank);
	void PreOrderTraverse();
	void InOrderTraverse();
	void PostOrderTraverse();
};

template <typename T>
bool LinearBinTree<T>::IsEmpty() {
	return node_array.empty();
};

template <typename T>
bool LinearBinTree<T>::IsRoot(int rank) {
	if (total == 0) {
		return false;
	}
	if (rank == 0) {
		return true;
	}
	return false;
};

template <typename T>
bool LinearBinTree<T>::IsLeaf(int rank) {
	if (2 * rank > total) {
		return true;
	}
	return false;
};

template <typename T>
int LinearBinTree<T>::GetHeight(int rank) {
	if (rank > total) {
		return -1;
	}
	return ceil(float(rank)/2);
};

template <typename T>
bool LinearBinTree<T>::AddTreeNode(T* node) {
	if (total == capacity) {
		capacity = 2 * capacity;
		node_array.reserve(capacity);
	}
	node_array.push_back(node);
	total += 1;
	return true;
};

template <typename T>
T* LinearBinTree<T>::GetTreeNode(int rank) {
	if (rank > total) {
		return nullptr;
	}
	return node_array[rank];
};

template <typename T>
bool LinearBinTree<T>::UpdateTreeNode(T* node, int rank) {
	if (rank > total) {
		return false;
	}
	node_array[rank] = node;
	return true; 
};

template <typename T>
bool LinearBinTree<T>::DeleteTreeNode(int rank) {
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

template <typename T>
void LinearBinTree<T>::PreOrderTraverse() {
	if (total == 0) {
		return;
	}

	stack<int> index_stack;
	index_stack.push(ROOT_INDEX);

	while (!index_stack.empty()) {
		int root_rank = index_stack.top();
		index_stack.pop();
		cout << "traversing index is: " << root_rank << endl;
		if ((2 * root_rank + 1) <= total) {
			index_stack.push(2 * root_rank + 1);
		}
		if ((2 * root_rank) <= total) {
			index_stack.push(2 * root_rank);
		}
	}
	return;
};

template <typename T>
void LinearBinTree<T>::InOrderTraverse() {
	if (total == 0)
		return;

	int root_index = ROOT_INDEX;
	stack<int> index_stack;
	index_stack.push(ROOT_INDEX);

	while (!index_stack.empty() || root_index != NULL_INDEX) {
		if (root_index != NULL_INDEX)
			while ((2 * root_index) <= total) {
				index_stack.push(2 * root_index);
				root_index = 2 * root_index;
			}

		int root_rank = index_stack.top();
		index_stack.pop();
		cout << "traversing index is: " << root_rank << endl;
		if ((2 * root_rank) + 1 <= total) {
			root_index = 2 * root_rank + 1;
			index_stack.push(root_index);
		} else {
			root_index = NULL_INDEX;
		}
	}
};

template <typename T>
void LinearBinTree<T>::PostOrderTraverse() {
	if (total == 0)
		return;

	int root_index = ROOT_INDEX;
	int last_index;
	stack<int> index_stack;
	index_stack.push(ROOT_INDEX);

	while (!index_stack.empty() || root_index != NULL_INDEX) {
		if (root_index != NULL_INDEX)
			while ((2 * root_index) <= total) {
				index_stack.push(2*root_index);
				root_index= 2 * root_index;
			}

		int root_rank = index_stack.top();
		if ((( 2 * root_rank) + 1 <= total) && ((( 2 * root_rank) + 1) != last_index)) {
			root_index = 2 * root_rank + 1;
			index_stack.push(root_index);
		} else {
			index_stack.pop();
			cout << "traversing index is: " << root_rank << endl;
			root_index = NULL_INDEX;
			last_index = root_rank;
		}
	}
};

template <typename T>
int LinearBinTree<T>::GetTreeNodeRank(T* node) {
	for (int i = 0; i < total-1; i++) {
		if (node == node_array[i]) {
			return i + 1;
		}
	}
	return NULL_INDEX;
}
