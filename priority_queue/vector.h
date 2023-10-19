#pragma once




namespace myvector
{
	template<class T>
	class vector
	{

	public:
		typedef T* iterator;

		vector()
		{

		}

		iterator end()
		{
			return _finish;
		}
		
		
		iterator begin()
		{
			return _start;
		}



		vector(iterator first,iterator last)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstrorage)
			{
				size_t newcapacity = (capacity() == 0 ? 4 : capacity() * 2);
				reserve(newcapacity);
			}
			*_finish = x;
			_finish++;

		}

		size_t capacity()
		{
			return _endofstrorage - _start;
		}

		size_t size()
		{
			return _finish - _start;
		}


		void reserve(size_t n)
		{
			if (n > capacity())
			{
				T*tmp = new T[n];
				size_t sz = size();
				if (_start)
				{
					
					for (int i = 0; i < sz; i++)
					{
						tmp[i] = _start[i];
					}
					
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_endofstrorage = _start + n;
			}
			
		}

	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _endofstrorage = nullptr;



	};
}