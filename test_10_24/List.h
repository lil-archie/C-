#pragma once


#include<iostream>
#include<list>

using namespace std;

namespace mylist
{
	template<class T>
	struct list_node
	{
		list_node<T>* _prev;
		list_node<T>* _next;
		T _val;

		list_node(const& T = T())
			:_prev(nullptr)
			, _next(nullptr)
			, _val(val)
		{

		}

	};
	template<class T> 
	class list
	{
		typedef list_node<T> node;
	public:
		void push_back(const &x)
		{
			if()
		}
	private:
		node* head;
		size_t size;
	};
}