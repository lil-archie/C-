#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once 

#include<iostream>
#include<queue>

using namespace std;
//优先级队列：按照大小堆的方式排序，容器适配器
namespace mypriority_queue
{
	template<class T,class Container=vector<T>>
	class priority_queue
	{
	public:
		priority_queue()//构造函数
		{
		}
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)//迭代器完成初始化
		{
			while()

		}



	private:

	};
}