#ifndef MYQUEUE_H
#define MYQUEUE_H
/************************************************************************/
/*			 ���ζ���C++ʵ�ִ���                              2019/03/09*/
/************************************************************************/

//Ϊʵ�ֶԸ������͵�֧��,����ͷ�ļ�
#include "CustomerBasic.h"

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

	//Part2:����ǲ���Customer����,��ʹ������
	bool EnQueue(Customer element);

	//����Ԫ�س���,���������һ��Ԫ��,ԭ���еڶ�λ��Ϊ�ֶ��е�һλ
	bool DeQueue(int &element); //DeQueue(&Q,&element) ��Ԫ�س���

	//Part2:������Ƴ�Customer����,��ʹ������
	bool DeQueue(Customer &element);

	//�Ե�ǰ���е�ÿһ��Ԫ�ط���,�����������
	//visit�������ڴ��������ʱ��ͬ����ز���,����ֻ������int����
	//���ڼ򵥵���������,��û��Ҫר��ȥд���ʺ���,���Բ���д��
	void QueueTraverse();		//QueueTraverse(Q,visit()) ��������

	//Part2:����Customer������ר�ŵĶ����޸�
	void QueueTraverseCus();
private:
	//ָ������ָ�����(����),����������ڹ��캯���б�ʵ������
	//int *m_pQueue;			//Part1:��������ָ��
	Customer *m_pQueue;			//Part2:Customer����ָ��

	//����Ԫ�ظ���,Ҳ�ƶ��г���
	int m_iQueueLen;			//����Ԫ�ظ���

	//ָʾ���е��Ŷ�����,�ڳ�ʼ��ʱ��������
	int m_iQueueCapacity;		//������������

	//�����ͷ�Ͷ�β
	//�����Ǹ�����,�ڴ���ǰ����ֱ�Ӹ�ֵ,���Զ�����Ƕ�ͷ�Ͷ�β������
	int m_iHead;
	int m_iTail;
};

#endif