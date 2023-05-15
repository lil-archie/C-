#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

typedef char VertexType; //������������
typedef int EdgeType; //�ߵ�Ȩ����������
#define MAXVEX (100)  //��󶥵���
#define INFINITY (65535) //2^16 - 1

typedef struct MGraph
{
    VertexType vexs[MAXVEX];  //�����
    EdgeType arc[MAXVEX][MAXVEX]; //�ڽӾ���
    int numVertexes, numEdges;  //�������ͱ���
}MGraph;


/**********************************************************\
*function: ����ͼ���ڽӾ���ṹ
*input: GraphAdjList *G
*output: none
*return: void
\**********************************************************/
void CreateMgraph(MGraph* G)
{
    int i, j, k, w;
    char ch;
    printf("���붥�����ͱ�����\n");
    scanf(" %d,%d", &G->numVertexes, &G->numEdges);

    for (i = 0; i < G->numVertexes; i++)
    {
        printf("���붥��%d��Ϣ��\n", i);
        scanf(" %c", &(G->vexs[i]));
    }

    for (i = 0; i < G->numVertexes; i++)
    {
        for (j = 0; j < G->numVertexes; j++)
        {
            if (i != j)
            {
                G->arc[i][j] = INFINITY;
            }
            else
            {
                G->arc[i][j] = 0; //�������Խ�����Ϊ0
            }
        }
    }

    for (k = 0; k < G->numEdges; k++)
    {
        printf("ѡ��߻�(0 ? 1): ");
        scanf(" %d", &ch);
        if (0 == ch)
        {
            printf("�����(vi,vj)�ϵ��±�i���±�j��Ȩw��\n");
            scanf(" %d, %d, %d", &i, &j, &w);
            G->arc[i][j] = w;
            G->arc[j][i] = G->arc[i][j];
        }
        else
        {
            printf("���뻡(vi,vj)�ϵ��±�i���±�j��Ȩw��\n");
            scanf(" %d, %d, %d", &i, &j, &w);
            G->arc[i][j] = w;
        }
    }
}


void MinSpanTree_Prim(MGraph G)
{
    int min, i, j, k;
    int adjvex[MAXVEX]; //���������ӽ�����丸���Ķ�Ӧ��ϵ��MAXVEXΪ���Ķ�������
    int lowcost[MAXVEX]; //ͼ�и������������������ֱ�Ӿ���
    lowcost[0] = 0; //V0����������
    adjvex[0] = 0; //��һ�������±�Ϊ0

    for (i = 1; i < G.numVertexes; i++)
    {
        lowcost[i] = G.arc[0][i]; //��V0������֮�бߵ�Ȩֵ��������
        adjvex[i] = 0; //��ʼ����ΪV0���±�
    }

    for (i = 1; i < G.numVertexes; i++) //�������������G.numVertexes-1�ζ���
    {
        min = INFINITY; //��ʼ����СȨֵΪ�����

        j = 1;
        k = 0;

        while (j < G.numVertexes) //ѭ��ȫ������
        {
            if (lowcost[j] != 0 && lowcost[j] < min) //Ȩֵ��Ϊ0��ȨֵС��min
            {
                min = lowcost[j]; //���õ�ǰȨֵ��Ϊ��Сֵ
                k = j; //����ǰ��Сֵ���±����k
            }
            j++;
        }

        printf(" (%d, %d) ", adjvex[k], k); //��ӡ��ǰ�������Ȩֵ��С��
        lowcost[k] = 0; //����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ��������

        for (j = 1; j < G.numVertexes; j++)
        {
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) //���±�Ϊk�����ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ
            {
                lowcost[j] = G.arc[k][j]; //����СȨֵ����lowcost
                adjvex[j] = k; //���±�Ϊk�Ķ������adjvex
            }
        }
    }
}





int main()
{
    MGraph G;
    CreateMgraph(&G);
    MinSpanTree_Prim(G);

    return 0;
}
\


#include<iostream>
#include<string>
using namespace std;

class Time
{
    friend class Date;   // ����������Ϊʱ�������Ԫ�࣬�����������о�ֱ�ӷ���Time���е�˽�г�Ա����

public:
    Time(int hour = 0, int minute = 0, int second = 0)
        : _hour(hour)
        , _minute(minute)
        , _second(second)
    {}

private:
    int _hour;
    int _minute;
    int _second;
};

class Date
{
public:
    Date(int year = 1900, int month = 1, int day = 1)
        : _year(year)
        , _month(month)
        , _day(day)
    {}

    void SetTimeOfDate(int hour, int minute, int second)
    {
        // ֱ�ӷ���ʱ����˽�еĳ�Ա����
        _t._hour = hour;
        _t._minute = minute;
        _t._second = second;
    }

private:
    int _year;
    int _month;
    int _day;
    Time _t;
};


//class A
//{
//private:
//    static int k;
//    int h;
////public:
//    class B
//    {
//    public:
//        void foo()
//        {
//
//        }
//    private:
//        int b;
//    };
//};
//
//int A::k = 1;
//
//int main()
//{
//    cout << sizeof(A) << endl;
//
//    A aa;
//    A::B bb;
//
//	return 0;
//}

//class A
//{
//private:
//    static int k;
//    int h;
//
//    class B  // �ڲ������ⲿ���������Ԫ
//    {
//    public:
//        void foo(const A& a)
//        {
//            cout << k << endl;//OK
//            cout << a.h << endl;//OK
//        }
//    private:
//        int b;
//    };
//};
//
//int A::k = 1;
//
//int main()
//{
//    cout << sizeof(A) << endl;
//
//    A aa;
//
//    return 0;
//}
//
//class A
//{
//public:
//    A(int a = 0)
//        :_a(a)
//    {
//        cout << "A(int a)" << endl;
//    }
//
//    ~A()
//    {
//        cout << "~A()" << endl;
//    }
//private:
//    int _a;
//};
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        cout << "Sum_Solution" << endl;
//        //...
//        return n;
//    }
//};


void push_back(const string& s)
{
    cout << "push_back:" << s << endl;
}

//int main()
//{
//    A aa(1);  // �������� -- ���������ڵ�ǰ�����ֲ���
//    A(2);     // �������� -- ���������ڵ�ǰ��
//
//    Solution sl;
//    sl.Sum_Solution(10);
//
//    Solution().Sum_Solution(20);
//
//    //A& ra = A(1);  // ����������г���
//    const A& ra = A(1); // const�����ӳ�����������������ڣ����������ڵ�ǰ�����ֲ���
//    A(10);
//
//    Solution().Sum_Solution(20);
//
//    string str("11111");
//    push_back(str);
//
//    push_back(string("222222"));
//
//    push_back("222222");
//
//    return 0;
//}

class A
{
public:
    A(int a = 0)
        :_a(a)
    {
        cout << "A(int a)" << endl;
    }

    A(const A& aa)
        :_a(aa._a)
    {
        cout << "A(const A& aa)" << endl;
    }

    A& operator=(const A& aa)
    {
        cout << "A& operator=(const A& aa)" << endl;

        if (this != &aa)
        {
            _a = aa._a;
        }

        return *this;
    }

    ~A()
    {
        cout << "~A()" << endl;
    }
private:
    int _a;
};

//void Func1(A aa)
//{
//
//}
//
//void Func2(const A& aa)
//{
//
//}
//
//A Func3()
//{
//    A aa;
//    return aa;
//}
//
//A& Func4()
//{
//    static A aa;
//    return aa;
//}
//
//int main()
//{
//   /* A a1;
//    Func1(a1);
//    Func2(a1);*/
//
//    //Func3();
//    Func4();
//
//
//    return 0;
//}

void Func1(A aa)
{}

A Func5()
{
    A aa;
    return aa;
}

// 20:25
//int main()
//{
//    A ra1 = Func5(); // ��������+�������� ->�Ż�Ϊ��������
//    cout << "==============" << endl;
//    A ra2;
//    ra2 = Func5();
//
//    //A aa1;
//    //Func1(aa1); // �����Ż�
//
//    //Func1(A(1)); // ����+�������� ->�Ż�Ϊ����
//    //Func1(1);    // ����+�������� ->�Ż�Ϊ����
//
//    //A aa2 = 1;  // ����+�������� ->�Ż�Ϊ����
//
//
//    return 0;
//}

//int main()
//{
//    int a = 1;
//    const int b = 2;
//    cout << &a << endl;
//    cout << &b << endl;
//
//
//    return 0;
//}

//int main()
//{
//    // C
//    int* p1 = (int*)malloc(sizeof(int));
//    free(p1);
//
//    // CPP
//    int* p2 = new int;
//    delete p2;
//
//    // C
//    int* p3 = (int*)malloc(sizeof(int)*10);
//    free(p3);
//
//    // CPP ����10��int������
//    int* p4 = new int[10];
//    delete[] p4;
//
//    // CPP ����һ�����飬��ʼ��Ϊ10
//    int* p5 = new int(10);
//    delete p5;
//
//    int* p6 = new int[10]{1,2,3};
//    delete[] p6;
//
//    return 0;
//}

struct ListNode
{
    int _val;
    struct ListNode* _next;

    ListNode(int x)
        :_val(x)
        , _next(NULL)
    {}
};

struct ListNode* BuyListNode(int x)
{
    // �������ռ�
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    // ���
    newnode->_next = NULL;
    newnode->_val = x;

    return newnode;
}

int main()
{
    struct ListNode* n1 = BuyListNode(1);
    struct ListNode* n2 = BuyListNode(2);
    struct ListNode* n3 = BuyListNode(3);

    // ���ռ�+���ù��캯����ʼ��
    ListNode* nn1 = new ListNode(1);
    ListNode* nn2 = new ListNode(2);
    ListNode* nn3 = new ListNode(3);

    return 0;
}