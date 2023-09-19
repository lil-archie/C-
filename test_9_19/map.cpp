#define  _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include"HashTable.h"

namespace bit
{
	template<class K, class V>
	class unordered_map
	{
		struct MapKeyOfT
		{
			const K& operator()(const pair<const K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;

		iterator begin()
		{
			return _ht.begin();
		}

		iterator end()
		{
			return _ht.end();
		}

		const_iterator begin() const
		{
			return _ht.begin();
		}

		const_iterator end() const
		{
			return _ht.end();
		}

		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return _ht.Insert(kv);
		}

		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _ht.Insert(make_pair(key, V()));
			return ret.first->second;
		}
	private:
		hash_bucket::HashTable<K, pair<const K, V>, MapKeyOfT> _ht;
	};
}
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
