// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include "malloc.h"
#include "stdlib.h"


typedef struct{
	int *data;		//数据
	int sizeIndex;	//表长序号
	int nLen;		//元素个数
}HashTable;

typedef struct{
	LNode *data;//数据
	int nLen;	//表长
}HashLink;

typedef struct
{
	int nData;
	struct LNode *pNext;
}LNode;

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
int GetHash(HashTable T, int nKey);

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
void InitTable(HashTable *T, int nLen);

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
bool InsertToTable(HashTable *T, int nKey);

/*
*	函数名称:
*		SearchTable
*	功能描述:
*		查找哈希表
*	函数参数:
*		HashTable T  要查找的哈希表
*		int nKey     要查找的值
*	返回值:
*		-1	 未找到
*		nPos 表中的位置
*	模块历史:
*	  	创建于2016.05.31, by 张铭宇
*/
int SearchTable(HashTable T, int nKey);

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
void DestroyTable(HashTable *T);

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
void RecreatTable(HashTable *T);
