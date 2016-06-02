/*
*	��������:
*		GetHash_L
*	��������:
*		��ȡ��ϣֵ_����ַ
*	��������:
*		HashLink T  ��ϣ��
*		int nKey	ֵ
*	����ֵ:
*		int nHash
*	ģ����ʷ:
*	  	������2016.06.01, by ������
*/
int GetHash_L(HashLink T, int nKey);

/*
*	��������:
*		InitTable_L
*	��������:
*		��ʼ����ϣ�� ����ַ
*	��������:
*		HashLink *T  ��ϣ��
*		int nKey	 ֵ
*	����ֵ:
*		��
*	ģ����ʷ:
*	  	������2016.06.01, by ������
*/
void InitTable(HashTable *T, int nLen);

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
*		FindTable
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
int FindTable(HashTable T, int nKey, int *nTime);

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

