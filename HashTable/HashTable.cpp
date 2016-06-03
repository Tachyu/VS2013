// HashTable.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//测试函数
void Test()
{
	HashTable T;
	InitTable(&T);
	//插入序列
	int pIn[13] = { 0, 3, 6, 5, 7, 10, 23, 89, 100, 111, 81,91,93};
	//int pIn[10] = { 0, 3, 6, 5, 7, 10, 23, 89, 100, 111};

	//搜索序列
	int pSe[11] = {11, 3, 6, 5, 7, 0 , 23, 89, 100, 111, 80 };
	
	printf("插入序列：\n");
	for (int i = 0; i < 13; i++)
	{
		printf("%d- ",i);
		InsertToTable(&T, pIn[i]);
	}
	
	printf("\n搜索序列：\n");
	for (int i = 0; i < 11; i++)
	{
		int nCom = 0;
		printf("%d- ",i);
		printf("目标：%3d 哈希值：%2d 结果: %2d",pSe[i],GetHash(T,pSe[i]),SearchTable(T, pSe[i], &nCom));
		printf(" 比较：%3d\n", nCom);
	}
	
	DestroyTable(&T);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test();
	return 0;
}

