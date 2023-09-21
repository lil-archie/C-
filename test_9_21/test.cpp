#define  _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include<vector>

namespace bit
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_a.resize(N / 32 + 1);
		}

		// xӳ����Ǹ���ǳ�1
		void set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			_a[i] |= (1 << j);
		}

		// xӳ����Ǹ���ǳ�0
		void reset(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			_a[i] &= (~(1 << j));
		}

		bool test(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;

			return _a[i] & (1 << j);
		}
	private:
		vector<int> _a;
	};

	template<size_t N>
	class twobitset
	{
	public:
		void set(size_t x)
		{
			// 00 -> 01
			if (!_bs1.test(x) && !_bs2.test(x))
			{
				_bs2.set(x);
			} // 01 -> 10
			else if (!_bs1.test(x) && _bs2.test(x))
			{
				_bs1.set(x);
				_bs2.reset(x);
			}
			// ����10�������2�μ����ϣ��Ͳ�����
		}

		bool is_once(size_t x)
		{
			return !_bs1.test(x) && _bs2.test(x);
		}
	private:
		bitset<N> _bs1;
		bitset<N> _bs2;
	};
}


#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<set>
using namespace std;

//int main()
//{
//	// ȥ��
//	unordered_set<int> us;
//	size_t old = us.bucket_count();
//	cout << old << endl;
//	for (size_t i = 0; i < 10000; i++)
//	{
//		us.insert(i);
//
//		if (old != us.bucket_count())
//		{
//			old = us.bucket_count();
//			cout << old << endl;
//		}
//	}
//
//	/*unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;*/
//
//	/*unordered_map<string, string> dict;
//	dict["sort"] = "����";
//	dict["insert"] = "����";
//	dict["string"] = "�ַ���";
//	dict["left"];
//
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//	cout << endl;*/
//
//
//
//
//	return 0;
//}

//int main()
//{
//	const size_t N = 100000;
//
//	unordered_set<int> us;
//	set<int> s;
//
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//	for (size_t i = 0; i < N; ++i)
//	{
//		v.push_back(rand());
//		//v.push_back(rand()+i);
//		//v.push_back(i);
//	}
//
//	// 21:15
//	size_t begin1 = clock();
//	for (auto e : v)
//	{
//		s.insert(e);
//	}
//	size_t end1 = clock();
//	cout << "set insert:" << end1 - begin1 << endl;
//
//	size_t begin2 = clock();
//	for (auto e : v)
//	{
//		us.insert(e);
//	}
//	size_t end2 = clock();
//	cout << "unordered_set insert:" << end2 - begin2 << endl;
//
//
//	size_t begin3 = clock();
//	for (auto e : v)
//	{
//		s.find(e);
//	}
//	size_t end3 = clock();
//	cout << "set find:" << end3 - begin3 << endl;
//
//	size_t begin4 = clock();
//	for (auto e : v)
//	{
//		us.find(e);
//	}
//	size_t end4 = clock();
//	cout << "unordered_set find:" << end4 - begin4 << endl << endl;
//
//	cout <<"�������ݸ�����"<< s.size() << endl;
//	cout <<"�������ݸ�����" << us.size() << endl << endl;;
//
//	size_t begin5 = clock();
//	for (auto e : v)
//	{
//		s.erase(e);
//	}
//	size_t end5 = clock();
//	cout << "set erase:" << end5 - begin5 << endl;
//
//	size_t begin6 = clock();
//	for (auto e : v)
//	{
//		us.erase(e);
//	}
//	size_t end6 = clock();
//	cout << "unordered_set erase:" << end6 - begin6 << endl << endl;
//	
//	return 0;
//}

#include"HashTable.h"

//int main()
//{
//	open_address::HashTable<int, int> ht;
//	int a[] = { 1,111,4,7,15,25,44,9 };
//	for (auto e : a)
//	{
//		ht.Insert(make_pair(e, e));
//	}
//
//	ht.Erase(15);
//
//	auto ret = ht.Find(4);
//	//ret->_kv.first = 41;
//	ret->_kv.second = 400;
//
//	//HashTable<string, string, StringHashFunc> dict;
//	open_address::HashTable<string, string> dict;
//	dict.Insert(make_pair("sort", "����"));
//	dict.Insert(make_pair("left", "xxx"));
//	auto dret = dict.Find("left");
//	//dret->_kv.first = "xx";
//	dret->_kv.second = "���";
//
//	string s1("xxx");
//	string s2("xxx");
//
//
//	open_address::DefaultHashFunc<string> hf;
//	cout << hf(s1) << endl;
//	cout << hf(s2) << endl;
//	cout << hf("bacd") << endl;
//	cout << hf("abcd") << endl;
//	cout << hf("abbe") << endl;
//	cout << hf("https://www.baidu.com/s?ie=utf-8&f=8&rsv_bp=1&rsv_idx=1&tn=65081411_1_oem_dg&wd=STATE&fenlei=256&rsv_pq=0xdd48647300054f47&rsv_t=1cd5rO%2BE6TJzo6qf9QKcibznhQ9J3lFwGEzmkc0Goazr3HuQSIIc2zD78Pt0&rqlang=en&rsv_enter=1&rsv_dl=tb&rsv_sug3=2&rsv_n=2&rsv_sug1=1&rsv_sug7=100&rsv_sug2=0&rsv_btype=i&prefixsug=STAT%2526gt%253B&rsp=5&inputT=656&rsv_sug4=796") << endl;
//
//	return 0;
//}

//int main()
//{
//	hash_bucket::HashTable<int, int> ht;
//	int a[] = { 1,111,4,7,15,25,44,9 };
//	for (auto e : a)
//	{
//		ht.Insert(make_pair(e, e));
//	}
//	ht.Print();
//
//	ht.Insert(make_pair(14, 14));
//	ht.Print();
//
//	ht.Insert(make_pair(24, 24));
//	ht.Print();
//
//	ht.Insert(make_pair(34, 34));
//	ht.Print();
//
//	ht.Erase(44);
//	ht.Erase(4);
//	ht.Erase(24);
//	ht.Print();
//
//	hash_bucket::HashTable<string, string> dict;
//	dict.Insert(make_pair("sort", "����"));
//	dict.Insert(make_pair("left", "xxx"));
//	dict.Insert(make_pair("insert", "����"));
//	dict.Insert(make_pair("string", "�ַ���"));
//	dict.Insert(make_pair("bucket", "Ͱ"));
//
//	auto dret = dict.Find("left");
//	//dret->_kv.first = "xx";
//	dret->_kv.second = "���";
//	dict.Print();
//
//	return 0;
//}

#include"UnOrderedSet.h"
#include"UnOrderedMap.h"

//int main()
//{
//	bit::unordered_set<int> us;
//	us.insert(3);
//	us.insert(1);
//	us.insert(3);
//	us.insert(4);
//	us.insert(5);
//	us.insert(0);
//
//	bit::unordered_set<int>::iterator it = us.begin();
//	while (it != us.end())
//	{
//		// �����޸�key
//		//*it += 10;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	bit::unordered_map<string, string> dict;
//	dict.insert(make_pair("sort", "����"));
//	dict.insert(make_pair("left", "���"));
//	dict.insert(make_pair("insert", "����"));
//	dict.insert(make_pair("sort", "xxx"));
//
//	bit::unordered_map<string, string>::iterator dit = dict.begin();
//	while (dit != dict.end())
//	{
//		// �����޸�key
//		//dit->first += 'x';
//		dit->second += 'x';
//
//		cout << dit->first << ":" << dit->second << endl;
//
//
//		++dit;
//	}
//	cout << endl;
//
//	dict["sort"] = "����";
//	dict["insert"] = "����";
//	dict["string"] = "�ַ���";
//	dict["right"];
//
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	int x = 1;
//	return 0;
//}

#include"BitSet.h"

//int main()
//{
//	bit::bitset<1000> bs;
//	bs.set(1);
//	bs.set(10);
//	bs.set(100);
//
//	cout << bs.test(1) << endl;
//	cout << bs.test(10) << endl;
//	cout << bs.test(100) << endl;
//	cout << bs.test(999) << endl<<endl;
//
//	bs.set(999);
//	bs.reset(10);
//
//	cout << bs.test(1) << endl;
//	cout << bs.test(10) << endl;
//	cout << bs.test(100) << endl;
//	cout << bs.test(999) << endl << endl;
//
//	getchar();
//
//	bit::bitset<-1> bs1;
//	//bit::bitset<0xffffffff> bs2;
//
//	getchar();
//
//	return 0;
//}

//int main()
//{
//	int a[] = { 1,2,3,3,4,4,4,4,4,2,3,6,3,1,5,5,8,9};
//	bit::twobitset<10> tbs;
//	for (auto e : a)
//	{
//		tbs.set(e);
//	}
//
//	for (auto e : a)
//	{
//		if (tbs.is_once(e))
//		{
//			cout << e << " ";
//		}
//	}
//	cout << endl;
//}

int main()
{
	int a1[] = { 1,2,3,3,4,4,4,4,4,2,3,6,3,1,5,5,8,9 };
	int a2[] = { 8,4,8,4,1,1,1,1 };

	bit::bitset<10> bs1;
	bit::bitset<10> bs2;

	// ȥ��
	for (auto e : a1)
	{
		bs1.set(e);
	}

	// ȥ��
	for (auto e : a2)
	{
		bs2.set(e);
	}

	// 9��03����
	for (int i = 0; i < 10; i++)
	{
		if (bs1.test(i) && bs2.test(i))
		{
			cout << i << " ";
		}
	}
	cout << endl;
}