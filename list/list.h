#pragma once
//#pragma once
#include<assert.h>
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

	template<class T,class Ref,class Ptr>
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

		// typedef __list_iterator<T, T&, T*> iterator;
	// typedef __list_iterator<T, const T&, const T*> const_iterator;
		typedef list_node<T> Node;
		typedef __list_iterator< T,  Ref,  Ptr> self;
		Node* _node;

		__list_iterator(Node* node)
			:_node(node)
		{}

		Ref& operator*()
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &_node->_val;
		}


		self & operator--() //前置
		{
			_node = _node->_prev;
			return *this;
		}


		self operator--(int) //后置
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		self operator++(int)//后置
		{
			self tmp(*this);

			_node = _node->_next;

			return tmp;
		}

		self &operator++()//前置
		{
			

			_node = _node->_next;

			return *this;
		}

		bool operator!=(const self & it)const 
		{
			return _node != it._node;
		}

		bool operator==(const self& it) const
		{
			return _node == it._node;
		}



	};

	//类函数的实现
	template<class T>
	class list
	{
		typedef list_node<T> Node;
	public:
		 typedef __list_iterator<T, T&, T*> iterator;
	     typedef __list_iterator<T, const T&, const T*> const_iterator;



		 void empty_init()
		 {
			 _head = new Node;
			 _head->_next = _head;
			 _head->_prev = _head;

			 _size = 0;
		 }
		
		 
		 list()
		 {
			 empty_init();

		 }



		list(const list<T>& lt)
		{
			empty_init();
			for (auto& e : lt)
			{
				push_back(e);
			}
		}
		void swap(list<T>& lt)
		{
			std::swap(_head, lt._head);

			std::swap(_size, lt._size);
		}


		list<T>& operator=(const list<T> lt)
		{
			swap(lt);
			return *this;
		}

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}


		

		void push_back(const T& x)
		{
			//Node* newnode = new Node;

			//Node* tail = _head->_prev;
			//newnode->_val = x;

			///*newnode->_prev = _head->_next;
			//_head->_next->_next = newnode;

			//newnode->_next = _head;
			//_head->_prev = newnode;*/

			//newnode->_prev = tail;
			//tail->_next = newnode;

			//newnode->_next = _head;
			//_head->_prev = newnode;

			insert(end(), x);

		}

		void  pop_back()
		{
			erase(--end());
		}

		size_t size()
		{
			return _size;
		}

		void push_front(const T&x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			erase(begin());
		}

		//在pos位置之前插入
		iterator insert(iterator pos,const T&x)
		{
			
			Node* cur = pos._node;
			Node* newnode = new Node(x);
			Node* prev = cur->_prev;

			prev->_next = newnode;
			newnode->_prev = prev;

			cur->_prev = newnode;
			newnode->_next = cur;

			_size++;

			return newnode;

		}

		

		iterator erase(iterator pos)
		{
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;


			delete cur;
			--_size;

			return next;


		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);

			}
			_size = 0;
		}
		~list()
		{
			clear();

			delete _head;
			_head = nullptr;

		}


		




	private:
		Node* _head;
		size_t _size;


	};
}
