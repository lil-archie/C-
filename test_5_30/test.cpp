#define  _CRT_SECURE_NO_WARNINGS 1

// prim �㷨����С������ 

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
//	// һ���� n ����,����Ҫ ���� n ��,ÿ��Ѱ��һ��Ȩֵ��С�ĵ�,��¼���±�
//	for (int i = 1; i <= n; i++) {
//		int cur = -1;
//		for (int j = 1; j <= n; j++) {
//			if (!vis[j] && (cur == -1 || dist[j] < dist[cur])) {
//				cur = j;
//			}
//		}
//		// ������Ҫ��ǰ��ֹ
//		if (dist[cur] >= INF) return INF;
//		sum += dist[cur];
//		vis[cur] = 1;
//		for (int k = 1; k <= n; k++) {
//			// ֻ���»�û���ҵ�����СȨֵ
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


////���鴢��δѡ���ϣ�ÿ��ѡ��δѡ���ϵ���̾��붼Ҫ��������һ�飬��覴�
//#include<iostream>
//#include<vector>//ʹ������������װ���ڽڵ�
//using namespace std;
//#define max_size 20
//#define inf 10000 //��ʾ�����
//typedef struct
//{
//    int parent;
//    int node;//�ڵ����
//    int value;//����ѡ�ڵ㵽�ýڵ�ľ��루Ȩֵ��
//    int flag;//�ýڵ��Ƿ�ѡ��1 ��ѡ��0 δѡ
//}node;
//typedef struct
//{
//    int node1;
//    int node2;
//    int value;
//}edge;
//vector<int> neighbor[max_size];//װ���ڽڵ�
//vector<int> value[max_size];//װ�����ڽڵ��Ȩֵ
//int j = 0;//����mst�����±�
//
//void Prim(node a[], edge b[], int n, int v)
//{
//    a[v].flag = 1;
//    int i;
//    for (i = 0; i < neighbor[v].size(); i++)//���µ���δѡ��ľ���
//    {
//        if (value[v][i] < a[neighbor[v][i]].value && a[neighbor[v][i]].flag == 0)
//        {
//            a[neighbor[v][i]].value = value[v][i];
//            a[neighbor[v][i]].parent = v;
//        }
//    }
//    int min_value = inf, p = 0;
//    for (i = 1; i <= n; i++)//��С���룬��ѡȡ
//    {
//        if (min_value > a[i].value && a[i].flag == 0)//�ҵ���δѡ�ڵ����С����
//        {
//            min_value = a[i].value;
//            p = i;//������ѡ�±�
//        }
//    }
//    if (p == 0);//ûѡȡ����С���룬˵�����е㶼Ϊ��ѡ���ϣ�����С�����������
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
//    cin >> n >> m;//����ڵ��� n������ m
//    for (int i = 1; i <= n; i++)//��ʼ���ڵ�
//    {
//        arr[i].flag = 0;//��ʼ��Ϊδѡ
//        arr[i].value = inf;//��ʼ�� ����ѡ�ڵ㵽�ýڵ�ľ���Ϊ�����
//    }
//    int a, b, c;
//    for (int i = 0; i < m; i++)//�����ʼͼ
//    {
//        cin >> a >> b >> c;//a bΪ�ߵĽڵ㣬cΪȨֵ
//        neighbor[a].push_back(b);//��bװ��a���ھ�
//        value[a].push_back(c);//�Ѷ�ӦȨֵװ��  a�ĵ�i���ھӣ���Ӧ��i��valueֵ
//        neighbor[b].push_back(a);
//        value[b].push_back(c);
//    }
//    edge mst[max_size];//����װ��С������
//    Prim(arr, mst, n, 1);//1�Žڵ㿪ʼ
//    for (int i = 0; i < n - 1; i++)
//    {
//        cout << mst[i].node1 << ' ' << mst[i].node2 << ' ' << mst[i].value << endl;
//    }
//    return 0;
//}


//�ַ��������

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


