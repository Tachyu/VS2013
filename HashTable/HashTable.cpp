// HashTable.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define LEN 121	//表长

//测试函数
void Test()
{
	HashTable T;
	InitTable(&T, LEN);
	//插入序列
	int pIn[11] = { 0, 3, 6, 5, 7, 10, 23, 89, 100, 111, 81 };
	//搜索序列
	int pSe[11] = { 0, 3, 6, 5, 7, 11, 23, 89, 100, 111, 80 };
	printf("插入序列：\n");
	for (int i = 0; i < 11; i++)
	{
		InsertToTable(&T, pIn[i]);
	}
	printf("\n装填因子：%.2f\n",11/(LEN + 0.0));
	printf("\n搜索序列：\n");
	for (int i = 0; i < 11; i++)
	{
		printf("目标：%3d 哈希值：%2d 结果: %2d\n",pSe[i],GetHash(T,pSe[i]),FindTable(T, pSe[i]));
	}
	DestroyTable(&T);
}

int _tmain(int argc, _TCHAR* argv[])
{
	Test();
	return 0;
}

