//#define  _CRT_SECURE_NO_WARNINGS 1
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
////定义数据结构，length为顺序表实际元素个数
//#define MAXSIZE 50
//
//typedef struct
//{
//	int elem[MAXSIZE];
//	int length;
//}SeqList;
//
////------------------创建顺序表------------------
//void creat(SeqList* s)
//{
//	int n, len, i;
//	printf("输入顺序表的长度:\n");
//	scanf("%d", &len);
//	s->length = len;
//	printf("输入顺序表的元素:\n");
//	for (i = 0; i < len; i++)
//	{
//		scanf("%d", &n);
//		s->elem[i] = n;
//	}
//}
//
////--------------------合并算法--------------------
//void merge(SeqList* LA, SeqList* LB, SeqList* LC)
//{
//	int i, j, k;
//	i = 0; j = 0; k = 0;
//	while (i < LA->length && j < LB->length)
//	{
//		if (LA->elem[i] <= LB->elem[j])
//		{
//			LC->elem[k] = LA->elem[i];
//			i++; k++;
//		}
//		else
//		{
//			LC->elem[k] = LB->elem[j];
//			j++; k++;
//		}
//	}
//	//当表LA比表LB长时，将表LA剩下的元素赋给表LC
//	while (i < LA->length)
//	{
//		LC->elem[k] = LA->elem[i];
//		i++; k++;
//	}
//	while (j < LB->length)
//	{
//		LC->elem[k] = LB->elem[j];
//		j++; k++;
//	}
//	LC->length = LA->length + LB->length;
//}
////--------------------输出所有元素--------------------
//void print(SeqList* L)
//{
//	int i;
//	if (L->length == 0) return;
//	for (i = 0; i < L->length; i++)
//		printf("%d  ", L->elem[i]);
//	printf("\n");
//}
//int main()
//{
//	SeqList LA, LB, LC;
//	creat(&LA);
//	creat(&LB);
//	printf("顺序表LA的元素为:\n");
//	print(&LA);
//	printf("顺序表LB的元素为:\n");
//	print(&LB);
//	printf("--------------开始合并顺序表------------\n");
//	merge(&LA, &LB, &LC);
//	printf("合并结果LC的元素为:\n");
//	print(&LC);
//	return 0;
//}
