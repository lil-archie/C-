#define  _CRT_SECURE_NO_WARNINGS 1

#include<vector>
#include<iostream>
using namespace std;



int main() {
      vector<int> v;
    
          int a[] = { 0,1,2,3,4,5,6 };
    
          vector<int> v1(a,a+sizeof(a)/sizeof(int));
          //vector<int> v1(10, 1);
      for (auto e : v1)
         {
             cout << e << " ";
        }
    
        
          return 0;
     }


#include<iostream>
#include<map>
#include<set>
using namespace std;

void test_set1()
{
	// ����+ȥ��
	set<int> s;
	s.insert(3);
	s.insert(5);
	s.insert(8);
	s.insert(7);

	if (s.find(5) != s.end())
	{
		cout << "�ҵ���" << endl;
	}

	if (s.count(5))
	{
		cout << "�ҵ���" << endl;
	}

	std::set<int> myset;
	std::set<int>::iterator itlow, itup;

	for (int i = 1; i < 10; i++)
		myset.insert(i * 10); // 10 20 30 40 50 60 70 80 90

	myset.insert(35);

	// ɾ��[30 60]
	//itlow = myset.lower_bound(30);                // >=     
	//itup = myset.upper_bound(60);                 // >


	//std::pair<std::set<int>::const_iterator, std::set<int>::const_iterator> ret;
	auto ret = myset.equal_range(30);
	itlow = ret.first;
	itup = ret.second;

	// [itlow, itup)
	cout << *itlow << endl;
	cout << *itup << endl;

	myset.erase(itlow, itup);                     // 10 20 70 80 90

	for (auto e : myset)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set2()
{
	// ����
	multiset<int> s;
	s.insert(3);
	s.insert(5);
	s.insert(8);
	s.insert(7);
	s.insert(7);
	s.insert(9);
	s.insert(7);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// ���������һ��7
	auto pos = s.find(7);
	while (pos != s.end())
	{
		//*pos = 10;
		cout << *pos << " ";
		++pos;
	}
	cout << endl;

	cout << s.count(7) << endl;

	auto ret = s.equal_range(6);
	auto itlow = ret.first;
	auto itup = ret.second;

	// [itlow, itup)
	// [7,7)
	cout << *itlow << endl;
	cout << *itup << endl;

	s.erase(itlow, itup);                     // 10 20 70 80 90

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

class A
{
public:
	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{}
private:
	int _a1;
	int _a2;
};

void test_map1()
{
	map<string, string> dict;

	pair<string, string> kv1("insert", "����");
	dict.insert(kv1);
	dict.insert(pair<string, string>("sort", "����"));

	// C++98
	dict.insert(make_pair("string", "�ַ���"));

	// C++11 ������Ĺ��캯����ʽ����ת��
	dict.insert({ "string", "�ַ���" });

	// ��ʽ���͵�ת��
	string str1 = "hello";
	A aa1 = { 1, 2 };
	pair<string, string> kv2 = { "string", "�ַ���" };
}

void test_map2()
{
	map<string, string> dict;
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("insert", "����"));

	// �����룬�����ǣ���������У�ֻ�Ƚ�key��value����ͬ����ν
	// key�Ѿ����˾Ͳ�������
	dict.insert(make_pair("insert", "xxxx"));

	// 10��37
	//map<string, string>::iterator it = dict.begin();
	auto it = dict.begin();
	while (it != dict.end())
	{
		//it->first = "xxx";
		//it->second = "xxx";

		//cout << (*it).first << ":" << (*it).second << endl;
		cout << it->first << ":" << it->second << endl;

		++it;
	}
	cout << endl;

	for (const auto& kv : dict)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

void test_map3()
{
	// ͳ�ƴ���
	string arr[] = { "����", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����", "ƻ��", "�㽶", "ƻ��", "�㽶" };
	map<string, int> countMap;
	//for (auto e : arr)
	//{
	//	auto it = countMap.find(e);
	//	if (it == countMap.end())
	//	{
	//		countMap.insert(make_pair(e, 1));
	//	}
	//	else
	//	{
	//		it->second++;
	//	}
	//}
	for (auto e : arr)
	{
		countMap[e]++;
	}

	for (const auto& kv : countMap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
}

void test_map4()
{
	map<string, string> dict;
	dict.insert(make_pair("string", "�ַ���"));
	dict.insert(make_pair("sort", "����"));
	dict.insert(make_pair("insert", "����"));

	cout << dict["sort"] << endl; // ���ҺͶ�
	dict["map"];                  // ����
	dict["map"] = "ӳ��,��ͼ";     // �޸�
	dict["insert"] = "xxx";       // �޸�
	dict["set"] = "����";         // ����+�޸�
}

int main()
{
	test_map4();

	return 0;
}