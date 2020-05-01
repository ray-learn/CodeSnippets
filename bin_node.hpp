
template<class T>
class BinNode {
public:
	T data;
	BinNode<T>* parent;
	BinNode<T>* left_child;
	BinNode<T>* right_child;
};

template<class T>
class BinTree {
public:
	BinNode<T>* root; 
};


