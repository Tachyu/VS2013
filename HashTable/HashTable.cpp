// HashTable.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//���Ժ���
void Test()
{
	HashTable T;
	InitTable(&T);
	//��������
	int pIn[13] = { 0, 3, 6, 5, 7, 10, 23, 89, 100, 111, 81,91,93};
	//int pIn[10] = { 0, 3, 6, 5, 7, 10, 23, 89, 100, 111};

	//��������
	int pSe[11] = {11, 3, 6, 5, 7, 0 , 23, 89, 100, 111, 80 };
	
	printf("�������У�\n");
	for (int i = 0; i < 13; i++)
	{
		printf("%d- ",i);
		InsertToTable(&T, pIn[i]);
	}
	
	printf("\n�������У�\n");
	for (int i = 0; i < 11; i++)
	{
		int nCom = 0;
		printf("%d- ",i);
		printf("Ŀ�꣺%3d ��ϣֵ��%2d ���: %2d",pSe[i],GetHash(T,pSe[i]),SearchTable(T, pSe[i], &nCom));
		printf(" �Ƚϣ�%3d\n", nCom);
	}
	
	DestroyTable(&T);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test();
	return 0;
}

