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

		string(const string& str) //拷贝构造函数
		{
			_str = new char[str._capacity + 1];
			strcpy(_str, str._str);
			_size = str._size;
			_capacity = str._capacity;
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
			int end = _size;
			//挪动数据
			while ((int)pos <= end )//当end减小到最小时会转换成很大的数，这里会隐式转换。//while(pos<=end&&end!=npos)
			{
				_str[end + n] = _str[end];
				end--;
			}
			for (int i = 0; i < n; i++)
			{
				_str[pos+i] = ch;
			}
			_size += n;
		}

		void insert(size_t pos, const char* str)
		{
			assert(pos < _size);
			size_t len = strlen(str);
			size_t end = _size;
			if (len + _size > _capacity)
			{
				reserve(len + _size + 2);
			}
			while (pos <= end && end != npos)
			{
				_str[end + len] = _str[end];
				end--;
			}
			for (int i = 0; i < len; i++)
			{
				_str[pos + i] = str[i];

			}
			_size += len;
		}

		typedef char* iterator;
		typedef const char* const_iterator;

		iterator end()
		{
			return _str + _size;
		}

		iterator begin()
		{
			return _str;
		}

		const_iterator end() const 
		{
			return _str + _size;
		}

		const_iterator begin() const 
		{
			return _str;
		}


		void erase(size_t pos, size_t len = npos)
		{
			assert(pos <= _size);
			if (len == npos || len + pos >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
				_str[_size] = '\0';
			}
			else
			{
				size_t end = len +pos;
				while (end <= _size)
				{
					_str[pos++] = _str[end++];
				}
				_size -= len;

			}

		}


		size_t find(char ch, size_t pos=npos)
		{
			assert(pos <= _size);
			for (int i = pos; i < _size; i++)
			{
				if (ch == _str[i])
					return i;
			}
			return npos;

		}
		
		size_t find(const char* str, size_t pos=0)
		{
			assert(pos < _size);
			const char* ptr = strstr(_str + pos, str);
			if (ptr)
			{
				return ptr - _str;
			}
			else
				return npos;
			
		}

		/*string substr(size_t pos=0, size_t len=npos)
		{
			assert(pos <= _size);
			size_t n=len;
			if (len == npos || pos + len >= _size)
			{
				 n = _size - pos;
			}
			string tmp;
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				tmp += _str[pos + i];
			}
			return tmp;

			
			
		}*/

		string substr(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);

			size_t n = len;
			if (len == npos || pos + len > _size)
			{
				n = _size - pos;
			}

			string tmp;
			tmp.reserve(n+2);
			for (size_t i = pos; i < pos + n; i++)
			{
				tmp += _str[i];
			}

			return tmp;
		}

		static const size_t npos;



	private:
		size_t _size;
		size_t _capacity;
		char* _str;
	};

	const size_t string::npos = -1;
}