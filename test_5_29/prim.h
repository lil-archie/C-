#pragma once
//void MinSpanTree_Prim(MGraph G)
//{
//    int min, i, j, k;
//    int adjvex[MAXVEX]; //���������ӽ�����丸���Ķ�Ӧ��ϵ��MAXVEXΪ���Ķ�������
//    int lowcost[MAXVEX]; //ͼ�и������������������ֱ�Ӿ���
//    lowcost[0] = 0; //V0����������
//    adjvex[0] = 0; //��һ�������±�Ϊ0
//
//    for (i = 1; i < G.numVertexes; i++)
//    {
//        lowcost[i] = G.arc[0][i]; //��V0������֮�бߵ�Ȩֵ��������
//        adjvex[i] = 0; //��ʼ����ΪV0���±�
//    }
//
//    for (i = 1; i < G.numVertexes; i++) //�������������G.numVertexes-1�ζ���
//    {
//        min = INFINITY; //��ʼ����СȨֵΪ�����
//
//        j = 1;
//        k = 0;
//
//        while (j < G.numVertexes) //ѭ��ȫ������
//        {
//            if (lowcost[j] != 0 && lowcost[j] < min) //Ȩֵ��Ϊ0��ȨֵС��min
//            {
//                min = lowcost[j]; //���õ�ǰȨֵ��Ϊ��Сֵ
//                k = j; //����ǰ��Сֵ���±����k
//            }
//            j++;
//        }
//
//        printf(" (%d, %d) ", adjvex[k], k); //��ӡ��ǰ�������Ȩֵ��С��
//        lowcost[k] = 0; //����ǰ�����Ȩֵ����Ϊ0����ʾ�˶����Ѿ��������
//
//        for (j = 1; j < G.numVertexes; j++)
//        {
//            if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j]) //���±�Ϊk�����ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ
//            {
//                lowcost[j] = G.arc[k][j]; //����СȨֵ����lowcost
//                adjvex[j] = k; //���±�Ϊk�Ķ������adjvex
//            }
//        }
//    }
//}
