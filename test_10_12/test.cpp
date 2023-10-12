#define  _CRT_SECURE_NO_WARNINGS 1

#include"RBTree.h"
#include"AVLTree.h"
#include<vector>

//int main()
//{
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	RBTree<int, int> t;
//	for (auto e : a)
//	{
//		t.Insert(make_pair(e, e));
//		cout << "Insert:" << e << "->" << t.IsBalance() << endl;
//	}
//
//	return 0;
//}

int main()
{
	const int N = 10000000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (size_t i = 0; i < N; i++)
	{
		v.push_back(i);
	}

	RBTree<int, int> rbt;
	for (auto e : v)
	{
		rbt.Insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	cout << rbt.IsBalance() << endl;
	cout << rbt.Height() << endl;
	cout << rbt._rotateCount << endl;


	AVLTree<int, int> avlt;
	for (auto e : v)
	{
		avlt.Insert(make_pair(e, e));
		//cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	cout << avlt.IsBalance() << endl;
	cout << avlt.Height() << endl;
	cout << avlt._rotateCount << endl;


	return 0;
}

#pragma once

#include<iostream>
#include<assert.h>
using namespace std;

template<class K, class V>
struct AVLTreeNode
{
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;  // balance factor

	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;

		// ... 控制平衡
		// 更新平衡因子
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else // if (cur == parent->_right)
			{
				parent->_bf++;
			}

			if (parent->_bf == 0)
			{
				// 更新结束
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 继续往上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 子树不平衡了，需要旋转
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}

				break;
			}
			else
			{
				assert(false);
			}
		}


		return true;
	}

	void RotateL(Node* parent)
	{
		++_rotateCount;

		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		parent->_right = curleft;
		if (curleft)
		{
			curleft->_parent = parent;
		}

		cur->_left = parent;

		Node* ppnode = parent->_parent;

		parent->_parent = cur;


		if (parent == _root)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;

			}

			cur->_parent = ppnode;
		}

		parent->_bf = cur->_bf = 0;
	}


	void RotateR(Node* parent)
	{
		++_rotateCount;

		Node* cur = parent->_left;
		Node* curright = cur->_right;

		parent->_left = curright;
		if (curright)
			curright->_parent = parent;

		Node* ppnode = parent->_parent;
		cur->_right = parent;
		parent->_parent = cur;

		if (ppnode == nullptr)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}

			cur->_parent = ppnode;
		}

		parent->_bf = cur->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		int bf = curleft->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == 0)
		{
			cur->_bf = 0;
			curleft->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			cur->_bf = 0;
			curleft->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			cur->_bf = 1;
			curleft->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	void RotateLR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		int bf = curright->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 0)
		{
			parent->_bf = 0;
			cur->_bf = 0;
			curright->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			cur->_bf = 0;
			curright->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			cur->_bf = -1;
			curright->_bf = 0;
		}
	}

	int Height()
	{
		return Height(_root);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool IsBalance()
	{
		return IsBalance(_root);
	}

	bool IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftHight = Height(root->_left);
		int rightHight = Height(root->_right);

		if (rightHight - leftHight != root->_bf)
		{
			cout << "平衡因子异常:" << root->_kv.first << "->" << root->_bf << endl;
			return false;
		}

		return abs(rightHight - leftHight) < 2
			&& IsBalance(root->_left)
			&& IsBalance(root->_right);
	}

private:
	Node* _root = nullptr;

public:
	int _rotateCount = 0;
};


#pragma once
#include<iostream>
using namespace std;

enum Colour
{
	RED,
	BLACK
};

template<class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;
	Colour _col;

	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _col(RED)
	{}
};

template<class K, class V>
struct RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;

		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				// u存在且为红
				if (uncle && uncle->_col == RED)
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else // u不存在 或 存在且为黑
				{
					if (cur == parent->_left)
					{
						//     g
						//   p
						// c
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//     g
						//   p
						//		c
						RotateL(parent);
						RotateR(grandfather);

						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
			else // parent == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				// u存在且为红
				if (uncle && uncle->_col == RED)
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						// g
						//	  p
						//       c
						RotateL(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						// g
						//	  p
						// c
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
		}

		_root->_col = BLACK;

		return true;
	}

	void RotateL(Node* parent)
	{
		++_rotateCount;

		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		parent->_right = curleft;
		if (curleft)
		{
			curleft->_parent = parent;
		}

		cur->_left = parent;

		Node* ppnode = parent->_parent;

		parent->_parent = cur;


		if (parent == _root)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;

			}

			cur->_parent = ppnode;
		}
	}


	void RotateR(Node* parent)
	{
		++_rotateCount;

		Node* cur = parent->_left;
		Node* curright = cur->_right;

		parent->_left = curright;
		if (curright)
			curright->_parent = parent;

		Node* ppnode = parent->_parent;
		cur->_right = parent;
		parent->_parent = cur;

		if (ppnode == nullptr)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}

			cur->_parent = ppnode;
		}
	}

	// 17:20继续
	bool CheckColour(Node* root, int blacknum, int benchmark)
	{
		if (root == nullptr)
		{
			if (blacknum != benchmark)
				return false;

			return true;
		}

		if (root->_col == BLACK)
		{
			++blacknum;
		}

		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "出现连续红色节点" << endl;
			return false;
		}

		return CheckColour(root->_left, blacknum, benchmark)
			&& CheckColour(root->_right, blacknum, benchmark);
	}

	bool IsBalance()
	{
		return IsBalance(_root);
	}

	bool IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		if (root->_col != BLACK)
		{
			return false;
		}

		// 基准值
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;

			cur = cur->_left;
		}

		return CheckColour(root, 0, benchmark);
	}

	int Height()
	{
		return Height(_root);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

private:
	Node* _root = nullptr;

public:
	int _rotateCount = 0;
};