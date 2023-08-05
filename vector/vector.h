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





		//扩容
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T)*sz);//注意
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
		

	
	private:
		T* _start;
		T* _finish;
		T* _endofstorage;

	};
}

