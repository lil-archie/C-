#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace mystring
{
	class string
	{
	public:
		/*string(const char* str="")
			:_size(strlen(str))
			;_capacity(_size)
			;_str(new char[_capacity + 1])
		{
			strcpy(_str, str);
		}*/

		

		string(const char* str = "")//构造函数
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		~string()//析构函数
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}

		const char* c_str()const
		{
			return _str;
		}

		size_t size() const
		{
			return _size;
		}

		char& operator[](size_t pos)
		{
			assert(pos<_size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			
			if (n> _capacity)
			{
				char* tmp = new char[n];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';

		}

		void append(const char* str)
		{
			size_t len = strlen(str);
			if (len + _size > _capacity)
				reserve((len + _size)+2);
			strcpy(_str + _size, str);
			_size += len;
		}

		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		void insert(size_t pos, size_t n, char ch)
		{
			assert(pos < _size);
			if (n + _size >= _capacity)
				reserve(n + _size + 2);
			size_t end = _size;
			while (pos <= end && end != npos)
			{

			}
		}

		static const size_t npos;



	private:
		size_t _size;
		size_t _capacity;
		char* _str;
	};

	const size_t string::npos = -1;s
}