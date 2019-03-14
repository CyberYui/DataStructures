#include <iostream>
#include "NodeAdv.h"
using namespace std;

Node::Node()
{
	index = 0;//��ʼ����Ϊ0
	data = 0;//��ʼ������Ϊ0
	pLChild = NULL;//����ָ���Ϊ��
	pRChild = NULL;
	pParent = NULL;
}


/****************************************************************/
/*				SearchNode(int nodeIndex)						*/
/* ����:Ѱ�Ҵ�������nodeIndex���Ӧ�Ľ��,������,�򷵻�,���򷵻�*/
/*		NULL,��������ͬ������,������е���						*/
/* �ص�:�ں�ʱ�ݹ����,�ں�ʱ���ؿ�ֵ							*/
/* ��������:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
Node *Node::SearchNode(int nodeIndex)
{
	//SearchNode��Tree����ĺ���ͬ��
	//�����ǻ���һ����,ֻ��������Node��ʵ��,Tree�е���

	if (this->index == nodeIndex)
	{
		//�����Ҫ�ҵ�������ͬ,�Ǿ����Լ�
		return this;
	}
	//������ʱ��������
	Node *temp = NULL;
	//�Լ�������,�Ϳ�����,��֮ǰ���ж�һ���ǲ���Ϊ��
	if (this->pLChild != NULL)
	{
		//�����Ϊ��,�������ǲ�����ͬ
		if (this->pLChild->index == nodeIndex)
		{
			//���������ͬ,����������ڵ�
			return this->pLChild;
		}
		else
		{
			//���û�ҵ���ڵ�,�Ǿͼ���������
			//����ҵ���,�ͽ�����,�����س�ȥ
			temp = this->pLChild->SearchNode(nodeIndex);
			if (temp != NULL)
			{
				return temp;
			}
		}
	}
	//�Լ�����ߵĶ�������,����,��֮ǰ���ж�һ���ǲ���Ϊ��
	if (this->pRChild != NULL)
	{
		//�����Ϊ��,�������ǲ�����ͬ
		if (this->pRChild->index == nodeIndex)
		{
			//���������ͬ,���������ҽڵ�
			return this->pRChild;
		}
		else
		{
			//���û�ҵ��ҽڵ�,�Ǿͼ���������
			//����ҵ���,�ͽ�����,�����س�ȥ
			temp = this->pRChild->SearchNode(nodeIndex);
			//�����������һ��,����Ҳ�����ж���,ֱ�ӷ��ؼ���
			//if (temp != NULL)
			//{
			//	return temp;
			//}
			return temp;
		}
	}
	//�����������,��ֻ��֤��Ҫ�ҵĽ�㲻������
	return NULL;
}

/****************************************************************/
/* void DeleteNode()											*/
/* ����:ͨ���ݹ����ɾ�����									*/
/* �ص�:SearchNode����											*/
/* ��������:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
void Node::DeleteNode()
{
	//��ɾ����ʱ��,��ý�����Ӧ�����ɾ��
	//����,��������ӽ��,�Ǿ���ɾ�����ĸ����ӽ��
	//Ȼ��������ĸ��ڵ�,Ҫ�����ڸ��ڵ����һ����λ
	//��������,�򽫸��ڵ������ָ����ΪNULL,Ȼ��Ҫɾ�����ӽڵ���ɱ
	//������Ҳ�,�򽫸��ڵ���Һ���ָ����ΪNULL,Ȼ��Ҫɾ�����ӽڵ���ɱ

	//��ɱ�����Һ���,ʹ�õݹ�
	if (this->pLChild != NULL)//����
	{
		this->pLChild->DeleteNode();
	}
	if (this->pRChild != NULL)//����
	{
		this->pRChild->DeleteNode();
	}
	//�����ж��Լ��ĸ��ڵ�ָ��
	if (this->pParent != NULL)
	{
		if (this->pParent->pLChild == this)
		{
			//����Լ����ڵ���������Լ�,����ָ����ΪNULL
			this->pParent->pLChild = NULL;
		}
	}
	if (this->pParent != NULL)
	{
		if (this->pParent->pRChild == this)
		{
			//����Լ����ڵ���Һ������Լ�,����ָ����ΪNULL
			this->pParent->pRChild = NULL;
		}
	}
	//��ɺ�ɾ���Լ�������
	delete this;
}


/****************************************************************/
/*				PreorderTraversal()								*/
/* ����:ǰ�����												*/
/* �ص�:�ݹ����												*/
/* ��������:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
void Node::PreorderTraversal()
{
	//����һ�������˵,��ǰ���������,���Լ�,Ȼ����,֮����
	//������Լ�������  ������(����)
	cout << this->data << "(" << this->index << ")" << "->";
	//֮�����Լ�����ຢ�ӽ��
	//���ж��Ƿ������ڵ�,��������ݹ����
	if (this->pLChild != NULL)
	{
		this->pLChild->PreorderTraversal();//�ݹ����ǰ�����
	}
	//���ж��ҽڵ�,���������ٵݹ����,
	if (this->pRChild != NULL)
	{
		this->pRChild->PreorderTraversal();
	}
	//�����ı�־��Ҷ�ӽڵ�����Һ���ָ�붼ΪNULL
}


/****************************************************************/
/*				InorderTraversal()								*/
/* ����:�������												*/
/* �ص�:�ݹ����												*/
/* ��������:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
void Node::InorderTraversal()
{
	//�������������,���Լ�,Ȼ����
	//����ǰ�����������,����λ�ü���

	//���ж��Ƿ����������,��������ݹ����
	if (this->pLChild != NULL)
	{
		this->pLChild->InorderTraversal();//�ݹ�����������
	}

	//����Լ�������  ������(����)
	cout << this->data << "(" << this->index << ")" << "->";

	//����ж�������,���������ٵݹ����,
	if (this->pRChild != NULL)
	{
		this->pRChild->InorderTraversal();
	}
	//�����ı�־��Ҷ�ӽڵ�����Һ���ָ�붼ΪNULL
}



/****************************************************************/
/*			PostorderTraversal()								*/
/* ����:�������												*/
/* �ص�:�ݹ����												*/
/* ��������:2019-3-14						Author:Cyber Kaka	*/
/****************************************************************/
void Node::PostorderTraversal()
{
	//�������������,����,���
	//����ǰ�����������,����λ�ü���

	//���ж��Ƿ����������,��������ݹ����
	if (this->pLChild != NULL)
	{
		this->pLChild->PostorderTraversal();//�ݹ���ú������
	}
	//���ж�������,���������ٵݹ����,
	if (this->pRChild != NULL)
	{
		this->pRChild->PostorderTraversal();
	}
	//����Լ�������  ������(����)
	cout << this->data << "(" << this->index << ")" << "->";
	//�����ı�־��Ҷ�ӽڵ�����Һ���ָ�붼ΪNULL
}