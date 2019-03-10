#ifndef MYSTACKADV_H
#define MYSTACKADV_H

#include "CoordinateAdv.h"
/************************************************************************/
/* ջ��:                                                                */
/*     MyStack(int size);   //�����ڴ��ʼ��ջ�ռ�,�趨ջ����,ջ��      */
/*     ~MyStack();          //����ջ�ռ��ڴ�                            */
/*     bool stackEmpty();   //�ж�ջ�Ƿ�Ϊ��,Ϊ�շ���true,�ǿշ���false */
/*     bool stackFull();    //�ж�ջ�Ƿ�Ϊ��,Ϊ������true,��������false */
/*     void clearStack();   //���ջ                                    */
/*     int stackLength();   //ͳ������Ԫ�صĸ���                        */
/*     void push(char elem);	//Ԫ����ջ,ջ������                     */
/*     char pop(char &elem);    //Ԫ�س�ջ,ջ���½�                     */
/*     void stackTraverse();    //����ջ������Ԫ��                      */
/*                                                                      */
/* Ŀ��:����ջ��ʵ��ԭ������л���               ��������:2019-03-10    */
/************************************************************************/

class MyStack
{
public:
	MyStack(int size);		//�����ڴ��ʼ��ջ�ռ�,�趨ջ����,ջ��      
	~MyStack();				//����ջ�ռ��ڴ�                            
	bool stackEmpty();		//�ж�ջ�Ƿ�Ϊ��,Ϊ�շ���true,�ǿշ���false 
	bool stackFull();		//�ж�ջ�Ƿ�Ϊ��,Ϊ������true,��������false 
	void clearStack();		//���ջ                                    
	int stackLength();		//ͳ������Ԫ�صĸ��� 

	//���Coordinate���ͽ�����Ӧ�ĸ���
	//�������һ��Coordinate����,���ڶ���������������й��ڼ��������͵�,
	//����������ֱ�Ӵ������,���Ҫ���������������������,��ʵ����ָ���
	//��Ӧ�õ��������캯��������
	bool push(Coordinate elem);	//Ԫ����ջ,ջ������
	bool pop(Coordinate &elem);   //Ԫ�س�ջ,ջ���½� 
	void stackTraverse(bool isFromButtom);   //����ջ������Ԫ��
private:
	//ָ��Coordinate���͵�ջ�ռ�
	Coordinate *m_pBuffer;	//ջ�ռ�ָ��,ָ��ָ��ջ�ռ�
	int m_iSize;			//ջ����
	int m_iTop;				//ջ��,ջ��Ԫ�ظ���
	//ջ�ײ���д,��Ϊջ����Զ����0,�����ܱ仯
};

#endif