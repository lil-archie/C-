#define  _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//#include<string>
//#include<list>
//using namespace std;

//int main()
//{
//	string s1("hello");
//	cout << s1 << endl;
//
//	s1 += 'w';
//	cout << s1 << endl;
//
//	s1 += "world";
//
//	cout << s1 << endl;
//
//
//	string::iterator it = s1.begin();//������
//
//	while (it != s1.end())
//	{
//		cout << (*it) << " ";
//		it++;
//	}
//
//
//	list<int> l1; 
//	
//}

//#include<stdio.h>
//#include<bool.h>
//#define V 6    // ��¼ͼ�ж���ĸ���
//
////����Ȩֵ��С�ġ���δ��ѡ��Ķ��㣬key �����¼�˸�����֮���Ȩֵ���ݣ�visited�����¼�Ÿ��������Ƿ��Ѿ���ѡ�����Ϣ
//int min_Key(int key[], bool visited[])
//{
//    int min = 2147483647, min_index;  //���� key ����ʹ�ã�min ��¼��С��Ȩֵ��min_index ��¼��СȨֵ�����Ķ���
//    //���� key ����
//    for (int v = 0; v < V; v++) {
//        //�����ǰ����Ϊ��ѡ���Ҷ�Ӧ��ȨֵС�� min ֵ
//        if (visited[v] == false && key[v] < min) {
//            //����  min ��ֵ����¼�ö����λ��
//            min = key[v];
//            min_index = v;
//        }
//    }
//    //������СȨֵ�Ķ����λ��
//    return min_index;
//}
////�����С������
//void print_MST(int parent[], int cost[V][V])
//{
//    int minCost = 0;
//    printf("��С������Ϊ��\n");
//    //���� parent ����
//    for (int i = 1; i < V; i++) {
//        //parent �����±�ֵ��ʾ�������㣬�����±��Ӧ��ֵΪ�ö���ĸ��ڵ�
//        printf("%d - %d wight:%d\n", parent[i] + 1, i + 1, cost[i][parent[i]]);//���������±�� 0 ��ʼ��������ʱ���� +1
//        //ͳ����С����������Ȩֵ
//        minCost += cost[i][parent[i]];
//    }
//    printf("��ȨֵΪ��%d", minCost);
//}
////�����û��ṩ��ͼ����Ϣ���洢�� cost �����У���Ѱ����С������
//void find_MST(int cost[V][V])
//{    //key �������ڼ�¼ B �ඥ�㵽 A �ඥ���Ȩֵ
//    //parent �������ڼ�¼��С�������и������㸸�ڵ��λ�ã���������������С������
//    //visited �������ڼ�¼������������ A �໹�� B ��
//    int parent[V], key[V];
//    bool visited[V];
//    // ��ʼ�� 3 ������
//    for (int i = 0; i < V; i++) {
//        key[i] = 2147483647;    // �� key �������λ������Ϊ���޴����
//        visited[i] = false;     // ���еĶ���ȫ������ B ��
//        parent[i] = -1;         // ���ж��㶼û�и��ڵ�
//    }
//    // ѡ�� key �����е�һ�����㣬��ʼѰ����С������
//    key[0] = 0;  // �ö����Ӧ��Ȩֵ��Ϊ 0
//    parent[0] = -1; // �ö���û�и��ڵ�
//    // ���� V �������ͼ������ѡ�� V-1 ��·�������ɹ�����С������
//    for (int x = 0; x < V - 1; x++)
//    {
//        // �� key �������ҵ�Ȩֵ��С�Ķ������ڵ�λ��
//        int u = min_Key(key, visited);
//        // �ö��㻮�ֵ� A ��
//        visited[u] = true;
//        // �����¶������ A �࣬�����Ҫ���� key �����е�����
//        for (int v = 0; v < V; v++)
//        {
//            // ����� B �д��ڵ��±�Ϊ u �Ķ����Ȩֵ�� key �����м�¼��Ȩֵ��С�������¶���ļ��룬ʹ���� B ���� A �����Ȩֵ���˸��õ�ѡ��
//            if (cost[u][v] != 0 && visited[v] == false && cost[u][v] < key[v])
//            {
//                // ���� parent �����¼�ĸ������㸸�ڵ����Ϣ
//                parent[v] = u;
//                // ���� key ����
//                key[v] = cost[u][v];
//            }
//        }
//    }
//    //���� parent ��¼�ĸ������㸸�ڵ����Ϣ�����Ѱ�ҵ�����С������
//    print_MST(parent, cost);
//}
//// main function
//int main()
//{
//    int p1, p2;
//    int wight;
//    int cost[V][V] = { 0 };
//    printf("����ͼ�����㵽�����·����Ȩֵ)��\n");
//    while (1) {
//        scanf("%d %d", &p1, &p2);
//        //����û����� -1 -1����ʾ�������
//        if (p1 == -1 && p2 == -1) {
//            break;
//        }
//        scanf("%d", &wight);
//        cost[p1 - 1][p2 - 1] = wight;
//        cost[p2 - 1][p1 - 1] = wight;
//    }
//    // �����û������ͼ����Ϣ��Ѱ����С������
//    find_MST(cost);
//    return 0;
//}
//

	// prim �㷨����С������ 

#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define INF 0x3f3f3f3f

using namespace std;

const int maxn = 505;

int a[maxn][maxn];

int vis[maxn], dist[maxn];

int n, m;

int u, v, w;

long long sum = 0;

int prim(int pos) 
{
	dist[pos] = 0;
	// һ���� n ����,����Ҫ ���� n ��,ÿ��Ѱ��һ��Ȩֵ��С�ĵ�,��¼���±�
	for (int i = 1; i <= n; i++) {
		int cur = -1;
		for (int j = 1; j <= n; j++) {
			if (!vis[j] && (cur == -1 || dist[j] < dist[cur])) {
				cur = j;
			}
		}
		// ������Ҫ��ǰ��ֹ
		if (dist[cur] >= INF) return INF;
		sum += dist[cur];
		vis[cur] = 1;
		for (int k = 1; k <= n; k++) {
			// ֻ���»�û���ҵ�����СȨֵ
			if (!vis[k]) dist[k] = min(dist[k], a[cur][k]);
		}
	}
	return sum;
}

int main(void) 
{
	scanf("%d%d", &n, &m);
	memset(a, 0x3f, sizeof(a));
	memset(dist, 0x3f, sizeof(dist));
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &u, &v, &w);
		a[u][v] = min(a[u][v], w);
		a[v][u] = min(a[v][u], w);
	}
	int value = prim(1);
	if (value >= INF) puts("impossible");
	else printf("%lld\n", sum);
	return 0;
}
