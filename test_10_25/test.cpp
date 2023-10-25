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

