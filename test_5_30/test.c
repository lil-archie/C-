//#define  _CRT_SECURE_NO_WARNINGS 1
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
////�������ݽṹ��lengthΪ˳���ʵ��Ԫ�ظ���
//#define MAXSIZE 50
//
//typedef struct
//{
//	int elem[MAXSIZE];
//	int length;
//}SeqList;
//
////------------------����˳���------------------
//void creat(SeqList* s)
//{
//	int n, len, i;
//	printf("����˳���ĳ���:\n");
//	scanf("%d", &len);
//	s->length = len;
//	printf("����˳����Ԫ��:\n");
//	for (i = 0; i < len; i++)
//	{
//		scanf("%d", &n);
//		s->elem[i] = n;
//	}
//}
//
////--------------------�ϲ��㷨--------------------
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
//	//����LA�ȱ�LB��ʱ������LAʣ�µ�Ԫ�ظ�����LC
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
////--------------------�������Ԫ��--------------------
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
//	printf("˳���LA��Ԫ��Ϊ:\n");
//	print(&LA);
//	printf("˳���LB��Ԫ��Ϊ:\n");
//	print(&LB);
//	printf("--------------��ʼ�ϲ�˳���------------\n");
//	merge(&LA, &LB, &LC);
//	printf("�ϲ����LC��Ԫ��Ϊ:\n");
//	print(&LC);
//	return 0;
//}
