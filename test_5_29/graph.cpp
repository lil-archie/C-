#define  _CRT_SECURE_NO_WARNINGS 1
//#include "CreateGraph.h"
//#include "prim.h"
///**********************************************************\
//*function: ����ͼ���ڽӾ���ṹ
//*input: GraphAdjList *G
//*output: none
//*return: void
//\**********************************************************/
//void CreateMgraph(MGraph* G)
//{
//    int i, j, k, w;
//    printf("���붥�����ͱ�����\n");
//    scanf(" %d,%d", &G->numVertexes, &G->numEdges);
//
//    for (i = 0; i < G->numVertexes; i++)
//    {
//        printf("���붥��%d��Ϣ��\n", i);
//        scanf(" %c", &(G->vexs[i]));
//    }
//
//    for (i = 0; i < G->numVertexes; i++)
//    {
//        for (j = 0; j < G->numVertexes; j++)
//        {
//            if (i != j)
//            {
//                G->arc[i][j] = INFINITY;
//            }
//            else
//            {
//                G->arc[i][j] = 0; //�������Խ�����Ϊ0
//            }
//        }
//    }
//
//    for (k = 0; k < G->numEdges; k++)
//    {
//        char ch;
//        printf("ѡ��߻�(0 ? 1): ");
//        scanf(" %d", &ch);
//        if (0 == ch)
//        {
//            printf("�����(vi,vj)�ϵ��±�i���±�j��Ȩw��\n");
//            scanf(" %d, %d, %d", &i, &j, &w);
//            G->arc[i][j] = w;
//            G->arc[j][i] = G->arc[i][j];
//        }
//        else
//        {
//            printf("���뻡(vi,vj)�ϵ��±�i���±�j��Ȩw��\n");
//            scanf(" %d, %d, %d", &i, &j, &w);
//            G->arc[i][j] = w;
//        }
//    }
//}
//
//
//
//int main()
//{
//    MGraph G;
//    CreateMgraph(&G);
//    MinSpanTree_Prim(G);
//
//    return 0;
//}
//
