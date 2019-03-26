/************************************************************************/
/*    �ļ���:MyQueue.h                    ��;:���ζ��е�ģ��           */
/*    ����:Cyber Kaka                     ����:YuiNozomi@vip.qq.com     */
/*    ��������:C++                        ���뻷��:VS2017               */
/*                                        ��������:2019��3��9��         */
/************************************************************************/
#ifndef MYQUEUE_H
#define MYQUEUE_H


#include <iostream>
#include <string>
using namespace std;


template<typename T>
class MyQueue
{
public:
	MyQueue(int queueCapacity);	//��������
	virtual ~MyQueue();			//���ٶ���
	void ClearQueue();			//��ն���
	bool QueueEmpty()const;		//�пն���
	bool QueueFull()const;		//��������
	int QueueLength()const;		//���г���
	bool EnQueue(T element);	//��Ԫ�����
	bool DeQueue(T &element);	//��Ԫ�س���
	void QueueTraverse();		//��������
private:
	T *m_pQueue;				//����ָ��
	int m_iQueueLen;			//����Ԫ�ظ���
	int m_iQueueCapacity;		//������������
	int m_iHead;
	int m_iTail;
};


/************************************************************************/
/*  ���캯��MyQueue       ����:����һ�����ζ���      Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
MyQueue<T>::MyQueue(int queueCapacity)
{
	m_iQueueCapacity = queueCapacity;//���û������������ֵ���ڲ����ݳ�Ա
	m_iHead = 0;//���ζ��г�ʼ�������ж�ͷ�Ͷ�β����0
	m_iTail = 0;
	m_iQueueLen = 0;//��ʼ״̬��,������Ԫ��,��Ԫ�ظ���Ϊ0
	m_pQueue = new T[m_iQueueCapacity];
	if (NULL==m_pQueue)
	{
		cout << "Memory distributed fail !" << endl;
		system("pause");
		system("exit");
	} 
	cout << "�����ɹ�!" << endl;
}


/************************************************************************/
/*  ��������~MyQueue      ����:����һ�����ζ���,����ָ��,�ͷ��ڴ�       */
/*                                                   Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
MyQueue<T>::~MyQueue()
{
	delete[]m_pQueue;
	m_pQueue = NULL;
	cout << "���ٶ��гɹ�!" << endl;
	cout << endl;
}


/************************************************************************/
/*��ն��к���ClearQueue()                                              */
/*        ����:��ն���,ʹ���б�س�ʼ״̬,��β�ͳ��ȱ��ȫ����ʼ��Ϊ0, */
/*             �˲��������޸�����,�����޸��ڴ�ָ��                      */
/*                                                   Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
void MyQueue<T>::ClearQueue()
{
	cout << "*********��ն�����..*********" << endl;
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
	cout << "***********��ճɹ�***********" << endl;
	cout << endl;
}


/************************************************************************/
/*  �пպ���QueueEmpty()    ����:�ж϶����Ƿ�Ϊ��    Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
bool MyQueue<T>::QueueEmpty()const
{
	//return m_iQueueLen == 0 ? true : false;
	if (m_iQueueLen == 0)
	{
		cout << "����Ϊ��!" << endl;
		return true;
	}
	else
	{
		cout << endl;
		return false;
	}
}


/************************************************************************/
/*  ��������QueueFull()     ����:�ж϶����Ƿ�Ϊ��    Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
bool MyQueue<T>::QueueFull()const
{
	//return m_iQueueLen == m_iQueueCapacity ? true : false;
	if (m_iQueueLen == m_iQueueCapacity)
	{
		cout << "��������!" << endl;
		cout << endl;
		return true;
	}
	else
	{
		return false;
	}
}


/************************************************************************/
/*  �г�����QueueLength()    ����:��ȡ���г���       Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
int MyQueue<T>::QueueLength()const
{
	return m_iQueueLen;
}


/************************************************************************/
/*  ��Ӻ���EnQueue(T element)      ����:�������в���Ԫ��               */
/*                                                   Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
bool MyQueue<T>::EnQueue(T element)
{
	if (QueueFull())
	{
		return false;
	}
	else
	{
		m_pQueue[m_iTail] = element;
		m_iTail++;
		m_iTail = m_iTail % m_iQueueCapacity;
		m_iQueueLen++;
		return true;
	}
}


/************************************************************************/
/*  ���Ӻ���DeQueue(T &element)                  ����:���������Ƴ�Ԫ��  */
/*  ע��:element������һ������,������һ������        Author:Cyber Kaka  */
/************************************************************************/
template<typename T>
bool MyQueue<T>::DeQueue(T &element)
{
	if (QueueEmpty())
	{
		return false;
	}
	else
	{
		element = m_pQueue[m_iHead];
		m_iHead++;
		m_iHead = m_iHead % m_iQueueCapacity;
		m_iQueueLen--;
		return true;
	}
}


/************************************************************************/
/*��������QueueTraverse()   ����:�������в����Ԫ��    Author:Cyber Kaka*/
/************************************************************************/
template<typename T>
void MyQueue<T>::QueueTraverse()
{
	cout << endl;
	cout << "***********��ʼ����***********" << endl;
	if (QueueEmpty()==true)
	{
		cout << "����Ϊ��!û������!" << endl;
	}
	else
	{	
		for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
		{
			cout << m_pQueue[i%m_iQueueCapacity] << endl;
		}
	}
	cout << "*********���α�������*********" << endl;
	cout << endl;
}


#endif
