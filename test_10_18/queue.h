
#pragma once

#include<iostream>
#include<stack>
#include<list>
#include<queue>
using namespace std;

//namespace bit
//
//{

//#include<deque>
//
//	template<class T, class Con = deque<T>>
//
//	class stack
//
//	{
//
//	public:
//
//		stack();
//
//		void push(const T& x);
//
//		void pop();
//
//		T& top();
//
//		const T& top()const;
//
//		size_t size()const;
//
//		bool empty()const;
//
//	private:
//
//		Con _c;
//
//	};
//
//
//
//	template<class T, class Con = deque<T>>
//
//	class queue
//
//	{
//
//	public:
//
//		queue();
//
//		void push(const T& x);
//
//		void pop();
//
//		T& back();
//
//		const T& back()const;
//
//		T& front();
//
//		const T& front()const;
//
//		size_t size()const;
//
//		bool empty()const;
//
//	private:
//
//		Con _c;
//
//	};
//
//};
namespace myContainer
{

	//  ≈‰∆˜
	template<class T, class Container = deque<T>>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_front();
		}
		T& front()
		{
			return _con.front();
		}
		T& back()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

	private:
		Container _con;
	};

	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_c.push_back(x);
		}
		void pop()
		{
			_c.pop_back();
		}
		T& front()
		{
			return _c.front();
		}
		T& back()
		{
			return _c.back();
		}
		size_t size()
		{
			return _c.size();
		}
		bool empty()
		{
			return _c.empty();
		}

	private:
		Container _c;
	};


}



