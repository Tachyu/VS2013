// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include "malloc.h"
#include "stdlib.h"


typedef struct{
	int *data;		//����
	int sizeIndex;	//�����
	int nLen;		//Ԫ�ظ���
}HashTable;

typedef struct{
	LNode *data;//����
	int nLen;	//��
}HashLink;

typedef struct
{
	int nData;
	struct LNode *pNext;
}LNode;

/*
*	��������:
*		GetHash
*	��������:
*		��ȡ��ϣֵ
*	��������:
*		HashTable T ��ϣ��
*		int nKey	��
*	����ֵ:
*		int nHash
*	ģ����ʷ:
*	  	������2016.05.31, by ������
*/
int GetHash(HashTable T, int nKey);

/*
*	��������:
*		InitTable
*	��������:
*		��ʼ����ϣ��
*	��������:
*		HashTable *T Ҫ��ʼ���Ĺ�ϣ��
*		int nLen	 ��
*	����ֵ:
*		��
*	ģ����ʷ:
*	  	������2016.05.31, by ������
*/
void InitTable(HashTable *T, int nLen);

/*
*	��������:
*		InsertToTable
*	��������:
*		�����ϣ��
*	��������:
*		HashTable *T Ҫ����Ĺ�ϣ��
*		int nKey     Ҫ�����ֵ
*	����ֵ:
*		true    ����ɹ�
*       false   �������л������
*	ģ����ʷ:
*	  	������2016.05.31, by ������
*/
bool InsertToTable(HashTable *T, int nKey);

/*
*	��������:
*		SearchTable
*	��������:
*		���ҹ�ϣ��
*	��������:
*		HashTable T  Ҫ���ҵĹ�ϣ��
*		int nKey     Ҫ���ҵ�ֵ
*	����ֵ:
*		-1	 δ�ҵ�
*		nPos ���е�λ��
*	ģ����ʷ:
*	  	������2016.05.31, by ������
*/
int SearchTable(HashTable T, int nKey);

/*
*	��������:
*		DestroyTable
*	��������:
*		���ٹ�ϣ��
*	��������:
*		HashTable *T  Ҫ���ٵĹ�ϣ��
*	����ֵ:
*		��
*	ģ����ʷ:
*	  	������2016.05.31, by ������
*/
void DestroyTable(HashTable *T);

/*
*	��������:
*		RecreatTable
*	��������:
*		�ع���ϣ��
*	��������:
*		HashTable *T  Ҫ�ع��Ĺ�ϣ��
*	����ֵ:
*		��
*	ģ����ʷ:
*	  	������2016.06.01, by ������
*/
void RecreatTable(HashTable *T);
