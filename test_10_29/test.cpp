#define  _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<unordered_set>
#include<unordered_map>
#include<set>
using namespace std;

//int main()
//{
//	// 去重
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
//	dict["sort"] = "排序";
//	dict["insert"] = "插入";
//	dict["string"] = "字符串";
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
//	cout <<"插入数据个数："<< s.size() << endl;
//	cout <<"插入数据个数：" << us.size() << endl << endl;;
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
//	dict.Insert(make_pair("sort", "排序"));
//	dict.Insert(make_pair("left", "xxx"));
//	auto dret = dict.Find("left");
//	//dret->_kv.first = "xx";
//	dret->_kv.second = "左边";
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
//	dict.Insert(make_pair("sort", "排序"));
//	dict.Insert(make_pair("left", "xxx"));
//	dict.Insert(make_pair("insert", "插入"));
//	dict.Insert(make_pair("string", "字符串"));
//	dict.Insert(make_pair("bucket", "桶"));
//
//	auto dret = dict.Find("left");
//	//dret->_kv.first = "xx";
//	dret->_kv.second = "左边";
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
//		// 不能修改key
//		//*it += 10;
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//
//	bit::unordered_map<string, string> dict;
//	dict.insert(make_pair("sort", "排序"));
//	dict.insert(make_pair("left", "左边"));
//	dict.insert(make_pair("insert", "插入"));
//	dict.insert(make_pair("sort", "xxx"));
//
//	bit::unordered_map<string, string>::iterator dit = dict.begin();
//	while (dit != dict.end())
//	{
//		// 不能修改key
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
//	dict["sort"] = "排序";
//	dict["insert"] = "插入";
//	dict["string"] = "字符串";
//	dict["right"];
//
//	for (auto& kv : dict)
//	{
//		cout << kv.first << ":" << kv.second << endl;
//	}
//
//	return 0;
//}


#pragma once
#include<vector>

namespace bit
{
	class bitset
	{
	public:
		// x映射的那个标记成1
		void set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;


		}

		// x映射的那个标记成0
		void reset(size_t x)
		{

		}

	private:
		vector<int> _a;
	};
}