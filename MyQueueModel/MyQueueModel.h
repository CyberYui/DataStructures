#ifndef MYQUEUEMODEL_H
#define MYQUEUEMODEL_H
/************************************************************************/
/*			 ���ζ���C++ʵ�ִ���                              2019/03/09*/
/************************************************************************/

//Ϊʵ�ֶԸ������͵�֧��,����ͷ�ļ�
#include "CustomerTest.h"

//��ģ�����
template <typename T>
class MyQueue
{
public:							//����ע������ʾ���������C�����ж�����غ���
	//����һ������,Ҫ��һ��Ҫ��һ��ָ��ָ���������,ʹ�ö�����һ������Դ(�ڴ�ռ�)
	//queueCapacity�Ƕ����������С����
	MyQueue(int queueCapacity);	//InitQueue(&Q)    ��������

	//���ٶ��к���,���ڱ�����ɺ�Ĵ�����
	//��������,�������ָ������,�ͷ���Ӧ���ڴ�
	virtual ~MyQueue();			//DestroyQueue(&Q) ���ٶ���

	//��ն���,ʹ�ö��н�ռ�ڴ�ռ�,��������ʵ����������
	//C++ͨ���Լ������ݳ�Ա����ά����������C���Ե�ȫ�ֱ�����
	void ClearQueue();			//ChearQueue(&Q)   ��ն���

	//�жϵ�ǰ�����Ƿ�Ϊ��,������Ϊ��,���޷���ɾԪ��,��Ե�Ӧ����������
	//����Ա����,��bool QueueEmpty(const MyQueue *this)ͬ���
	//�ж�m_pQueueָ��ָ��������Ƿ�Ϊ��
	bool QueueEmpty()const;		//QueueLength(Q)   �пն���

	bool QueueFull()const;		//QueueFull(Q)	   ��������

	//�����жϵ�ǰ����Ԫ�ظ���,�����г���
	//����Ա����,��int QueueLength(const MyQueue *this)ͬ���
	int QueueLength()const;		//QueueLength(Q)   ���г���

	//����Ԫ�����,���ڶ����޷����,������Ԫ�ر��������β��
	bool EnQueue(int element);	//EnQueue(&Q,element)  ��Ԫ�����

	//Part2:����ǲ���T����,��ʹ������
	bool EnQueue(T element);

	//����Ԫ�س���,���������һ��Ԫ��,ԭ���еڶ�λ��Ϊ�ֶ��е�һλ
	bool DeQueue(int &element); //DeQueue(&Q,&element) ��Ԫ�س���

	//Part2:������Ƴ�T����,��ʹ������
	bool DeQueue(T &element);

	//�Ե�ǰ���е�ÿһ��Ԫ�ط���,�����������
	//visit�������ڴ��������ʱ��ͬ����ز���,����ֻ������int����
	//���ڼ򵥵���������,��û��Ҫר��ȥд���ʺ���,���Բ���д��
	void QueueTraverse();		//QueueTraverse(Q,visit()) ��������

	//Part2:����Customer������ר�ŵĶ����޸�
	void QueueTraverseCus();
private:
	//ָ������ָ�����(����),����������ڹ��캯���б�ʵ������
	//int *m_pQueue;			//Part1:��������ָ��
	T *m_pQueue;			//Part2:T����ָ��

	//����Ԫ�ظ���,Ҳ�ƶ��г���
	int m_iQueueLen;			//����Ԫ�ظ���

	//ָʾ���е��Ŷ�����,�ڳ�ʼ��ʱ��������
	int m_iQueueCapacity;		//������������

	//�����ͷ�Ͷ�β
	//�����Ǹ�����,�ڴ���ǰ����ֱ�Ӹ�ֵ,���Զ�����Ƕ�ͷ�Ͷ�β������
	int m_iHead;
	int m_iTail;
};

//��һʵ��ͷ�ļ��еĺ���
//ÿ������ǰ����Ҫд��template <typename T>
/************************************************************************/
/*���캯��MyQueue       ����:����һ�����ζ���          Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
MyQueue<T>::MyQueue(int queueCapacity)
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
	//��������һ����©,��Ϊ�Ӷ��������ڴ��ǿ�������ʧ�ܵ�,�����ﲻ������
	//m_pQueue = new int[m_iQueueCapacity];

	//if (NULL==m_pQueue)
	//{
	//	cout << "Memory distributed fail !" << endl;
	//}
	//����T�ڴ�
	m_pQueue = new T[m_iQueueCapacity];

}

/************************************************************************/
/*��������~MyQueue      ����:����һ�����ζ���,����ָ��,�ͷ��ڴ�         */
/*                                                     Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
MyQueue<T>::~MyQueue()
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
template <typename T>
void MyQueue<T>::ClearQueue()
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
template <typename T>
bool MyQueue<T>::QueueEmpty()const
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
template <typename T>
bool MyQueue<T>::QueueFull()const
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
template <typename T>
int MyQueue<T>::QueueLength()const
{
	return m_iQueueLen;
}

/************************************************************************/
/*��Ӻ���EnQueue(int element)    ����:�������в���Ԫ��                 */
/*                                                     Author:Cyber Kaka*/
/************************************************************************/
//Part1:
//bool MyQueue::EnQueue(int element)
//{
//	if (QueueFull())
//	{
//		return false;
//	}
//	else
//	{
//		//��ʼ״̬��,��ͷ�Ͷ�β����0,���ռ主��ʱ,��ͷ�����ƶ�
//		//ÿ����һ��Ԫ��֮��,��β���ָһ��λ��,�Դ�����
//		//�������������Ҫ��������������һ��
//		m_pQueue[m_iTail] = element;
//		m_iTail++;//��β++,�����Ǹ�ָ��һ��,ָʾ����λ��
//		//������뵽�˶�ͷ���ڵ�λ��ʱ,m_iTail�ټӾͲ�������
//		//����ʹ���жϻ����������ȡ��,�Ӷ�ʹm_iTail�Ϸ�
//		m_iTail = m_iTail % m_iQueueCapacity;
//		//if (m_iTail >= m_iQueueCapacity)
//		//{
//		//	m_iTail = 0;
//		//}
//		//else
//		//{
//		//	m_iQueueLen++;
//		//}
//		m_iQueueLen++;//ÿ����һ��Ԫ��,��Ҫ������+1
//		cout << "��������:" << element << endl;
//		return true;
//	}
//}

/************************************************************************/
/*��Ӻ���EnQueue(Customer element)    ����:�������в���Customer����Ԫ��*/
/*                                                     Author:Cyber Kaka*/
/************************************************************************/
//Part2
template <typename T>
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
		//cout << "��������:" << element << endl;
		return true;
	}
}

/************************************************************************/
/*���Ӻ���DeQueue(Customer &element)   ����:���������Ƴ�Customer����Ԫ��*/
/*ע��:element������һ������,������һ������            Author:Cyber Kaka*/
/************************************************************************/
//Part2:
template <typename T>
bool MyQueue<T>::DeQueue(T &element)
{
	if (QueueEmpty())
	{
		cout << "����Ϊ��!" << endl;
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
/*���Ӻ���DeQueue(int &element)    ����:���������Ƴ�Ԫ��                */
/*ע��:element������һ������,������һ������            Author:Cyber Kaka*/
/************************************************************************/
//Part1:
//bool MyQueue::DeQueue(int &element)
//{
//	if (QueueEmpty())
//	{
//		cout << "����Ϊ��!" << endl;
//		return false;
//	}
//	else
//	{
//		//�ڻ��ζ�����,����ռ�Ϊ��,��ôÿ��һ����Ԫ��,��Ҫ��һ����Ԫ��
//		//��Ӧ��,��ͷ��Ҫ����һλ,β����ָ��ԭλ
//		element = m_pQueue[m_iHead];
//		m_iHead++;//��������һ����λ��,��ͷ��Ϊ��һ��Ԫ��
//		//�����ͷָ����ԭ�ȶ�β���ڵ�λ��ʱ,m_iHead�ټӾͲ�������
//		//����ʹ���жϻ����������ȡ��,�Ӷ�ʹm_iHead�Ϸ�
//		m_iHead = m_iHead % m_iQueueCapacity;
//		//if (m_iHead>=m_iQueueCapacity)
//		//{
//		//	m_iHead = 0;
//		//} 
//		//else
//		//{
//		//	m_iHead++;
//		//}
//		m_iQueueLen--;//ÿɾȥһ��Ԫ��,��Ҫ������-1
//		return true;
//	}
//}

/************************************************************************/
/*��������QueueTraverse()   ����:�������в����Ԫ��    Author:Cyber Kaka*/
/************************************************************************/
//Part1
//void MyQueue::QueueTraverse()
//{
//	cout << endl;
//	cout << "***********��ʼ����***********" << endl;
//	//�ж϶����Ƿ�Ϊ��,��Ϊ�����ñ���
//	if (QueueEmpty()==true)
//	{
//		cout << "����Ϊ��!û������!" << endl;
//	}
//	else
//	{	
//		//ʹ��ѭ����������
//		//��ͷ��ֵ���ϳ��ȵ�ֵ,��֤����ͷ�������,ѭ��ʱ�Ĵ��������ܵ�Ӱ��
//		for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
//		{
//			//����i++����i<m_iQueueCapacity���ж����һ��Ҳ������i++��
//			//��ʱi����m_iQueueCapacity,��ִ�����һ��ѭ��������
//			//������ֱ�Ӵ�i�ᵼ������Խ��,����iҲӦ��ȡ��
//			//����,��m_iQueueCapacityС������ֱ��������
//			//i����m_iQueueCapacity�����ʾ��һ����
//			//Part1:
//			//cout << m_pQueue[i%m_iQueueCapacity] << endl;
//			//m_pQueue[i%m_iQueueCapacity].printInfo();
//		}
//	}
//	cout << "*********���α�������*********" << endl;
//	cout << endl;
//}

/************************************************************************/
/*��������QueueTraverseCus()   ����:�������в����Ԫ��  Author:Cyber Kaka*/
/************************************************************************/
template <typename T>
void MyQueue<T>::QueueTraverseCus()
{
	cout << endl;
	cout << "***********��ʼ����***********" << endl;
	if (QueueEmpty() == true)
	{
		cout << "����Ϊ��!û������!" << endl;
	}
	else
	{
		for (int i = m_iHead; i < m_iQueueLen + m_iHead; i++)
		{
			cout << m_pQueue[i%m_iQueueCapacity];
			cout << "ǰ�滹��" << (i - m_iHead) << "����" << endl;
		}
	}
	cout << "*********���α�������*********" << endl;
	cout << endl;
}


#endif // MYQUEUEMODEL_H