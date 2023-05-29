#pragma once
//void MinSpanTree_Prim(MGraph G)
//{
//    int min, i, j, k;
//    int adjvex[MAXVEX]; //生成树中子结点与其父结点的对应关系，MAXVEX为最大的顶点数量
//    int lowcost[MAXVEX]; //图中各顶点与生成树的最短直接距离
//    lowcost[0] = 0; //V0加入生成树
//    adjvex[0] = 0; //第一个顶点下标为0
//
//    for (i = 1; i < G.numVertexes; i++)
//    {
//        lowcost[i] = G.arc[0][i]; //将V0顶点与之有边的权值存入数组
//        adjvex[i] = 0; //初始化都为V0的下标
//    }
//
//    for (i = 1; i < G.numVertexes; i++) //向生成树中添加G.numVertexes-1次顶点
//    {
//        min = INFINITY; //初始化最小权值为无穷大
//
//        j = 1;
//        k = 0;
//
//        while (j < G.numVertexes) //循环全部顶点
//        {
//            if (lowcost[j] != 0 && lowcost[j] < min) //权值不为0且权值小于min
//            {
//                min = lowcost[j]; //则让当前权值成为最小值
//                k = j; //将当前最小值的下标存入k
//            }
//            j++;
//        }
//
//        printf(" (%d, %d) ", adjvex[k], k); //打印当前顶点边中权值最小边
//        lowcost[k] = 0; //将当前顶点的权值设置为0，表示此顶点已经完成任务
//
//        for (j = 1; j < G.numVertexes; j++)
//        {
//            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) //若下标为k顶点各权值小于此前这些顶点未被加入生成树权值
//            {
//                lowcost[j] = G.arc[k][j]; //将较小权值存入lowcost
//                adjvex[j] = k; //将下标为k的顶点存入adjvex
//            }
//        }
//    }
//}
