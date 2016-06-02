// HashTable.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define LEN 121	//��

//���Ժ���
void Test()
{
	HashTable T;
	InitTable(&T, LEN);
	//��������
	int pIn[11] = { 0, 3, 6, 5, 7, 10, 23, 89, 100, 111, 81 };
	//��������
	int pSe[11] = { 0, 3, 6, 5, 7, 11, 23, 89, 100, 111, 80 };
	printf("�������У�\n");
	for (int i = 0; i < 11; i++)
	{
		InsertToTable(&T, pIn[i]);
	}
	printf("\nװ�����ӣ�%.2f\n",11/(LEN + 0.0));
	printf("\n�������У�\n");
	for (int i = 0; i < 11; i++)
	{
		printf("Ŀ�꣺%3d ��ϣֵ��%2d ���: %2d\n",pSe[i],GetHash(T,pSe[i]),FindTable(T, pSe[i]));
	}
	DestroyTable(&T);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test();
	return 0;
}

