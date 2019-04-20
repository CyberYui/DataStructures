#ifndef POLYADD_H
#define POLYADD_H

struct tagNode
{
	float coef;//ϵ��
	int exp;//ָ��
	struct tagNode *next;//ָ����
};
typedef struct tagNode Node;
typedef struct tagNode *PNode;

//��������:�������뵽������ʵ�λ��,������������
//������� head---����ͷ���
//������� pnode--������Ľ��
//����ֵ:��
void InsertList(PNode head, PNode pnode);

//��������:����InsertList(),��������ʽ����
//������� head---����ͷ���
//����ֵ:��
void CreateList(PNode head);

//��������:��������ʽ���
//������� head---����ͷ���
//����ֵ:��
void Add_Poly(PNode pa, PNode pb);

//��������:�������ʽ����
//������� head---����ͷ���
//����ֵ:��
void printLinkedList(PNode head);

#endif // POLYADD_H