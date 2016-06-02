#include "stdafx.h"

//100内部分素数
static int SIZE[] = { 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

/*
*	函数名称:
*		GetHash
*	功能描述:
*		获取哈希值
*	函数参数:
*		HashTable T 哈希表
*		int nKey	表长
*	返回值:
*		int nHash
*	模块历史:
*	  	创建于2016.05.31, by 张铭宇
*/
int GetHash(HashTable T, int nKey)
{
	return nKey % SIZE[(T.sizeIndex)];
}

/*
*	函数名称:
*		InitTable
*	功能描述:
*		初始化哈希表
*	函数参数:
*		HashTable *T 要初始化的哈希表
*		int nLen	 表长
*	返回值:
*		无
*	模块历史:
*	  	创建于2016.05.31, by 张铭宇
*/
void InitTable(HashTable *T, int nLen)
{
	T->sizeIndex = 0;
	int *pTemp = (int*)malloc(sizeof(int)* SIZE[T->sizeIndex]);

	if (!pTemp)
		exit(-1);//内存不足

	T->data = pTemp;
	//标记存储空间为空
	for (int i = 0;
		i < SIZE[T->sizeIndex];
		i++)
	{
		T->data[i] = -1;
	}
	T->nLen = 0;
}

/*
*	函数名称:
*		SearchTable
*	功能描述:
*		查找哈希表
*	函数参数:
*		HashTable T  要查找的哈希表
*		int nKey     要查找的值
*		int *nTime   比较的次数	 
*	返回值:
*		-1	 未找到
*		nPos 表中的位置
*	模块历史:
*	  	创建于2016.05.31, by 张铭宇
*/
int SearchTable(HashTable T, int nKey, int* nTime)
{
	//获取hash值
	int nHash = GetHash(T,nKey);
	//比较次数
	int nCom = 0;
	//初始位置为哈希值所在位置
	int nPos = nHash;
	while (T.data[nPos] != -1
		&& T.data[nPos] != nKey)
	{
		nCom++;
		nPos = (nPos + 1) % SIZE[T.sizeIndex];
	}
	//更新比较次数，反馈给调用函数
	*nTime = nPos;
	//未找到
	if (T.data[nPos] == -1)
	{
		return -1;
	}
	else
	{
		return nPos;
	}
}


/*
*	函数名称:
*		InsertToTable
*	功能描述:
*		插入哈希表
*	函数参数:
*		HashTable *T 要插入的哈希表
*		int nKey     要插入的值
*	返回值:
*		true    插入成功
*       false   表中已有或表已满
*	模块历史:
*	  	创建于2016.05.31, by 张铭宇
*/
bool InsertToTable(HashTable *T, int nKey)
{
	//比较次数
	int nCom = 0;
	//表中已有该元素
	if (SearchTable(*T, nKey, &nCom) != -1)
		return false;

	//比较次数超过阈值,重构表
	if (nCom > SIZE[T->sizeIndex] / 2)
		RecreatTable(T);

	//初始插入位置
	int nPos = GetHash(*T,nKey);
	
	//找到一个空的插入位置，利用线性探测再散列
	while (T->data[nPos] != -1)
		nPos = (nPos + 1) % SIZE[T->sizeIndex];

	//插入元素
	T->data[nPos] = nKey;
	//完成
	return true;
}

/*
*	函数名称:
*		RecreatTable
*	功能描述:
*		重构哈希表
*	函数参数:
*		HashTable *T  要重构的哈希表
*	返回值:
*		无
*	模块历史:
*	  	创建于2016.06.01, by 张铭宇
*/
void RecreatTable(HashTable *T)
{
	if (SIZE[T->sizeIndex] == 97)//达到容量数组最大值
		return;
	//新,旧表大小
	int nNewSize = SIZE[T->sizeIndex + 1];
	int nOldSize = SIZE[T->sizeIndex];
	//重新分配空间
	int *pTemp = 
		(int*)realloc(T->data,
		sizeof(int)* nNewSize);

	if (!pTemp)
		exit(-1);//内存不足

	//将新生存储空间标记为空
	for (int i = nOldSize;
		i < nNewSize;
		i++)
	{
		T->data[i] = -1;
	}

	//在原存储空间范围，由后之前，检测是否有元素hash值发生变化
	for (int i = nOldSize - 1;
		i >= 0; i--)
	{
		//待查元素
		int nCheck = T->data[i];

		//对旧hash值与新hash值不一致的元素进行处理
		if (nCheck != -1 &&
			nCheck % nOldSize
			!= nCheck % nNewSize)
		{
			//新hash值对应位置的偏移量
			int nDiv = 0;
			int nNewHash = nCheck % nNewSize;
			while (
				T->data[nNewHash + nDiv] != -1)
			{
				nDiv++;
			}
			//转移元素，将原位置置空
			T->data[nNewHash + nDiv] = nCheck;
			T->data[i] = -1;
		}
	}
}

/*
*	函数名称:
*		DestroyTable
*	功能描述:
*		销毁哈希表
*	函数参数:
*		HashTable *T  要销毁的哈希表
*	返回值:
*		无
*	模块历史:
*	  	创建于2016.05.31, by 张铭宇
*/
void DestroyTable(HashTable *T)
{
	free(T->data);
	T->sizeIndex = 0;
	T->nLen = 0;
}