#pragma once
#include<iostream>
#include<assert.h>

using namespace std;

namespace myvector
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
		: _start(nullptr)
		, _finish(nullptr)
		, _endofstorage(nullptr)
		{}

		vector(const vector<T> & v)//拷贝构造函数
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			_start = new T[v.capacity()];
			for (size_t i = 0; i < v.size(); i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
		}

		vector(size_t n, const T& val = T())//给缺省值
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			resize(n, val);
		}

		vector(int n, const T& val = T())//函数重载，方便编译器识别
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			resize(n, val);
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}


		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage ,v._endofstorage);
		}

		vector<T>& operator=(vector<T> v)//构造临时类型，互换后释放
		{
			swap(v);
			return *this;
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}

		size_t size() const 
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		iterator end() 
		{
			return _finish;
		}

		iterator begin() 
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}



		void resize(size_t n, const T& val)
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
		}

		//扩容
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T)*sz);//注意
					for (size_t i = 0; i < sz; i++)//字符串拷贝时需要深拷贝。所以需要调用string类的赋值实现深拷贝
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
					
				}
				_start = tmp;
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
			
			

		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return *(_start + pos);
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}
		void push_back(const T&x)
		{
			/*if (_finish == _endofstorage)
			{
				size_t newcapacity=(capacity()== 0 ? 4 : capacity() * 2);
				reserve(newcapacity);
			}

			*_finish = x;
			_finish++;*/
			insert(_finish,x);
			
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			if (_finish == _endofstorage)
			{
				size_t sz = pos - _start;
				size_t newcapacity = (capacity() == 0 ? 4 : capacity() * 2);
				reserve(newcapacity);
				//解决迭代器失效
				pos = _start + sz;

			}
			iterator end = _finish-1;
			while (pos <= end)
			{
				*(end + 1) = *end;
				end--;
			}

			*pos = x;
			_finish++;


			return pos;
		}

		iterator erase(iterator pos)//使用过后迭代器失效（防止修改原位置数据，vs环境下强制检查，Linux下可以访问）
		{
			assert(pos >= _start && pos < _finish);

			iterator it = pos + 1;

			while (it != _finish)
			{
				*(it - 1) = *it;
				it++;
				
			}

			_finish--;

			return pos;
		}
		

	
	private:
		T* _start;
		T* _finish;
		T* _endofstorage;

	};
}

