#include<iostream>
#include<string.h>
using namespace std;
template <typename T>
class AVLTree {
	struct Node {
		T _key;
		Node *_left;
		Node *_right;
		uint8_t _height;
		Node(const T& k) :_key(k), _left(nullptr), _right(nullptr), _height(1) { ; }
	};
	Node* root;
	uint8_t GetHeight(Node* p) {
		return p != nullptr ? p->_height : 0;
		p-
	}
	int GetBalance(Node* p) {
		return GetHeight(p->_left) - GetHeight(p->_right);
	}
	void UpdateHeight(Node* p) {
		auto leftHeight = GetHeight(p->_left);
		auto rightHeight = GetHeight(p->_right);
		p->_height = max(leftHeight, rightHeight) + 1;
	}
	Node* RotateRight(Node* p);
	Node* Balance(Node* p);
	Node* Insert(Node* p, const T& key);
	Node* Remove(Node*p, const T& key);
	Node* Find(Node* p, const T& key) {
		if (root == nullptr)return nullptr;
		if(key<root->)
	}
	void Print(Node* p, size_t offset);
public:
	AVLTree() :root(nullptr){}
	AVLTree(const AVLTree&) = delete;
	AVLTree(AVLTree&&) = delete;
	~AVLTree(){}//через рекурсивную приватную функцию
	bool Find(const T& key) {
		return Find(root, key)!=nullptr;
	}
	void Insert(const T& key) {
		root = Insert(root, key);
	}
	void Remove(const T& key) {
		Remove(root, key);
	}
	Node* RotateRight(Node* p) {
		
	}
};