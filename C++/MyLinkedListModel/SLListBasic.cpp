#include <iostream>
#include "SLListBasic.h"
using namespace std;

/************************************************************************/
/* ���캯��List()														*/
/*     ����������˵,������˳���һ����Ҫ�涨��С,������ʱ�����ַ,������*/
/* ַ���ص���ǰ��������													*/
/*																		*/
/* ����:����һ����ʼ��������,������һ��ָ����ΪNULL,��ֵ��Ϊ0��ͷ���	*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
List::List()
{
	//�������
	m_pList = new Node;
	m_pList->data = 0;//��ֵ��Ϊ0
	m_pList->next = NULL;//ָ����ΪNULL
	//�����Ͷ������һ��ͷ���,��������,ͷ�����û�������
	m_iLength = 0;//����Ϊ0
}


/************************************************************************/
/* ��������~List()														*/
/*     ����������˵,���������������ǽ���������н��ȫ���ͷ�,������һ�� */
/* ���,����պ���ClearList()�Ա�,�������������ͷ��˵�һ�����			*/
/*																		*/
/* ����:�ͷ�һ�������������������,ɾ��ָ��,�ͷ��ڴ�ռ�				*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
List::~List()
{
	//����ClearList,����������׵Ľ��
	ClearList();
	//������׽��
	delete m_pList;
	m_pList = NULL;
}


/************************************************************************/
/* ��պ���ClearList()													*/
/*     ����������˵,������պ������ǽ�����Ľ��ȫ���ͷ�,���ǲ�������һ */
/* �����,����������~List()�Ա�,�������������ͷ��˵�һ�����,��պ���û	*/
/* ��																	*/
/*																		*/
/* ����:���һ������ķ�����������										*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
void List::ClearList()
{
	//������ץ����,�����ҵ�һ������,Ȼ�������п���,�ҳ�������
	//֮����ץ������,Ȼ��˳������,ֱ�����������ѵ�
	Node *tempNode = m_pList->next;//����һ���˽�������
	//�����ҵ��׽��,�����ж�
	while (tempNode != NULL)
	{
		//�ǿ�����������,��ȡ��Ϣ,֮��������,��Ϊ���Ѿ�û�����ü�ֵ��
		Node *temp = tempNode->next;//����ָ������ָ����һ�����
		delete tempNode;//ɾ��ԭ���
		tempNode = temp;//�����½��,�ص�����ͷ��������
	}
	//���н��������,��tempNode=NULL
	//��β,�����´��ռ����ݵ�ʱ���������������
	m_pList->next = NULL;
}


/************************************************************************/
/* �пպ���ListEmpty()													*/
/*     ����������˵,�����пպ������Ƕ�������������ж�,���Ϊ��,�򷵻�һ*/
/* ��trueֵ,����ǿ�,�򷵻�false										*/
/*																		*/
/* ����:�ж�һ�������Ƿ�Ϊ��											*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::ListEmpty()
{
	if (m_iLength == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


/************************************************************************/
/* �ⳤ����ListLength()													*/
/*     ͬ˳���,��������˵,���Ĳⳤ�������Ƕ���������ĳ��Ƚ��з��ؼ���	*/
/*																		*/
/* ����:����һ������ĳ���												*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
int List::ListLength()
{
	return m_iLength;
}


/************************************************************************/
/* ��ͷ�����㺯��ListInsertHead(Node *pNode)							*/
/*																		*/
/* ����:��һ�����pNode���뵽ͷ���ĺ���								*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::ListInsertHead(Node *pNode)
{
	//����Ҫ�ҵ�ͷ���ָ����ָ��Ľ��,��m_pList->next
	//����ԭ�ȵĵڶ������,������������µĵ��������
	Node *secondNode = m_pList->next;
	//����Ҫ��Ҫ����Ľ������ݱ�������,��pNode->data
	Node *newNode = new Node;
	//�������µĽ���ʱ��,���ܻ����������ڴ�ʧ�ܵ����,��ʱ����false
	if (newNode == NULL)//�������ж�,һ��Ҫ���ǲ�������==,���������޴���,��������д���
	{
		return false;
	}
	newNode->data = pNode->data;//������ֵ������
	//����ͷ���ָ������µĽ��,��newNode
	m_pList->next = newNode;
	//�����½���ָ����,ָ��ԭͷ���ָ����ָ��Ľ�㱻������temp��
	newNode->next = secondNode;
	//����ɹ���,����true,��ʱ������+1
	m_iLength++;
	return true;
}


/************************************************************************/
/* ��β�����㺯��ListInsertTail(Node *pNode)							*/
/*																		*/
/* ����:��һ�����pNode���뵽β���ĺ���								*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::ListInsertTail(Node *pNode)
{
	//����Ҫ�ҵ�����ͷ���,�Ӷ����ܰ����ҵ�β���
	//�������޸�ͷ���,���Խ���һ����ʱ���,���������Ϊ�ɵ�β���
	Node *currentTailNode = m_pList;
	//�ж���ʱ����Ƿ�ָ��NULL,�������,��һֱ������
	while (currentTailNode->next != NULL)
	{
		currentTailNode = currentTailNode->next;
	}
	//��ʱtempNode=NULL
	//�������һ�����,��β���
	Node *newNode = new Node;
	//�������µĽ���ʱ��,���ܻ����������ڴ�ʧ�ܵ����,��ʱ����false
	if (newNode == NULL)
	{
		return false;
	}
	//�Ѵ���Ľ���������ָ�����趨��
	newNode->data = pNode->data;
	newNode->next = NULL;
	//�����µĽ�����β�����
	currentTailNode->next = newNode;
	//����ɹ���,����true,��ʱ������+1
	m_iLength++;
	return true;
}


/************************************************************************/
/* �����㺯��ListInsert(int i, Node *pNode)							*/
/*																		*/
/* ����:��һ�����pNode���뵽���������i���֮��						*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::ListInsert(int i, Node *pNode)
{
	//����i��ֵ,����Ƿ�,���������,ֱ�ӷ���false
	if (i < 0 || i > m_iLength)
	{
		return false;
	}
	//��Ȼ˵����������жϻ�������߼�����,����ʵ�ʵĲ�����û������
	//if (i==0)
	//{
	//	ListInsertHead(pNode);
	//	return true;
	//}
	//if (i==m_iLength)
	//{
	//	ListInsertTail(pNode);
	//	return true;
	//}
	else
	{
		//���Ȼ�����ͷ��㲢����һ����
		Node *iNode = m_pList;
		//ͨ��forѭ���ҵ���i�����
		for (int k = 0; k < i; k++)
		{
			iNode = iNode->next;
		}
		//�����½��
		Node *newNode = new Node;
		//�������µĽ���ʱ��,���ܻ����������ڴ�ʧ�ܵ����,��ʱ����false
		if (newNode == NULL)
		{
			return false;
		}
		//�Ѵ���Ľ�������򸳸��½��
		newNode->data = pNode->data;
		//i������һ�����������newNode����һ�����
		newNode->next = iNode->next;
		//��ʱ���½����뵽i���֮��
		iNode->next = newNode;
		m_iLength++;
		return true;
	}
}


/************************************************************************/
/* ɾ����㺯��ListDelete(int i, Node *pNode)							*/
/*																		*/
/* ����:��һ��i���ɾ��,���������ݴ���pNode								*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::ListDelete(int i, Node *pNode)
{
	//Ҫɾ��һ�����,����Ҫ������ǰһ�����
	//������ɾ����ʱ��������ǰ�����,Ȼ�������̽��
	//��ǰ��������Ӻ�̽��,�ͷŵ�ǰ���,������˶Խ���ɾ��

	//�����ж�i��ֵ�Ƿ�Ϸ�,���Ϸ���ֱ�ӷ���false
	//����ͷ���֮ǰ��β���֮�󲻴��ڵĽ��û��ɾ,����Ľ�㶼����ɾ��
	if (i < 0 || i >= m_iLength)
	{
		//����ʹ�õ���forѭ��,����i���ܵ���m_iLength,
		//��������ɾ��β���֮�󲻴��ڵĽ��
		return false;
	}
	//��������ͷ���
	Node *currentNode = m_pList;
	//����ǰ�Ľ����ʱ������currentNodeBefore��
	Node *currentNodeBefore = NULL;
	for (int k = 0; k <= i; k++)
	{
		//����ԭ�ȵĽ��
		currentNodeBefore = currentNode;
		//���ƽ��,��ʱcurrentNodeBefore����Ľ���Ѿ������ڽ���ǰ�������
		currentNode = currentNode->next;
		//����currentNode����Ľ�������ڽ��ĺ�̽��
	}
	//�����ǰ�����ָ����ָ���̽��,��ɶԽ��ķ���
	currentNodeBefore->next = currentNode->next;
	//�����������򱣴��pNode
	pNode->data = currentNode->data;
	//ɾ�����,�ͷ��ڴ�
	delete currentNode;
	currentNode = NULL;
	//������-1
	m_iLength--;
	return true;
	/************************************************************/
	/* ���� ListDelete(int i, Node *pNode) �Ľ���               */
	/*   currentNode(CN)   currentNodeBefore(CNB)   pNode(PN)   */
	/* ��������ôһ������:						                */
	/*     1|A      //�����Ҫɾ�����2|B,����ú���	        */
	/*     2|B      //��ʱΪ��ʼ,CN->1|A,��ͷ���               */
	/*     3|C                   CNB->NULL PN=NULL  ��ʼѭ��:   */
	/*     4|D      <1>k=0 k<=2? ��  CNB->1|A  CN->2|B  k++ = 1 */
	/*     5|E		<2>k=1 k<=2? ��  CNB->2|B  CN->3|C  k++ = 2 */
	/*              <3>k=2 k<=2? ��  CNB->3|C  CN->4|D  k++ = 3 */
	/*              <4>k=3 k<=2? ��								*/
	/*              ѭ������:     ��ʱ      CNB->3|C  CN->4|D   */
	/*			ִ��currentNodeBefore->next = currentNode->next	*/
	/*				��CNB -> 3|C        �� CNB.next -> 5|E		*/
	/*				  PN.data = CN.data = 4						*/
	/*				������� 3|C ָ�� 5|E pNode�б���4�������	*/
	/*		��4|D�Ѿ���ɾ����������	delete currentNode			*/
	/************************************************************/
}



/************************************************************************/
/* ��ȡָ����㺯��GetElem(int i, Node *pNode)							*/
/*																		*/
/* ����:��ȡָ��λ��i�Ľ��,������������ȡ��pNode						*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::GetElem(int i, Node *pNode)
{
	//��ListDelete��Ҳ��Ҫ��i�Ľ��,���Խ���˼��
	if (i < 0 || i >= m_iLength)
	{
		return false;
	}
	//��������ͷ���
	Node *currentNode = m_pList;
	for (int k = 0; k < i; k++)
	{
		currentNode = currentNode->next;
	}
	pNode->data = currentNode->data;
	return true;
}


/************************************************************************/
/* ��λ��㺯��LocateElem(Node *pNode)									*/
/*																		*/
/* ����:��ȡָ�����pNode,�������в����Ƿ��к�����������ͬ�Ľ��,����� */
/*      �򷵻��������������е�λ��i,���򷵻�0,���Ҳ���				*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
int List::LocateElem(Node *pNode)
{
	//Ҫ����������ȥ��pNode�Ա�
	//����Ҫ����ͷ���
	Node *currentNode = m_pList;//ͷ������������û�������,��Ϊ��0
	//�ж���ʱ����Ƿ�ָ��NULL,�������,��һֱ������
	int count = 1;//������,������ͷ���,���Դ�1��ʼ��
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		//�Ա�������
		if (currentNode->data == pNode->data)
		{
			//����ҵ���������ͬ�Ľ��,�ͷ��ص�һ��ƥ��Ľ����
			return count;
			//�������п����кܶ���pNode��������ͬ�Ľ��,����ֻ���ص�һ��ƥ���
		}
		//û���ҵ��ͼ�����+1,��������
		count++;
	}
	//����ȫ������֮��û���ҵ�,�ͷ���-1
	return -1;
}


/************************************************************************/
/* ǰ��Ѱ�Һ���PriorElem(Node *pCurrentNode, Node *pPreNode)			*/
/*																		*/
/* ����:��ȡָ�����pCurrentNode,�������в����Ƿ��к�����������ͬ�Ľ��,*/
/*      ������򷵻��������������е�ǰ�����pPreNode��������			*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::PriorElem(Node *pCurrentNode, Node *pPreNode)
{
	//���Խ��LocateElem����������,������Ҫ����ͷ���
	Node *currentNode = m_pList;//ͷ������������û�������,��Ϊ��0
	Node *tempNode = NULL;//������ʱ�ڵ�,���浱ǰ������һ�����
	//�жϽ���Ƿ�ָ��NULL,�������,��һֱ������
	while (currentNode->next != NULL)
	{
		tempNode = currentNode;
		//����������,��ǰ������һλ,�Ӷ�tempNode�������ǰ�����
		currentNode = currentNode->next;
		//�Ա�������
		if (currentNode->data == pCurrentNode->data)
		{
			if (tempNode == m_pList)
			{
				//�ж�tempNode�ǲ���ͷ��㱾��,�����,
				//��currentNode�ǵ�һ�����
				//����ǰ�������ͷ���,��û�������
				return false;
			}
			//��ȷ�ҵ�֮��ͷ��ص�ǰ����ǰ���������
			pPreNode->data = tempNode->data;
			return true;
		}
	}
	//����ȫ������֮��û���ҵ�,�ͷ���false
	return false;
}


/************************************************************************/
/* ���Ѱ�Һ���NextElem(Node *pCurrentNode, Node *pNextNode)			*/
/*																		*/
/* ����:��ȡָ�����pCurrentNode,�������в����Ƿ��к�����������ͬ�Ľ��,*/
/*      ������򷵻��������������еĺ�̽��������򸳸�pNextNode		*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
bool List::NextElem(Node *pCurrentNode, Node *pNextNode)
{
	//����Ҫ����ͷ���
	Node *currentNode = m_pList;//ͷ������������û�������,��Ϊ��0
	//�����Һ�̽��,����Ҫ�����ǰ�����б���������������
	//��Ϊnext��ָ����һ�����
	while (currentNode->next != NULL)
	{
		currentNode = currentNode->next;
		//�Ա�������
		if (currentNode->data == pCurrentNode->data)
		{
			if (currentNode->next == NULL)
			{
				//�ж�currentNode�ǲ���β��㱾��,�����,
				//��currentNode�����һ�����,û�к�̽��
				return false;
			}
			//��ȷ�ҵ�֮��ͷ��ص�ǰ���ĺ�̽���������
			pNextNode->data = currentNode->next->data;
			return true;
		}
	}
	//����ȫ������֮��û���ҵ�,�ͷ���false
	return false;
}


/************************************************************************/
/* ��������ListTraverse()												*/
/*																		*/
/* ����:������������,��ɶ��������ݵ����								*/
/*																		*/
/* ��������:2019-03-12								 Author:Cyber Kaka	*/
/************************************************************************/
void List::ListTraverse()
{
	//����Ҫ����ͷ���
	Node *currentNode = m_pList;
	while (currentNode->next != NULL)
	{
		//����ͷ������������,����ֱ�Ӵӵڶ����������
		currentNode = currentNode->next;
		currentNode->printNode();
	}
}