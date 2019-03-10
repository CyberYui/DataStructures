#include "MyQueueBasic.h"
#include <iostream>
using namespace std;
//��һʵ��ͷ�ļ��еĺ���

/************************************************************************/
/*���캯��MyQueue       ����:����һ�����ζ���          Author:Cyber Kaka*/
/************************************************************************/
MyQueue::MyQueue(int queueCapacity)
{
	//���û������������ֵ���ڲ����ݳ�Ա
	m_iQueueCapacity = queueCapacity;
	//���ζ��г�ʼ�������ж�ͷ�Ͷ�β����0
	m_iHead = 0;
	m_iTail = 0;
	//��ʼ״̬��,������Ԫ��,��Ԫ�ظ���Ϊ0
	m_iQueueLen = 0;
	//ClearQueue();
	//�����ζ��з����ڴ�
	//��Ϊ�Ӷ��������ڴ��ǿ�������ʧ�ܵ�,������Ҫ�����ж�
	m_pQueue = new int[m_iQueueCapacity];
	if (NULL==m_pQueue)
	{
		cout << "Memory distributed fail !" << endl;
		system("pause");
		system("exit");
	}

}

/************************************************************************/
/*��������~MyQueue      ����:����һ�����ζ���,����ָ��,�ͷ��ڴ�         */
/*                                                     Author:Cyber Kaka*/
/************************************************************************/
MyQueue::~MyQueue()
{
	//�����������һ������,��������ʱҲҪ����������ָ��ķ�ʽ����
	delete[]m_pQueue;
	m_pQueue = NULL;
	cout << "���ٶ��гɹ�!" << endl;
	cout << endl;
}

/************************************************************************/
/*��ն��к���ClearQueue()                                              */
/*        ����:��ն���,ʹ���б�س�ʼ״̬,�����޸�����,�����޸��ڴ�ָ��*/
/*                                                     Author:Cyber Kaka*/
/************************************************************************/
void MyQueue::ClearQueue()
{
	cout << "*********��ն�����..*********" << endl;
	//����βΪ0,Ԫ�ظ���Ϊ0
	m_iHead = 0;
	m_iTail = 0;
	m_iQueueLen = 0;
	cout << "***********��ճɹ�***********" << endl;
	cout << endl;
}

/************************************************************************/
/*�пպ���QueueEmpty()  ����:�ж϶����Ƿ�Ϊ��          Author:Cyber Kaka*/
/************************************************************************/
bool MyQueue::QueueEmpty()const
{
	//return m_iQueueLen == 0 ? true : false;
	if (m_iQueueLen == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/************************************************************************/
/*��������QueueFull()  ����:�ж϶����Ƿ�Ϊ��           Author:Cyber Kaka*/
/************************************************************************/
bool MyQueue::QueueFull()const
{
	//return m_iQueueLen == m_iQueueCapacity ? true : false;
	if (m_iQueueLen == m_iQueueCapacity)
	{
		cout << "��������!" << endl;
		return true;
	}
	else
	{
		cout << "����δ��,��ʼ����!" << endl;
		return false;
	}
}

/************************************************************************/
/*�г�����QueueLength()  ����:��ȡ���г���             Author:Cyber Kaka*/
/************************************************************************/
int MyQueue::QueueLength()const
{
	return m_iQueueLen;
}

/************************************************************************/
/*��Ӻ���EnQueue(int element)    ����:�������в���Ԫ��                 */
/*                                                     Author:Cyber Kaka*/
/************************************************************************/
bool MyQueue::EnQueue(int element)
{
	if (QueueFull())
	{
		return false;
	}
	else
	{
		//��ʼ״̬��,��ͷ�Ͷ�β����0,���ռ主��ʱ,��ͷ�����ƶ�
		//ÿ����һ��Ԫ��֮��,��β���ָһ��λ��,�Դ�����
		//�������������Ҫ��������������һ��
		m_pQueue[m_iTail] = element;
		m_iTail++;//��β++,�����Ǹ�ָ��һ��,ָʾ����λ��
		//������뵽�˶�ͷ���ڵ�λ��ʱ,m_iTail�ټӾͲ�������
		//����ʹ���жϻ����������ȡ��,�Ӷ�ʹm_iTail�Ϸ�
		m_iTail = m_iTail % m_iQueueCapacity;
		//if (m_iTail >= m_iQueueCapacity)
		//{
		//	m_iTail = 0;
		//}
		//else
		//{
		//	m_iQueueLen++;
		//}
		m_iQueueLen++;//ÿ����һ��Ԫ��,��Ҫ������+1
		cout << "��������:" << element << endl;
		return true;
	}
}

/************************************************************************/
/*���Ӻ���DeQueue(int &element)    ����:���������Ƴ�Ԫ��                */
/*ע��:element������һ������,������һ������            Author:Cyber Kaka*/
/************************************************************************/
bool MyQueue::DeQueue(int &element)
{
	if (QueueEmpty())
	{
		cout << "����Ϊ��!" << endl;
		return false;
	}
	else
	{
		//�ڻ��ζ�����,����ռ�Ϊ��,��ôÿ��һ����Ԫ��,��Ҫ��һ����Ԫ��
		//��Ӧ��,��ͷ��Ҫ����һλ,β����ָ��ԭλ
		element = m_pQueue[m_iHead];
		m_iHead++;//��������һ����λ��,��ͷ��Ϊ��һ��Ԫ��
		//�����ͷָ����ԭ�ȶ�β���ڵ�λ��ʱ,m_iHead�ټӾͲ�������
		//����ʹ���жϻ����������ȡ��,�Ӷ�ʹm_iHead�Ϸ�
		m_iHead = m_iHead % m_iQueueCapacity;
		//if (m_iHead>=m_iQueueCapacity)
		//{
		//	m_iHead = 0;
		//} 
		//else
		//{
		//	m_iHead++;
		//}
		m_iQueueLen--;//ÿɾȥһ��Ԫ��,��Ҫ������-1
		return true;
	}
}

/************************************************************************/
/*��������QueueTraverse()   ����:�������в����Ԫ��    Author:Cyber Kaka*/
/************************************************************************/
void MyQueue::QueueTraverse()
{
	cout << endl;
	cout << "***********��ʼ����***********" << endl;
	//�ж϶����Ƿ�Ϊ��,��Ϊ�����ñ���
	if (QueueEmpty()==true)
	{
		cout << "����Ϊ��!û������!" << endl;
	}
	else
	{	
		//ʹ��ѭ����������
		//��ͷ��ֵ���ϳ��ȵ�ֵ,��֤����ͷ�������,ѭ��ʱ�Ĵ��������ܵ�Ӱ��
		for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
		{
			//����i++����i<m_iQueueCapacity���ж����һ��Ҳ������i++��
			//��ʱi����m_iQueueCapacity,��ִ�����һ��ѭ��������
			//������ֱ�Ӵ�i�ᵼ������Խ��,����iҲӦ��ȡ��
			//����,��m_iQueueCapacityС������ֱ��������
			//i����m_iQueueCapacity�����ʾ��һ����
			//Part1:
			//cout << m_pQueue[i%m_iQueueCapacity] << endl;
			//m_pQueue[i%m_iQueueCapacity].printInfo();
		}
	}
	cout << "*********���α�������*********" << endl;
	cout << endl;
}
