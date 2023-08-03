#define  _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;

int Add(int left, int right)
{
    return left + right;
}

// ͨ�üӷ�����
template<class T>
T Add(T left, T right)
{
    return left + right;
}

template<class T>
T* func(int n)
{
    return new T[n];
}

//int main()
//{
//	int x = 0, y = 1;
//	swap(x, y);
//
//	double a = 1.1, b = 2.2;
//	swap(a, b);
//
//	cout << Add(x, y) << endl;
//
//	cout << Add<int>(x, y) << endl;
//
//	int* ptr = func<int>(10);
//
//	return 0;
//}

template<class T>
class Vector
{
public:
    Vector(size_t capacity = 10)
        : _pData(new T[capacity])
        , _size(0)
        , _capacity(capacity)
    {}

    // ʹ������������ʾ�������������������ⶨ�塣
    ~Vector();

    void PushBack(const T& data);
    void PopBack();
    // ...

    size_t Size() { return _size; }

    T& operator[](size_t pos)
    {
        //assert(pos < _size);
        return _pData[pos];
    }

private:
    T* _pData;
    size_t _size;
    size_t _capacity;
};

template<class T>
Vector<T>::~Vector()
{
    delete[] _pData;
    _pData = nullptr;
}

// ���� �� Vector
// ���� �� Vector<T>

//int main()
//{
//    //Vector<int> v;
//
//    vector<int> v;
//    v.push_back(1);
//    v.push_back(1);
//    v.push_back(1);
//    v.push_back(1);
//    v.reserve(100);
//
//    list<int> lt;
//    lt.push_back(1);
//
//
//
//    return 0;
//}

void test_string1()
{
    string s1;
    string s2("hello");

    cin >> s1;
    cout << s1 << endl;
    cout << s2 << endl;

    //cin >> s2;
    //cout << s2 << endl;

    //char str[1600];
    //scanf

    // strcat
    string ret1 = s1 + s1;
    cout << ret1 << endl;

    string ret2 = s1 + "������";
    cout << ret2 << endl;
}

void test_string2()
{
    string s1("hello world");
    string s2 = "hello world";

    // ����string
    for (size_t i = 0; i < s1.size(); i++)
    {
        // ��
        cout << s1[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < s1.size(); i++)
    {
        // д
        s1[i]++;
    }
    cout << s1 << endl;

    // ������
    string::iterator it = s1.begin();
    //while (it < s1.end())  // ������Ե��ǲ�����
    while (it != s1.end())  // �Ƽ��淨��ͨ��
    {
        // ��
        cout << *it << " ";
        ++it;
    }
    cout << endl;


    it = s1.begin();
    while (it != s1.end())
    {
        // д
        *it = 'a';
        ++it;
    }
    cout << endl;
    cout << s1 << endl;

    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    list<int>::iterator lit = lt.begin();
    while (lit != lt.end())
    {
        cout << *lit << " ";
        ++lit;
    }
    cout << endl;
}

void test_string3()
{
    string s1("hello world");
    string::iterator it = s1.begin();
    //while (it < s1.end())  // ������Ե��ǲ�����
    while (it != s1.end())  // �Ƽ��淨��ͨ��
    {
        // ��
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    //string::reverse_iterator rit = s1.rbegin();
    auto rit = s1.rbegin();
    while (rit != s1.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;

    // ԭ���������������滻�ɵ�����
    // ��
    for (auto ch : s1)
    {
        cout << ch << " ";
    }
    cout << endl;

    // д
    for (auto& ch : s1)
    {
        ch++;
    }
    cout << endl;

    cout << s1 << endl;
}

// 17:17����
void func(const string& s)
{
    //string::const_iterator it = s.begin();
    auto it = s.begin();
    while (it != s.end())
    {
        // ��֧��д
        // *it = 'a';

        // ��
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    //string::const_reverse_iterator rit = s.rbegin();
    auto rit = s.rbegin();
    while (rit != s.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
}

void test_string4()
{
    string s1("hello worldxxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyy");
    func(s1);

    string s2(s1);
    cout << s2 << endl;

    string s3(s1, 6, 5);
    cout << s3 << endl;

    string s4(s1, 6, 3);
    cout << s4 << endl;

    string s5(s1, 6);
    cout << s5 << endl;

    string s6(s1, 6, s1.size() - 6);
    cout << s6 << endl;

    string s7(10, 'a');
    cout << s7 << endl;

    string s8(++s7.begin(), --s7.end());
    cout << s8 << endl;

    s8 = s7;
    s8 = "xxx";
    s8 = 'y';
}

void test_string5()
{
    //string s1("hello worldxxxxxxxxxxxxxxxxxxxxxxxxxxyyyyyyyyyyyyyyyyyy");
    string s1("hello world");
    cout << s1.size() << endl;
    cout << s1.length() << endl;
    cout << s1.capacity() << endl;

    s1.clear();
    s1 += "����";
    cout << s1.size() << endl;
    cout << s1.capacity() << endl;
    //cout << s1.max_size() << endl;

    // mysql

    string filename;
    cin >> filename;
    // FILE* fout = fopen(filename.c_str(), "r");
}

//int main()
//{
//    test_string5();
//
//    return 0;
//}

/////////////////////////////////////////////////////////////////////////////////
#include<map>  // key/value
#include<set>  // key

void test_set1()
{
    // ����+ȥ��
    // ȥ��ԭ��һ��ֵ�Ѿ����ˣ����ǾͲ�����
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(5);
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(5);

    set<int>::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;

    auto pos = s.find(3);  // O(logN)
    //auto pos = find(s.begin(), s.end(), 3); // O(N)
    if (pos != s.end())
        s.erase(pos);

    s.erase(30);

    for (auto e : s)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main()
{
    test_set1();

    return 0;
}

