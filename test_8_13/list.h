#pragma once

#include<iostream>

using namespace std;

namespace mylist
{
	//定义链表的结构
	template<class T>
	struct list_node
	{
		list_node<T>* _prev;
		list_node<T>* _next;
		T _val;

		list_node<T>(const T& val = T())
			:_prev(nullptr)
			, _next(nullptr)
			, _val(val)
		{}

	};
	//迭代器的实现
	//template<class T>
	//struct __lsit_iterator
	//{
	//	typedef list_node<T> Node;
	//	
	//	Node* _node;
	//	
	//	__list_iterator(Node *node)
	//		:_node(node)
	//	{}

	//	T& operator *()
	//	{
	//		return _node->_val;
	//	}

	//	__list_iterator<T> & operator++() //后置++
	//	{
	//		_node = _node->next;
	//		return *this;
	//	}

	//	__list_iterator<T> operator++(int)//前置++
	//	{
	//		__lsit_iterator<T> tmp(*this);
 //
	//		_node = _node->next;

	//		return tmp;

	//		
	//	}

		/*bool operator!=(const __list_iterator<T>& it)
		{
			return _node != it._node;
		}*/



	/*template<class T>
	struct __list_const_iterator
	{
		typedef list_node<T> Node;
		Node* _node;

		__list_const_iterator(Node* node)
			:_node(node)
		{}

		const T& operator*()
		{
			return _node->_val;
		}

		__list_const_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		__list_const_iterator<T> operator++(int)
		{
			__list_const_iterator<T> tmp(*this);

			_node = _node->_next;

			return tmp;
		}

		bool operator!=(const __list_const_iterator<T>& it)
		{
			return _node != it._node;
		}

		bool operator==(const __list_const_iterator<T>& it)
		{
			return _node == it._node;
		}
	};*/

	//};

	/*template<class T>
	struct __list_iterator
	{
		typedef list_node<T> Node;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		T& operator*()
		{
			return _node->_val;
		}

		__list_iterator<T>& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		__list_iterator<T> operator++(int)
		{
			__list_iterator<T> tmp(*this);

			_node = _node->_next;

			return tmp;
		}

		bool operator!=(const __list_iterator<T>& it)
		{
			return _node != it._node;
		}

		bool operator==(const __list_iterator<T>& it)
		{
			return _node == it._node;
		}
	};*/

	// 这么设计太冗余了，看看库里面如何设计的
		//typedef __list_const_iterator<T> const_iterator;


		// 这样设计const迭代器是不行的，因为const迭代器期望指向内容不能修改
		// 这样设计是迭代器本身不能修改
		//typedef const __list_iterator<T> const_iterator;
		// const T* ptr1;
		// T* const ptr2;

		// 如何设计const迭代器？

	template<class T>
	struct __list_iterator
	{
		/*typedef list_node Node;
		Node* _node;
		__list_iterator(Node* node)
			:_node(node)
		{
		}
		T& operator*()
		{
			return _node->_val;
		}

		__list_iterator<T> */
		typedef list_node<T> Node;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		T& operator*()
		{
			return _node->_val;
		}

		__list_iterator<T>& operator++() //前置
		{
			_node = _node->_next;
			return *this;
		}

		__list_iterator<T> operator++(int)//后置
		{
			__list_iterator<T> tmp(*this);

			_node = _node->_next;

			return tmp;
		}

		bool operator!=(const __list_iterator<T>& it)
		{
			return _node != it._node;
		}

	};

	//类函数的实现
	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		typedef __list_iterator<T> iterator;


		list()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		void push_back(const T&x)
		{
			Node*newnode = new Node;

			Node* tail = _head->_prev;
			newnode->_val = x;

			/*newnode->_prev = _head->_next;
			_head->_next->_next = newnode;

			newnode->_next = _head;
			_head->_prev = newnode;*/

			newnode->_prev = tail;
			tail->_next = newnode;

			newnode->_next = _head;
			_head->_prev = newnode;
			
		}

		
		
	private:
		Node* _head;

	
	};
}
