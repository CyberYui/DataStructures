#ifndef SKIPLIST_H
#define SKIPLIST_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEVEL 3	//��������Ϊ����
typedef int KeyType;

//��Ծ����Ľ��ṹ����
typedef struct node
{
	int level;				//������
	KeyType key;			//����ֵ
	struct node *next[1];   //ָ������
}*PNode;

//��Ծ����ṹ����
typedef struct SKIPLIST_STRU
{
	int num;		//��Ծ�������ݸ���
	int maxLevel;   //��Ծ����������
	PNode head;		//��Ծ�����ͷָ��
}*SkipList;

/****************************************************************/
/* PNode CreateNode(int level, KeyType key)						*/
/* ����:�������												*/
/* �������level:������ڲ���									*/
/* �������key:����ֵ											*/
/* ����ֵp:���													*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
PNode CreateNode(int level, KeyType key);

/****************************************************************/
/* SkipList SetNullSkipList(int level)							*/
/* ����:��������ͷ���Ŀ���Ծ����								*/
/* �������level:����											*/
/* ����ֵlist:��Ծ����											*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
SkipList SetNullSkipList(int level);

/****************************************************************/
/* int RandomLevel(int maxlevel)								*/
/* ����:�����������(α),�ڸ������Ե������������		    	*/
/* �������maxLevel:�����������								*/
/* ����ֵi:����													*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
int RandomLevel(int maxlevel);

/****************************************************************/
/* int SkipListInsert(SkipList list, KeyType key)				*/
/* ����:������												*/
/* �������list:Ҫ�������Ծ����								*/
/* �������key:���ֵ											*/
/* ����ֵ:1--�ɹ�����	0--����ʧ��								*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
int SkipListInsert(SkipList list, KeyType key);

/****************************************************************/
/* PNode SkipListSearch(SkipList list, KeyType key)				*/
/* ����:��ֵ���ҽ��											*/
/* �������list:��Ծ����										*/
/* �������key:���ҵĽ���ֵ									*/
/* ����ֵ:p--���ҳɹ��Ľ���λ��		NULL--����ʧ��			*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
PNode SkipListSearch(SkipList list, KeyType key);

/****************************************************************/
/* int SkipListDelete(SkipList list, KeyType key)				*/
/* ����:��ֵɾ�����											*/
/* �������list:��Ծ����										*/
/* �������key:Ҫɾ���Ľ���ֵ(Ĭ�����������ظ�Ԫ��)			*/
/* ����ֵ:1--�ɹ�ɾ��	0--ɾ��ʧ��								*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
int SkipListDelete(SkipList list, KeyType key);

/****************************************************************/
/* void PrintSkipList(SkipList list)							*/
/* ����:�����Ծ����											*/
/* �������list:��Ծ����										*/
/* ����ֵ:��													*/
/* ��������:2019-6-6						Author:Cyber Kaka	*/
/****************************************************************/
void PrintSkipList(SkipList list);

#endif	//	SKIPLIST_H
