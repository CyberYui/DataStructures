#include <iostream>
#include <vector>
#include "MapAdvPrim.h"
using namespace std;

/****************************************************************/
/* CMap(int capacity)											*/
/* ����:��ʼ��ͼ												*/
/* 																*/
/* ��������:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
CMap::CMap(int capacity)
{
	//����������ɶ�����
	m_iCapacity = capacity;
	m_iNodeCount = 0;//��ʼ����Ϊ0

	//�洢��������,ͨ��new�����ڴ�
	m_pNodeArray = new Node[m_iCapacity];//�����ͼ����Ӧ�ڴ�

	//������ڽӾ�����ڴ�,��СΪ������ͬ������������
	m_pMatrix = new int[m_iCapacity*m_iCapacity];//������ڽӾ�����ڴ�

	//���ڽӾ����ʼ��,����ÿ��λ�õ�Ԫ�س�ʼ��Ϊ0����
	//memset=memory set(�ڴ��趨),�趨��m_pMatrix,ֵ���趨Ϊ0
	//�ڴ��СΪm_iCapacity*m_iCapacity * sizeof(int)
	//��������Ҫ�趨������Ĵ�С,��Ҫ�����������͵Ĵ�С
	//memset(m_pMatrix, 0, m_iCapacity*m_iCapacity * sizeof(int));//�ڽӾ����ֵ

	//��������,ʹ��ѭ����ֵ
	for (int i = 0; i < m_iCapacity * m_iCapacity; i++)
	{
		m_pMatrix[i] = 0;
	}

	//����ķ�������ߵĸ���Ϊn-1
	m_pEdge = new Edge[m_iCapacity - 1];
}


/****************************************************************/
/* ~CMap()														*/
/* ����:ɾ��ָ��,�ͷ��ڴ�										*/
/*																*/
/* ��������:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
CMap::~CMap()
{
	//�ͷŽ����ڽӾ�����ڴ�
	delete[]m_pNodeArray;
	delete[]m_pMatrix;
}


/****************************************************************/
/* addNode(Node *pNode)											*/
/* ����:��Ӵ���Ľ�����ݵ�ͼ�ж�������						*/
/* [ע��]�������һ��Node��ָ��									*/
/* ��������:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
bool CMap::addNode(Node *pNode)
{
	//���ܴ���ָ��,��Ϊ���pNode���ⲿ����,��������Ϊ����������
	//���Ҫ����ͼ�еĶ���,��Ϊ����ڴ�����ͼ���Ƶ�,�ⲿ�޷�����

	//�������pNode����Ӧ���ݴ���ͼ�еĶ���
	//���ж�һ��pNode�Ƿ�Ϊ��
	if (pNode == NULL)
	{
		return false;
	}
	//�ɼ��������������m_pNodeArray������������±�
	//��������һ������,�±�m_iNodeCount����0,�����n��.�±����n-1
	m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
	//������+1
	m_iNodeCount++;
	//����ɹ�,����true
	return true;
}


/****************************************************************/
/* resetNode()													*/
/* ����:���ö���,ѭ�������������Ϊδ�����ʹ�					*/
/* 																*/
/* ��������:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
void CMap::resetNode()
{
	//ѭ�������ж���ķ��ʱ�ʶ��Ϊδ����false״̬
	for (int i = 0; i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

/****************************************************************/
/* setValueToMatrixForDirectedGraph(int row, int col, int val)	*/
/* ����:Ϊ����ͼ�����ڽӾ���,row������,col������,val��ʾȨֵ,��	*/
/*		Ĭ��Ϊ1													*/
/* 																*/
/* ��������:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
	//ע��,�ڶ����ʱ��m_pMatrix��Ӧ����һ��һά����
	//��������������ʵֻ��ĳһ��λ�õ�������
	//�����λ�õļ�����row*m_iCapacity + col

	//��Ȼ,Ҳ��Ҫ�ж�row��col�ĺϷ���
	if (row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	//����������m_iCapacity*m_iCapacity,��ô�����λ��
	//�Ϳ��Զ�λΪ��*��+�е�ƫ��,ע��row��col�Ǵ�0��ʼ���
	m_pMatrix[row*m_iCapacity + col] = val;
	return true;
}


/****************************************************************/
/* setValueToMatrixForUndirectedGraph(int row, int col, int val)*/
/* ����:Ϊ����ͼ�����ڽӾ���,row������,col������,val��ʾȨֵ,��	*/
/*		Ĭ��Ϊ1													*/
/* 																*/
/* ��������:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	//����ͬ��
	//��Ȼ,Ҳ��Ҫ�ж�row��col�ĺϷ���
	if (row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	//��������ͼ��˫���,����Ҫ���Գ�λ��Ҳ��ֵ
	m_pMatrix[row*m_iCapacity + col] = val;
	//�����л�������
	m_pMatrix[col*m_iCapacity + row] = val;
	return true;
}


/****************************************************************/
/* bool getValueFromMatrix(int row, int col, int &val)			*/
/* ����:���ڽӾ����л�ȡȨֵ									*/
/* 																*/
/* ��������:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
bool CMap::getValueFromMatrix(int row, int col, int &val)
{
	//ָ����Ӧ������,������Ӧ���������ڽӾ����ϵ�ֵ�Ƕ���
	//��val,���Ϊ0���ʾ��ǰ��ǵ����ж�Ӧ�Ķ��㲻����,��֮����
	//��Ȼ,Ҳ��Ҫ�ж�row��col�ĺϷ���
	if (row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	//������Ȩֵ,���ڽӾ�����ȡ��
	val = m_pMatrix[row*m_iCapacity + col];
	return true;
}


/****************************************************************/
/* void printMatrix()											*/
/* ����:��ӡ�ڽӾ���											*/
/* 																*/
/* ��������:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
void CMap::printMatrix()
{
	//����ı�������Ӧ�ÿ����ٽ����Ż�,ʹ����������������ַ�
	//�������ַ�����,ÿ��ʹ�ö���Ҫ�޸���
	char Row[] = "ABCDEF";//�����������
	cout << "  A   B   C   D   E   F" << endl;
	//�����к��д�ӡ����,���ö���ѭ�����Դ�ӡ��һ������״�ĸ�ʽ
	for (int i = 0; i < m_iCapacity; i++)
	{
		cout << Row[i];
		for (int k = 0; k < m_iCapacity; k++)
		{
			//�ɼ��Ǵ�ӡ��i��,��k��
			cout << "[" << m_pMatrix[i*m_iCapacity + k] << "]" << " ";
		}
		cout << endl;
	}
}


/****************************************************************/
/* void depthFirstTraverse(int nodeIndex)						*/
/* ����:������ȱ�������,����������ǰ�����						*/
/* �ص�:�ݹ��������											*/
/* ��������:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
void CMap::depthFirstTraverse(int nodeIndex)
{
	//����Demo1�е�ͼ��˵,�����������Ӧ����A->B->C->E->F->D->G->H
	//�����������Ĳ�β�ȷ��,����ʹ�õݹ�ķ�ʽ�������

	int value = 0;//����Ȩֵ����ʱ�������
	//���������һ�����������,Ȼ������Ϊ�ѷ���
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	//����֮��Ķ���
	for (int i = 0; i < m_iCapacity; i++)
	{
		//���Ȼ�ȡnodeIndex*m_iCapacity+i���λ�õ�Ȩֵ,��ֵ��value
		getValueFromMatrix(nodeIndex, i, value);
		//�жϴ�λ��Ȩֵ�Ƿ񲻵���0,��val�Ƿ�Ϊ0
		//���������ʾ�б�,�б߾���Ҫ��������
		if (value != 0)
		{
			//�ж����Ƿ񱻷��ʹ�
			if (m_pNodeArray[i].m_bIsVisited/*==true*/)
			{
				//�������ʹ�,���������֮��Ķ���ʹ˶����Ƿ��б�
				continue;
			}
			else
			{
				//���δ�����ʹ�,��Դ˶���������������������
				//ֱ���γɻ�·�Ķ���Ϊֹ,��ΪҪ�γɻ�·,�Ʊػ������ѷ��ʵĶ���
				depthFirstTraverse(i);
			}
		}
		else
		{
			//���ĳ��λ���ޱ�,���������֮��Ķ���ʹ˶����Ƿ��б�
			continue;
		}
	}
}


/****************************************************************/
/* void breadthFirstTraverse(int nodeIndex)						*/
/* ����:������ȱ�������										*/
/* [ע��]������ȱ�����������ȱ���Ҫ������һЩ					*/
/* ��������:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
void CMap::breadthFirstTraverse(int nodeIndex)
{
	//����Demo1�е�ͼ��˵,�����������Ӧ����A->B->D->C->F->G->H->E
	//�����������Ĳ�β�ȷ��,����ʹ�õݹ�ķ�ʽ�������

	//�����ʵ����:���ȷ���A,�������һ������
	//���ֵ�һ��ֻ��Aһ������,���������н�������A
	//��A��������ȡ��,ͨ���ڽӾ����ҵ���Ӧ����A���ӵĶ���B��D
	//�ֱ����B,D,ͬʱ��B��D����һ���µ�������
	//[ע��]��������A���ڵ������ǲ�ͬ��
	//���ȴӵڶ����������ó�B,�ҵ���B�����ӵ�C��F,������C��F
	//ͬʱ��C��F����һ���µ�����,��������������
	//Ȼ���ٴӵڶ���������ȡ��D,�ҵ���D�����ӵ�G��H,������G��H
	//��G��H�ŵ�C��F�����������������
	//�������ֵڶ������������������,������
	//�ٽ�C�ӵ�����������ȡ��,�ҵ�E,����E�ŵ��µĵ��Ĳ�������
	//�ٽ�F�ӵ�����������ȡ��,������F������E�����ʹ���
	//����G,������G������H�����ʹ���
	//����H,������H������G�����ʹ���,�Ӷ������㶥���������
	//��ʱ�ٷ���E,����û�к�E�������²㶥��,��������

	//��Ȼ�����ȷ���nodeIndex��Ӧ�Ķ���,��������Ϊ�ѱ�����
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	//����ǰ�Ľ�㱣����һ��������,������������������
	vector<int> curVec;
	curVec.push_back(nodeIndex);

	breadthFirstTraverseImpl(curVec);
}


/****************************************************************/
/* void breadthFirstTraverseImpl(vector<int> preVec)			*/
/* ����:������ȱ���������ʵ��ʵ�ֺ���							*/
/* 																*/
/* ��������:2019-3-16						Author:Cyber Kaka	*/
/****************************************************************/
void CMap::breadthFirstTraverseImpl(vector<int> preVec)
{
	//������ʱ��Ȩֵ�������
	int value = 0;
	//����vector����
	vector<int> curVec;

	//����ͼ,preVec����һ��Ķ�������,ǿ������ת��Ϊint��,size()������vector
	for (int j = 0; j < (int)preVec.size(); j++)
	{
		//��ǰһ�������preVec�ڵ�ÿ��������й�����ȱ���
		for (int i = 0; i < m_iCapacity; i++)
		{
			//ѭ���жϴ����preVec�еĶ��������������Ƿ�����
			getValueFromMatrix(preVec[j], i, value);
			if (value != 0)
			{
				//������,�����ж϶����Ƿ񱻷��ʹ�
				if (m_pNodeArray[i].m_bIsVisited)
				{
					//���������ʹ��Ķ���
					continue;
				}
				else
				{
					//�����������,����������Ϊ������
					cout << m_pNodeArray[i].m_cData << " ";
					m_pNodeArray[i].m_bIsVisited = true;
					//����ǰ���ӵĶ�����뵱ǰ��curVec����
					//�������������ɱ�ʾ���붥����
					curVec.push_back(i);
					//������,����������������һ������
				}
			}
		}
		//����,��ǰһ��Ķ�����б������
	}
	//�жϵ�ǰ�����鱣��Ķ�������Ƿ�Ϊ0,��Ϊ0���ʾ�����޶���,��������
	if ((int)curVec.size() == 0)
	{
		return;
	}
	else
	{
		//�����е�,��ݹ���ù�����ȱ���
		breadthFirstTraverseImpl(curVec);
	}
}


/****************************************************************/
/* void primTree(int nodeIndex)									*/
/* ����:����ķ��������ʵ�ֺ���									*/
/* 																*/
/* ��������:2019-3-16						Author:Cyber Kaka	*/
/****************************************************************/
void CMap::primTree(int nodeIndex)
{
	//�ߵ�Ȩֵ����ʱ����
	int value = 0;
	//����һ�����ߵ���ʱ����
	int edgeCount = 0;
	//�ŵ������,�����ϴ��,�߼����Ǵ�������
	//ʹ�ñ�׼ģ�涨��,����С���������涥��ͱ�
	vector<int> nodeVec;	//�涥�������
	vector<Edge> edgeVec;	//��ߵ�����
	//��ӡ����ĵ�һ�����������
	//m_pNodeArray��ͼ�б��涥�������
	cout << m_pNodeArray[nodeIndex].m_cData << endl;
	//��nodeIndex����nodeVec��
	nodeVec.push_back(nodeIndex);
	//����ǰ����Ϊ������
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	//�����õ��ı���,��edgeCount������ڵ�ǰ������-1,��ֹͣ
	while (edgeCount < m_iCapacity - 1)
	{
		//����ʱ�����洢ÿһ���������
		int temp = nodeVec.back();//��nodeVec������ȡ������Ԫ��
		//Ѱ����ö������ӵ����б�
		//�ӵ�һ�����㿪ʼ����,һ������һ������ؽ���Ѱ��
		for (int i = 0; i < m_iCapacity; i++)
		{
			//���Ȼ�ȡȨֵ,���ж�Ȩֵ�Ƿ�Ϸ�
			getValueFromMatrix(temp, i, value);
			if (value != 0)
			{
				if (m_pNodeArray[i].m_bIsVisited/*==true*/)
				{
					continue;
				}
				else
				{
					//����һ����,���������Ϊtemp
					//�յ�����Ϊi,ȨֵΪ�����value��ֵ
					Edge edge(temp, i, value);
					//���õ��ıߴ��뱣��ߵ�������
					edgeVec.push_back(edge);
				}
			}
		}
		//�ӱ�ѡ�ߵļ������ҵ���СȨֵ�ı�,�����Ǵ��,ʵ���Ǵ�����
		int edgeIndex = getMinEdge(edgeVec);
		//������Ϊ��ѡ��״̬
		edgeVec[edgeIndex].m_bSelected = true;
		//�ҵ���С��֮��,��ӡ�����������������Լ��ߵ�Ȩֵ
		cout << edgeVec[edgeIndex].m_iNodeIndexA;//��ʼ��
		cout << "---->" << edgeVec[edgeIndex].m_iNodeIndexB;//�յ�
		cout << "(" << edgeVec[edgeIndex].m_iWeightValue << ")" << endl;//Ȩֵ
		//����ǰ�������߷ŵ���С�������ļ�����
		m_pEdge[edgeCount] = edgeVec[edgeIndex];
		//�߼���+1
		edgeCount++;
		//�ҵ��뵱ǰ��С�������ӵĵ�
		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;
		//����ǰ�ҵ������������ļ�����
		nodeVec.push_back(nextNodeIndex);
		//����ǰ����Ϊ������
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true;
		//��ӡ�õ��Ӧ������
		cout << m_pNodeArray[nextNodeIndex].m_cData << endl;
	}
}


/****************************************************************/
/* int getMinEdge(vector<Edge> edgeVec)							*/
/* ����:��һ���������л�ȡ��С�ߵ�����							*/
/* 																*/
/* ��������:2019-3-16						Author:Cyber Kaka	*/
/****************************************************************/
int CMap::getMinEdge(vector<Edge> edgeVec)
{
	//���屣����СȨֵ����ʱ����
	int minWeight = 0;
	//���屣����СȨֵ�ߵ���������ʱ����
	int edgeIndex = 0;
	//���ҵ���һ��û�б����ʹ��ı�
	unsigned int i = 0;//��Ϊ֮��Ҫ�õ�i,���԰�i�������ⲿ
	for (i = 0; i < (edgeVec.size()); i++)
	{
		if (!edgeVec[i].m_bSelected)
		{
			//���Ϊ����˵�������߻�û��ѡ������
			minWeight = edgeVec[i].m_iWeightValue;
			//��¼һ�µ�ǰ��СȨֵ�����ߵ�����
			edgeIndex = i;
			//�ҵ�֮��Ϳ�������ѭ����
			break;
		}
		//���û���ҵ�,�Ǿͼ���ѭ��
	}
	//����ѡ����һ��û�б����ʹ��ı�
	//�ж�һ��ȡ����Ȩֵ,�������Ϊ��ʼֵ0�Ļ�
	//֤��û��ȡ���±�,Ҳ����˵���б߶���ѡ����,�ͷ���-1
	if (minWeight == 0)
	{
		return -1;
	}
	//���ȡ�����±�,����н������Ĳ���
	//�������ñ��û�б����ʹ��ı�����Ա�
	//��ʱѡ�ı�Ӧ����i���ϴ�ѭ��֮��ı�
	for (; i < (edgeVec.size()); i++)
	{
		//�����ж�����ѡ�ı��Ƿ�ѡ��
		if (edgeVec[i].m_bSelected)
		{
			//����ѡ��,��ֱ������һ��
			continue;
		}
		else
		{
			//�����ǰ�ߵ�ȨֵС�ڱ����minWeight
			if (minWeight > edgeVec[i].m_iWeightValue)
			{
				//����ǰ�ߵ�Ȩֵ��ֵ��minWeight
				minWeight = edgeVec[i].m_iWeightValue;
				//������С�ߵ���������Ϊ��ǰ��
				edgeIndex = i;
			}
		}
	}
	//��󷵻������ߵ���������
	return edgeIndex;
}