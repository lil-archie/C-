#define  _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

typedef char VertexType; //顶点数据类型
typedef int EdgeType; //边的权重数据类型
#define MAXVEX (100)  //最大顶点数
#define INFINITY (65535) //2^16 - 1

typedef struct MGraph
{
    VertexType vexs[MAXVEX];  //顶点表
    EdgeType arc[MAXVEX][MAXVEX]; //邻接矩阵
    int numVertexes, numEdges;  //顶点数和边数
}MGraph;


/**********************************************************\
*function: 创建图的邻接矩阵结构
*input: GraphAdjList *G
*output: none
*return: void
\**********************************************************/
void CreateMgraph(MGraph* G)
{
    int i, j, k, w;
    char ch;
    printf("输入顶点数和边数：\n");
    scanf(" %d,%d", &G->numVertexes, &G->numEdges);

    for (i = 0; i < G->numVertexes; i++)
    {
        printf("输入顶点%d信息：\n", i);
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
                G->arc[i][j] = 0; //矩阵正对角线上为0
            }
        }
    }

    for (k = 0; k < G->numEdges; k++)
    {
        printf("选择边或弧(0 ? 1): ");
        scanf(" %d", &ch);
        if (0 == ch)
        {
            printf("输入边(vi,vj)上的下标i，下标j和权w：\n");
            scanf(" %d, %d, %d", &i, &j, &w);
            G->arc[i][j] = w;
            G->arc[j][i] = G->arc[i][j];
        }
        else
        {
            printf("输入弧(vi,vj)上的下标i，下标j和权w：\n");
            scanf(" %d, %d, %d", &i, &j, &w);
            G->arc[i][j] = w;
        }
    }
}


void MinSpanTree_Prim(MGraph G)
{
    int min, i, j, k;
    int adjvex[MAXVEX]; //生成树中子结点与其父结点的对应关系，MAXVEX为最大的顶点数量
    int lowcost[MAXVEX]; //图中各顶点与生成树的最短直接距离
    lowcost[0] = 0; //V0加入生成树
    adjvex[0] = 0; //第一个顶点下标为0

    for (i = 1; i < G.numVertexes; i++)
    {
        lowcost[i] = G.arc[0][i]; //将V0顶点与之有边的权值存入数组
        adjvex[i] = 0; //初始化都为V0的下标
    }

    for (i = 1; i < G.numVertexes; i++) //向生成树中添加G.numVertexes-1次顶点
    {
        min = INFINITY; //初始化最小权值为无穷大

        j = 1;
        k = 0;

        while (j < G.numVertexes) //循环全部顶点
        {
            if (lowcost[j] != 0 && lowcost[j] < min) //权值不为0且权值小于min
            {
                min = lowcost[j]; //则让当前权值成为最小值
                k = j; //将当前最小值的下标存入k
            }
            j++;
        }

        printf(" (%d, %d) ", adjvex[k], k); //打印当前顶点边中权值最小边
        lowcost[k] = 0; //将当前顶点的权值设置为0，表示此顶点已经完成任务

        for (j = 1; j < G.numVertexes; j++)
        {
            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) //若下标为k顶点各权值小于此前这些顶点未被加入生成树权值
            {
                lowcost[j] = G.arc[k][j]; //将较小权值存入lowcost
                adjvex[j] = k; //将下标为k的顶点存入adjvex
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
    friend class Date;   // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量

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
        // 直接访问时间类私有的成员变量
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
//    class B  // 内部类是外部类的天生友元
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
//    A aa(1);  // 有名对象 -- 生命周期在当前函数局部域
//    A(2);     // 匿名对象 -- 生命周期在当前行
//
//    Solution sl;
//    sl.Sum_Solution(10);
//
//    Solution().Sum_Solution(20);
//
//    //A& ra = A(1);  // 匿名对象具有常性
//    const A& ra = A(1); // const引用延长匿名对象的生命周期，生命周期在当前函数局部域
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
//    A ra1 = Func5(); // 拷贝构造+拷贝构造 ->优化为拷贝构造
//    cout << "==============" << endl;
//    A ra2;
//    ra2 = Func5();
//
//    //A aa1;
//    //Func1(aa1); // 不会优化
//
//    //Func1(A(1)); // 构造+拷贝构造 ->优化为构造
//    //Func1(1);    // 构造+拷贝构造 ->优化为构造
//
//    //A aa2 = 1;  // 构造+拷贝构造 ->优化为构造
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
//    // CPP 申请10个int的数组
//    int* p4 = new int[10];
//    delete[] p4;
//
//    // CPP 申请一个数组，初始化为10
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
    // 单纯开空间
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    // 检查
    newnode->_next = NULL;
    newnode->_val = x;

    return newnode;
}

int main()
{
    struct ListNode* n1 = BuyListNode(1);
    struct ListNode* n2 = BuyListNode(2);
    struct ListNode* n3 = BuyListNode(3);

    // 开空间+调用构造函数初始化
    ListNode* nn1 = new ListNode(1);
    ListNode* nn2 = new ListNode(2);
    ListNode* nn3 = new ListNode(3);

    return 0;
}