#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

#include<assert.h>

//int main()
//{
//	// һ�����������ж������
//	int a = 0;
//	int& b = a;
//	int& c = b;
//
//	// �����ڶ���ʱ�����ʼ��
//	//int& d;
//
//	// ����һ������һ��ʵ�壬�ٲ�����������ʵ��
//	int x = 10;
//	c = x; // x��ֵ����c��c������a/b�������
//
//	return 0;
//}

// 1������������  ������Ͳ�����
// 2������������  �����ٿ������Ч�ʣ��������/��������--ʲô������Ժ�ὲ��

//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//// int* preorderTraversal(struct TreeNode* root, int* returnSize)  -- c
//// int* preorderTraversal(struct TreeNode* root, int& returnSize)  -- cpp
//
//typedef struct ListNode
//{
//	int val;
//	struct ListNode* next; // c / cpp
//	//ListNode* next;          // cpp
//}*PNode;
//
//void LTPushBack(PNode& phead, int x);
//
//
//#include <time.h>
//struct A { int a[100000]; };
//
//void TestFunc1(A a) {}
//
//void TestFunc2(A& a) {}
//
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	TestRefAndValue();
//
//	return 0;
//}

// 3������������ֵ  �����ٿ������Ч�ʣ��������/��������--ʲô������Ժ�ὲ��
// 4������������ֵ   �޸ķ���ֵ+��ȡ����ֵ

// ��ֵ����
//int Count()
//{
//	static int n = 0;
//	n++;
//
//	// ...
//	return n;
//}
//
//int main()
//{
//	int ret = Count();
//
//	return 0;
//}

// �����÷���
//int& Count()
//{
//	static int n = 0;
//	n++;
//	// ...
//	return n;
//}
//
//int main()
//{
//	int ret = Count();
//
//	return 0;
//}

//#include <time.h>
//struct A { int a[10000]; };
//
//A a;
//// ֵ����
//A TestFunc1() { return a; }
//// ���÷���
//A& TestFunc2() { return a; }
//
//void TestReturnByRefOrValue()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//
//	// �������������������֮���ʱ��
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//
//int main()
//{
//	TestReturnByRefOrValue();
//
//	return 0;
//}

//int& Count()
//{
//	int n = 0;
//	n++;
//	// ...
//	return n;
//}
//
//int main()
//{
//	int ret = Count();
//	cout << ret << endl;
//
//	return 0;
//}


//int& Count(int x)
//{
//	int n = x;
//	n++;
//	// ...
//	return n;
//}
//
//int main()
//{
//	int& ret = Count(10);
//	cout << ret << endl;
//
//	Count(20);
//	cout << ret << endl;
//
//	return 0;
//}

// ��������������������
int& Count(int x)
{
	int n = x;
	n++;
	// ...
	return n;
}

// ��ȷ����������������
//int& Count(int x)
//{
//	static int n = x;
//	n++;
//	// ...
//	return n;
//}

//struct SeqList
//{
//	int a[100];
//	size_t size;
//};
//
//int SLGet(SeqList* ps, int pos)
//{
//	assert(pos < 100 && pos >= 0);
//
//	return ps->a[pos];
//}
//
//void SLModify(SeqList* ps, int pos, int x)
//{
//	assert(pos < 100 && pos >= 0);
//
//	ps->a[pos] = x;
//}
//
//int& SLAt(SeqList& s, int pos)
//{
//	assert(pos < 100 && pos >= 0);
//
//	return s.a[pos];
//}
//
//int main()
//{
//	//int& ret = Count(10);
//	//cout << ret << endl;
//
//	////printf("sssssssssssssssssssssssss\n");
//	//rand();
//	//cout << ret << endl;
//
//	SeqList s;
//	SLModify(&s, 0, 1);
//	cout << SLGet(&s, 0) << endl;
//
//	// �Ե�0��λ��ֵ+5
//	int ret1 = SLGet(&s, 0);
//	SLModify(&s, 0, ret1+5);
//
//	SLAt(s, 0) = 1;
//	cout << SLAt(s, 0) << endl;
//	SLAt(s, 0) += 5;
//
//	return 0;
//}


///////////////////////////////////////////////////////////////


struct SeqList
{
	int a[100];
	size_t size;

	int& at(int pos)
	{
		assert(pos >= 0 && pos < 100);
		return a[pos];
	}

	int& operator[](int pos)
	{
		assert(pos >= 0 && pos < 100);
		return a[pos];
	}
};

// 20:46����
//int main()
//{
//	SeqList s;
//	s.at(0) = 0;
//	s.at(0)++;
//	cout << s.at(0) << endl;
//
//	s[1] = 10;
//	s[1]++;
//	cout << s[1] << endl;
//
//	/*vector<int> v;
//	for (int i = 0; i < v.size(); ++i)
//	{
//		v[i]++;
//	}*/
//
//	return 0;
//}

//int main()
//{
//	// ������
//	// ���ù����У�Ȩ�޲��ܷŴ�
//	const int a = 0;
//	//int& b = a;
//
//	// ���ԣ�c������d��û�зŴ�Ȩ�ޣ���Ϊd�ĸı䲻Ӱ��c
//	const int c = 0;
//	int d = c;
//
//	// ������
//	// ���ù����У�Ȩ�޿���ƽ�ƻ�����С
//	int x = 0;
//	int& y = x;
//	const int& z = x;
//	++x;
//	//++z;
//
//	const int& m = 10;
//
//	double dd = 1.11;
//	int ii = dd;
//
//	const int& rii = dd;
//
//	return 0;
//}

//int func1()
//{
//	static int x = 0;
//	return x;
//}
//
//int& func2()
//{
//	static int x = 0;
//	return x;
//}
//
//int main()
//{
//	// int& ret1 = func1();  // Ȩ�޷Ŵ�
//	//const int& ret1 = func1(); // Ȩ��ƽ��
//	// int ret1 = func1();  // ����
//
//	int& ret2 = func2();		// Ȩ��ƽ��
//	const int& rret2 = func2();  // Ȩ����С
//
//	return 0;
//}

//int main()
//{
//	int i = 1;
//	double j = 1.1;
//	if (j > i)
//	{
//		cout << "xxxxx" << endl;
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//
//	// �﷨���棺�����ռ䣬�Ƕ�aȡ����
//	int& ra = a;
//	ra = 20;
//
//	// �﷨���棺���ռ䣬�洢a�ĵ�ַ
//	int* pa = &a;
//	*pa = 30;
//
//	return 0;
//}


/////////////////////////////////////////////////////////////////////////
// C++11
#include<map>
#include<string>
#include<vector>

//int main()
//{
//	int a = 0;
//	int b = a;
//	auto c = a; // �����ұߵı���ʽ�Զ��Ƶ�c������
//	auto d = 1 + 1.11; // �����ұߵı���ʽ�Զ��Ƶ�d������
//	cout << typeid(c).name() << endl;
//	cout << typeid(d).name() << endl;
//
//	vector<int> v;
//
//	// ���ͺܳ�
//	//vector<int>::iterator it = v.begin();
//	// �ȼ���
//	auto it = v.begin();
//
//	std::map<std::string, std::string> dict;
//	//std::map<std::string, std::string>::iterator dit = dict.begin();
//	// �ȼ���
//	auto dit = dict.begin();
//
//	return 0;
//}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < sizeof(arr) / sizeof(int); ++i)
		arr[i] *= 2;

	for (int* p = arr; p < arr + sizeof(arr) / sizeof(arr[0]); ++p)
		cout << *p << " ";
	cout << endl;

	// ����������
	// ��Χfor �﷨��
	// ����ȡ���������ݸ�ֵ��e
	// �Զ��������Զ��жϽ���
	// for (int x : arr)
	for (auto x : arr)
	{
		cout << x << " ";
	}
	cout << endl;

	// �޸�����
	for (auto& e : arr)
	{
		e *= 2;
	}

	for (auto e : arr)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}