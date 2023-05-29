#define  _CRT_SECURE_NO_WARNINGS 1
//#include "CreateGraph.h"
//#include "prim.h"
///**********************************************************\
//*function: 创建图的邻接矩阵结构
//*input: GraphAdjList *G
//*output: none
//*return: void
//\**********************************************************/
//void CreateMgraph(MGraph* G)
//{
//    int i, j, k, w;
//    printf("输入顶点数和边数：\n");
//    scanf(" %d,%d", &G->numVertexes, &G->numEdges);
//
//    for (i = 0; i < G->numVertexes; i++)
//    {
//        printf("输入顶点%d信息：\n", i);
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
//                G->arc[i][j] = 0; //矩阵正对角线上为0
//            }
//        }
//    }
//
//    for (k = 0; k < G->numEdges; k++)
//    {
//        char ch;
//        printf("选择边或弧(0 ? 1): ");
//        scanf(" %d", &ch);
//        if (0 == ch)
//        {
//            printf("输入边(vi,vj)上的下标i，下标j和权w：\n");
//            scanf(" %d, %d, %d", &i, &j, &w);
//            G->arc[i][j] = w;
//            G->arc[j][i] = G->arc[i][j];
//        }
//        else
//        {
//            printf("输入弧(vi,vj)上的下标i，下标j和权w：\n");
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
