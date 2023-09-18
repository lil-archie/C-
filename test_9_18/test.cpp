#define  _CRT_SECURE_NO_WARNINGS 1
#pragma once

#include"HashTable.h"

namespace bit
{
	template<class K>
	class unordered_set
	{
		struct SetKeyOfT
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename hash_bucket::HashTable<K, K, SetKeyOfT>::const_iterator const_iterator;


		const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}

		// 20:28
		pair<const_iterator, bool> insert(const K& key)
		{
			//return _ht.Insert(key);
			pair<typename hash_bucket::HashTable<K, K, SetKeyOfT>::iterator, bool> ret = _ht.Insert(key);
			return pair<const_iterator, bool>(ret.first, ret.second);
		}
	private:
		hash_bucket::HashTable<K, K, SetKeyOfT> _ht;
	};
}
#pragma once
#include<vector>

template<class K>
struct DefaultHashFunc
{
	size_t operator()(const K& key)
	{
		return (size_t)key;
	}
};

// 12:00
template<>
struct DefaultHashFunc<string>
{
	size_t operator()(const string& str)
	{
		// BKDR
		size_t hash = 0;
		for (auto ch : str)
		{
			hash *= 131;
			hash += ch;
		}

		return hash;
	}
};

namespace open_address
{
	enum STATE
	{
		EXIST,
		EMPTY,
		DELETE
	};

	template<class K, class V>
	struct HashData
	{
		pair<K, V> _kv;
		STATE _state = EMPTY;
	};

	template<class K, class V, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
	public:
		HashTable()
		{
			_table.resize(10);
		}

		bool Insert(const pair<K, V>& kv)
		{
			if (Find(kv.first))
			{
				return false;
			}

			// 扩容
			//if ((double)_n / (double)_table.size() >= 0.7)
			if (_n * 10 / _table.size() >= 7)
			{
				size_t newSize = _table.size() * 2;
				// 遍历旧表，重新映射到新表
				HashTable<K, V, HashFunc> newHT;
				newHT._table.resize(newSize);

				// 遍历旧表的数据插入到新表即可
				for (size_t i = 0; i < _table.size(); i++)
				{
					if (_table[i]._state == EXIST)
					{
						newHT.Insert(_table[i]._kv);
					}
				}

				_table.swap(newHT._table);
			}

			// 线性探测
			HashFunc hf;
			size_t hashi = hf(kv.first) % _table.size();
			while (_table[hashi]._state == EXIST)
			{
				++hashi;
				hashi %= _table.size();
			}

			_table[hashi]._kv = kv;
			_table[hashi]._state = EXIST;
			++_n;

			return true;
		}

		HashData<const K, V>* Find(const K& key)
		{
			// 线性探测
			HashFunc hf;
			size_t hashi = hf(key) % _table.size();
			while (_table[hashi]._state != EMPTY)
			{
				if (_table[hashi]._state == EXIST
					&& _table[hashi]._kv.first == key)
				{
					return (HashData<const K, V>*) & _table[hashi];
				}

				++hashi;
				hashi %= _table.size();
			}

			return nullptr;
		}

		// 按需编译
		bool Erase(const K& key)
		{
			HashData<const K, V>* ret = Find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;

				return true;
			}

			return false;
		}

	private:
		vector<HashData<K, V>> _table;
		size_t _n = 0; // 存储有效数据的个数
	};
}

// 泛型编程：不是针对某种具体类型，针对广泛的类型(两种及以上) -- 模板
namespace hash_bucket
{
	template<class T>
	struct HashNode
	{
		T _data;
		HashNode<T>* _next;

		HashNode(const T& data)
			:_data(data)
			, _next(nullptr)
		{}
	};

	// 前置声明
	template<class K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	template<class K, class T, class Ptr, class Ref, class KeyOfT, class HashFunc>
	struct HTIterator
	{
		typedef HashNode<T> Node;
		typedef HTIterator<K, T, Ptr, Ref, KeyOfT, HashFunc> Self;
		typedef HTIterator<K, T, T*, T&, KeyOfT, HashFunc> Iterator;

		Node* _node;
		const HashTable<K, T, KeyOfT, HashFunc>* _pht;

		/*HTIterator(Node* node, HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			,_pht(pht)
		{}*/

		HTIterator(Node* node, const HashTable<K, T, KeyOfT, HashFunc>* pht)
			:_node(node)
			, _pht(pht)
		{}

		// 普通迭代器时，他是拷贝构造
		// const迭代器时，他是构造
		HTIterator(const Iterator& it)
			:_node(it._node)
			, _pht(it._pht)
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		Self& operator++()
		{
			if (_node->_next)
			{
				// 当前桶还没完
				_node = _node->_next;
			}
			else
			{
				KeyOfT kot;
				HashFunc hf;
				size_t hashi = hf(kot(_node->_data)) % _pht->_table.size();
				// 从下一个位置查找查找下一个不为空的桶
				++hashi;
				while (hashi < _pht->_table.size())
				{
					if (_pht->_table[hashi])
					{
						_node = _pht->_table[hashi];
						return *this;
					}
					else
					{
						++hashi;
					}
				}

				_node = nullptr;
			}

			return *this;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

		bool operator==(const Self& s)
		{
			return _node == s._node;
		}
	};

	// 1、哈希表
	// 2、封装map和set
	// 3、普通迭代器
	// 4、const迭代器
	// 5、insert返回值  operator[]
	// 6、key不能修改的问题

	// 17:05
	// set -> hash_bucket::HashTable<K, K> _ht;
	// map -> hash_bucket::HashTable<K, pair<K, V>> _ht;
	template<class K, class T, class KeyOfT, class HashFunc = DefaultHashFunc<K>>
	class HashTable
	{
		typedef HashNode<T> Node;

		// 友元声明
		template<class K, class T, class Ptr, class Ref, class KeyOfT, class HashFunc>
		friend struct HTIterator;
	public:
		typedef HTIterator<K, T, T*, T&, KeyOfT, HashFunc> iterator;
		typedef HTIterator<K, T, const T*, const T&, KeyOfT, HashFunc> const_iterator;

		iterator begin()
		{
			// 找第一个桶
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return iterator(cur, this);
				}
			}

			return iterator(nullptr, this);
		}

		iterator end()
		{
			return iterator(nullptr, this);
		}

		const_iterator begin() const
		{
			// 找第一个桶
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				if (cur)
				{
					return const_iterator(cur, this);
				}
			}

			return const_iterator(nullptr, this);
		}

		const_iterator end() const
		{
			return const_iterator(nullptr, this);
		}

		size_t GetNextPrime(size_t prime)
		{
			static const int __stl_num_primes = 28;
			static const unsigned long __stl_prime_list[__stl_num_primes] =
			{
			  53,         97,         193,       389,       769,
			  1543,       3079,       6151,      12289,     24593,
			  49157,      98317,      196613,    393241,    786433,
			  1572869,    3145739,    6291469,   12582917,  25165843,
			  50331653,   100663319,  201326611, 402653189, 805306457,
			  1610612741, 3221225473, 4294967291
			};

			size_t i = 0;
			for (; i < PRIMECOUNT; ++i)
			{
				if (primeList[i] > prime)
					return primeList[i];
			}

			return primeList[i];
		}

		HashTable()
		{
			_table.resize(GetNextPrime(1), nullptr);
		}

		~HashTable()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}

				_table[i] = nullptr;
			}
		}

		pair<iterator, bool> Insert(const T& data)
		{
			KeyOfT kot;

			iterator it = Find(kot(data));
			if (it != end())
			{
				return make_pair(it, false);
			}

			HashFunc hf;

			// 负载因子到1就扩容
			if (_n == _table.size())
			{
				// 16:03继续
				//size_t newSize = _table.size() * 2;
				size_t newSize = GetNextPrime(_table.size());
				vector<Node*> newTable;
				newTable.resize(newSize, nullptr);

				// 遍历旧表，顺手牵羊，把节点牵下来挂到新表
				for (size_t i = 0; i < _table.size(); i++)
				{
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;

						// 头插到新表
						size_t hashi = hf(kot(cur->_data)) % newSize;
						cur->_next = newTable[hashi];
						newTable[hashi] = cur;

						cur = next;
					}

					_table[i] = nullptr;
				}

				_table.swap(newTable);
			}

			size_t hashi = hf(kot(data)) % _table.size();
			// 头插
			Node* newnode = new Node(data);
			newnode->_next = _table[hashi];
			_table[hashi] = newnode;
			++_n;
			return make_pair(iterator(newnode, this), true);
		}

		iterator Find(const K& key)
		{
			HashFunc hf;
			KeyOfT kot;
			size_t hashi = hf(key) % _table.size();
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					return iterator(cur, this);
				}

				cur = cur->_next;
			}

			return end();
		}

		bool Erase(const K& key)
		{
			HashFunc hf;
			KeyOfT kot;
			size_t hashi = hf(key) % _table.size();
			Node* prev = nullptr;
			Node* cur = _table[hashi];
			while (cur)
			{
				if (kot(cur->_data) == key)
				{
					if (prev == nullptr)
					{
						_table[hashi] = cur->_next;
					}
					else
					{
						prev->_next = cur->_next;
					}

					delete cur;
					return true;
				}

				prev = cur;
				cur = cur->_next;
			}

			--_n;
			return false;
		}

		void Print()
		{
			for (size_t i = 0; i < _table.size(); i++)
			{
				printf("[%d]->", i);
				Node* cur = _table[i];
				while (cur)
				{
					cout << cur->_kv.first << ":" << cur->_kv.second << "->";
					cur = cur->_next;
				}
				printf("NULL\n");
			}
			cout << endl;
		}

	private:
		vector<Node*> _table; // 指针数组
		size_t _n = 0; // 存储了多少个有效数据
	};
}