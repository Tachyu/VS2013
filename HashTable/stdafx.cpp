#include "stdafx.h"

//100�ڲ�������
static int SIZE[] = { 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

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
int GetHash(HashTable T, int nKey)
{
	return nKey % SIZE[(T.sizeIndex)];
}

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
void InitTable(HashTable *T, int nLen)
{
	T->sizeIndex = 0;
	int *pTemp = (int*)malloc(sizeof(int)* SIZE[T->sizeIndex]);

	if (!pTemp)
		exit(-1);//�ڴ治��

	T->data = pTemp;
	//��Ǵ洢�ռ�Ϊ��
	for (int i = 0;
		i < SIZE[T->sizeIndex];
		i++)
	{
		T->data[i] = -1;
	}
	T->nLen = 0;
}

/*
*	��������:
*		SearchTable
*	��������:
*		���ҹ�ϣ��
*	��������:
*		HashTable T  Ҫ���ҵĹ�ϣ��
*		int nKey     Ҫ���ҵ�ֵ
*		int *nTime   �ȽϵĴ���	 
*	����ֵ:
*		-1	 δ�ҵ�
*		nPos ���е�λ��
*	ģ����ʷ:
*	  	������2016.05.31, by ������
*/
int SearchTable(HashTable T, int nKey, int* nTime)
{
	//��ȡhashֵ
	int nHash = GetHash(T,nKey);
	//�Ƚϴ���
	int nCom = 0;
	//��ʼλ��Ϊ��ϣֵ����λ��
	int nPos = nHash;
	while (T.data[nPos] != -1
		&& T.data[nPos] != nKey)
	{
		nCom++;
		nPos = (nPos + 1) % SIZE[T.sizeIndex];
	}
	//���±Ƚϴ��������������ú���
	*nTime = nPos;
	//δ�ҵ�
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
bool InsertToTable(HashTable *T, int nKey)
{
	//�Ƚϴ���
	int nCom = 0;
	//�������и�Ԫ��
	if (SearchTable(*T, nKey, &nCom) != -1)
		return false;

	//�Ƚϴ���������ֵ,�ع���
	if (nCom > SIZE[T->sizeIndex] / 2)
		RecreatTable(T);

	//��ʼ����λ��
	int nPos = GetHash(*T,nKey);
	
	//�ҵ�һ���յĲ���λ�ã���������̽����ɢ��
	while (T->data[nPos] != -1)
		nPos = (nPos + 1) % SIZE[T->sizeIndex];

	//����Ԫ��
	T->data[nPos] = nKey;
	//���
	return true;
}

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
void RecreatTable(HashTable *T)
{
	if (SIZE[T->sizeIndex] == 97)//�ﵽ�����������ֵ
		return;
	//��,�ɱ��С
	int nNewSize = SIZE[T->sizeIndex + 1];
	int nOldSize = SIZE[T->sizeIndex];
	//���·���ռ�
	int *pTemp = 
		(int*)realloc(T->data,
		sizeof(int)* nNewSize);

	if (!pTemp)
		exit(-1);//�ڴ治��

	//�������洢�ռ���Ϊ��
	for (int i = nOldSize;
		i < nNewSize;
		i++)
	{
		T->data[i] = -1;
	}

	//��ԭ�洢�ռ䷶Χ���ɺ�֮ǰ������Ƿ���Ԫ��hashֵ�����仯
	for (int i = nOldSize - 1;
		i >= 0; i--)
	{
		//����Ԫ��
		int nCheck = T->data[i];

		//�Ծ�hashֵ����hashֵ��һ�µ�Ԫ�ؽ��д���
		if (nCheck != -1 &&
			nCheck % nOldSize
			!= nCheck % nNewSize)
		{
			//��hashֵ��Ӧλ�õ�ƫ����
			int nDiv = 0;
			int nNewHash = nCheck % nNewSize;
			while (
				T->data[nNewHash + nDiv] != -1)
			{
				nDiv++;
			}
			//ת��Ԫ�أ���ԭλ���ÿ�
			T->data[nNewHash + nDiv] = nCheck;
			T->data[i] = -1;
		}
	}
}

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
void DestroyTable(HashTable *T)
{
	free(T->data);
	T->sizeIndex = 0;
	T->nLen = 0;
}