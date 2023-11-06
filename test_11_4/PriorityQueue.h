#pragma once
#include"test.h"
template<class T>
class Less
{
public:
	bool operator()(const T& x, const T& y)
	{
		return x < y;
	}
};

template<class T>
class Greater
{
public:
	bool operator()(const T &x, const T &y)
	{
		return x > y;
	}
};
namespace myPriorityQueue
{
	template<class T,class Container=vector<T>,class Compare=Less<T>>
	class Priority_queue
	{
	public:
		Priority_queue()
		{
		}
		template<class Iterator>
		Priority_queue(Iterator first,Iterator last)
		{
			while (first != last)
			{
				_con.push_back(*first);
				first++;
			}
			for (int i = (_con.size() - 1 - 1) / 2; i > 0; i--)
			{
				AdjustDown(i);
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1);

		}
		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}
		T& top()
		{
			return _con[0];
		}
		bool empty()
		{
			return _con.empty();

		}
		size_t size()
		{
			return _con.size();
		}
	private:
		void AdjustDown(int parent)
		{
			Compare com;
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1]))
				{
					child++;
				}
				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent],_con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		void AdjustUp(int child)//向调整法
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child>0)
			{
				if (com(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		


		Container _con;
	};
}