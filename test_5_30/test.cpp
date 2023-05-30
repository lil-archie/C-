#define  _CRT_SECURE_NO_WARNINGS 1

// prim 算法求最小生成树 

//#include <cstdio>
//#include <string>
//#include <cstring>
//#include <iostream>
//#include <algorithm>
//
//#define INF 0x3f3f3f3f
//
//using namespace std;
//
//const int maxn = 505;
//
//int a[maxn][maxn];
//
//int vis[maxn], dist[maxn];
//
//int n, m;
//
//int u, v, w;
//
//long long sum = 0;
//
//int prim(int pos) {
//	dist[pos] = 0;
//	// 一共有 n 个点,就需要 遍历 n 次,每次寻找一个权值最小的点,记录其下标
//	for (int i = 1; i <= n; i++) {
//		int cur = -1;
//		for (int j = 1; j <= n; j++) {
//			if (!vis[j] && (cur == -1 || dist[j] < dist[cur])) {
//				cur = j;
//			}
//		}
//		// 这里需要提前终止
//		if (dist[cur] >= INF) return INF;
//		sum += dist[cur];
//		vis[cur] = 1;
//		for (int k = 1; k <= n; k++) {
//			// 只更新还没有找到的最小权值
//			if (!vis[k]) dist[k] = min(dist[k], a[cur][k]);
//		}
//	}
//	return sum;
//}
//
//int main(void) {
//	scanf("%d%d", &n, &m);
//	memset(a, 0x3f, sizeof(a));
//	memset(dist, 0x3f, sizeof(dist));
//	for (int i = 1; i <= m; i++) {
//		scanf("%d%d%d", &u, &v, &w);
//		a[u][v] = min(a[u][v], w);
//		a[v][u] = min(a[v][u], w);
//	}
//	int value = prim(1);
//	if (value >= INF) puts("impossible");
//	else printf("%lld\n", sum);
//	return 0;
//}


////数组储存未选集合，每次选到未选集合的最短距离都要遍历数组一遍，有瑕疵
//#include<iostream>
//#include<vector>//使用向量容器，装相邻节点
//using namespace std;
//#define max_size 20
//#define inf 10000 //表示无穷大
//typedef struct
//{
//    int parent;
//    int node;//节点序号
//    int value;//从已选节点到该节点的距离（权值）
//    int flag;//该节点是否被选，1 已选，0 未选
//}node;
//typedef struct
//{
//    int node1;
//    int node2;
//    int value;
//}edge;
//vector<int> neighbor[max_size];//装相邻节点
//vector<int> value[max_size];//装到相邻节点的权值
//int j = 0;//用于mst数组下标
//
//void Prim(node a[], edge b[], int n, int v)
//{
//    a[v].flag = 1;
//    int i;
//    for (i = 0; i < neighbor[v].size(); i++)//更新到相未选点的距离
//    {
//        if (value[v][i] < a[neighbor[v][i]].value && a[neighbor[v][i]].flag == 0)
//        {
//            a[neighbor[v][i]].value = value[v][i];
//            a[neighbor[v][i]].parent = v;
//        }
//    }
//    int min_value = inf, p = 0;
//    for (i = 1; i <= n; i++)//找小距离，并选取
//    {
//        if (min_value > a[i].value && a[i].flag == 0)//找到到未选节点的最小距离
//        {
//            min_value = a[i].value;
//            p = i;//记下所选下标
//        }
//    }
//    if (p == 0);//没选取到最小距离，说明所有点都为已选集合，即最小生成树已完成
//    else
//    {
//        b[j].node1 = a[p].parent;
//        b[j].node2 = p;
//        b[j].value = min_value;
//        j++;
//        Prim(a, b, n, p);
//    }
//}
//int main()
//{
//    node arr[max_size];
//    int n, m;
//    cin >> n >> m;//输入节点数 n，边数 m
//    for (int i = 1; i <= n; i++)//初始化节点
//    {
//        arr[i].flag = 0;//初始化为未选
//        arr[i].value = inf;//初始化 从已选节点到该节点的距离为无穷大
//    }
//    int a, b, c;
//    for (int i = 0; i < m; i++)//输入初始图
//    {
//        cin >> a >> b >> c;//a b为边的节点，c为权值
//        neighbor[a].push_back(b);//把b装入a的邻居
//        value[a].push_back(c);//把对应权值装入  a的第i个邻居，对应第i个value值
//        neighbor[b].push_back(a);
//        value[b].push_back(c);
//    }
//    edge mst[max_size];//用于装最小生成树
//    Prim(arr, mst, n, 1);//1号节点开始
//    for (int i = 0; i < n - 1; i++)
//    {
//        cout << mst[i].node1 << ' ' << mst[i].node2 << ' ' << mst[i].value << endl;
//    }
//    return 0;
//}


//字符串的相加

//class Solution {
//public:
//    string addStrings(string num1, string num2) {
//        int end1 = num1.size() - 1;
//        int end2 = num2.size() - 1;
//        int carry = 0;
//        string strRet;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int val1 = end1 >= 0 ? num1[end1] - '0' : 0;
//            int val2 = end2 >= 0 ? num2[end2] - '0' : 0;
//            int ret = val1 + val2 + carry;
//            carry = ret / 10;
//            ret %= 10;
//
//            strRet += (ret + '0');
//
//            end1--;
//            end2--;
//        }
//        if (carry == 1)
//        {
//            strRet += '1';
//        }
//
//        reverse(strRet.begin(), strRet.end());
//
//        return strRet;
//    }
//};


