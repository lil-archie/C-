#pragma once
#pragma once
#include<vector>
#include<list>
#include<deque>

namespace bit
{
	// 
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}

		T& top()
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

	void test_stack()
	{
		//stack<int, vector<int>> st1;
		stack<int> st1;
		st1.push(1);
		st1.push(2);
		st1.push(3);
		st1.push(4);

		while (!st1.empty())
		{
			cout << st1.top() << " ";
			st1.pop();
		}
		cout << endl;

		stack<int, list<int>> st2;
		st2.push(1);
		st2.push(2);
		st2.push(3);
		st2.push(4);

		while (!st2.empty())
		{
			cout << st2.top() << " ";
			st2.pop();
		}
		cout << endl;
	}
}

#pragma once
#include<vector>
#include<list>
#include<deque>

namespace bit
{
	// 
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
			//_con.erase(_con.begin());
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

	void test_queue()
	{
		queue<int, list<int>> q;

		//queue<int, vector<int>> q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);

		while (!q.empty())
		{
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}
}

