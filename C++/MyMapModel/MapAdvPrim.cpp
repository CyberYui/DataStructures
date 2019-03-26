#include <iostream>
#include <vector>
#include "MapAdvPrim.h"
using namespace std;

/****************************************************************/
/* CMap(int capacity)											*/
/* 功能:初始化图												*/
/* 																*/
/* 创建日期:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
CMap::CMap(int capacity)
{
	//传入最大容纳顶点数
	m_iCapacity = capacity;
	m_iNodeCount = 0;//初始顶点为0

	//存储结点的数组,通过new分配内存
	m_pNodeArray = new Node[m_iCapacity];//分配出图的相应内存

	//分配出邻接矩阵的内存,大小为行列相同的正方形区域
	m_pMatrix = new int[m_iCapacity*m_iCapacity];//分配出邻接矩阵的内存

	//将邻接矩阵初始化,即将每个位置的元素初始化为0即可
	//memset=memory set(内存设定),设定给m_pMatrix,值都设定为0
	//内存大小为m_iCapacity*m_iCapacity * sizeof(int)
	//即不仅需要设定数据域的大小,还要算上数据类型的大小
	//memset(m_pMatrix, 0, m_iCapacity*m_iCapacity * sizeof(int));//邻接矩阵存值

	//或者这样,使用循环赋值
	for (int i = 0; i < m_iCapacity * m_iCapacity; i++)
	{
		m_pMatrix[i] = 0;
	}

	//普里姆生成树边的个数为n-1
	m_pEdge = new Edge[m_iCapacity - 1];
}


/****************************************************************/
/* ~CMap()														*/
/* 功能:删除指针,释放内存										*/
/*																*/
/* 创建日期:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
CMap::~CMap()
{
	//释放结点和邻接矩阵的内存
	delete[]m_pNodeArray;
	delete[]m_pMatrix;
}


/****************************************************************/
/* addNode(Node *pNode)											*/
/* 功能:添加传入的结点数据到图中顶点中来						*/
/* [注意]传入的是一个Node的指针									*/
/* 创建日期:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
bool CMap::addNode(Node *pNode)
{
	//不能传入指针,因为这个pNode是外部数据,很容易因为操作而被损坏
	//因此要存入图中的顶点,因为这个内存是由图控制的,外部无法控制

	//将传入的pNode的相应数据传给图中的顶点
	//先判断一下pNode是否为空
	if (pNode == NULL)
	{
		return false;
	}
	//可见顶点的索引就是m_pNodeArray这个结点数组的下标
	//比如放入第一个顶点,下标m_iNodeCount就是0,放入第n个.下标就是n-1
	m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
	//计数器+1
	m_iNodeCount++;
	//传入成功,返回true
	return true;
}


/****************************************************************/
/* resetNode()													*/
/* 功能:重置顶点,循环将顶点均重置为未被访问过					*/
/* 																*/
/* 创建日期:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
void CMap::resetNode()
{
	//循环将所有顶点的访问标识置为未访问false状态
	for (int i = 0; i < m_iNodeCount; i++)
	{
		m_pNodeArray[i].m_bIsVisited = false;
	}
}

/****************************************************************/
/* setValueToMatrixForDirectedGraph(int row, int col, int val)	*/
/* 功能:为有向图设置邻接矩阵,row代表行,col代表列,val表示权值,其	*/
/*		默认为1													*/
/* 																*/
/* 创建日期:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
bool CMap::setValueToMatrixForDirectedGraph(int row, int col, int val)
{
	//注意,在定义的时候m_pMatrix对应的是一个一维数组
	//所以在算行列其实只是某一个位置的数而已
	//而这个位置的计算是row*m_iCapacity + col

	//当然,也需要判断row和col的合法性
	if (row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	//整个矩阵是m_iCapacity*m_iCapacity,那么具体的位置
	//就可以定位为行*宽+列的偏移,注意row和col是从0开始算的
	m_pMatrix[row*m_iCapacity + col] = val;
	return true;
}


/****************************************************************/
/* setValueToMatrixForUndirectedGraph(int row, int col, int val)*/
/* 功能:为无向图设置邻接矩阵,row代表行,col代表列,val表示权值,其	*/
/*		默认为1													*/
/* 																*/
/* 创建日期:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
bool CMap::setValueToMatrixForUndirectedGraph(int row, int col, int val)
{
	//理由同上
	//当然,也需要判断row和col的合法性
	if (row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	//由于无向图是双向的,所以要给对称位置也赋值
	m_pMatrix[row*m_iCapacity + col] = val;
	//即行列互换即可
	m_pMatrix[col*m_iCapacity + row] = val;
	return true;
}


/****************************************************************/
/* bool getValueFromMatrix(int row, int col, int &val)			*/
/* 功能:从邻接矩阵中获取权值									*/
/* 																*/
/* 创建日期:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
bool CMap::getValueFromMatrix(int row, int col, int &val)
{
	//指定相应的行列,看看相应的内容在邻接矩阵上的值是多少
	//即val,如果为0则表示当前标记的行列对应的顶点不相连,反之相连
	//当然,也需要判断row和col的合法性
	if (row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	if (col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	//相连的权值,由邻接矩阵中取得
	val = m_pMatrix[row*m_iCapacity + col];
	return true;
}


/****************************************************************/
/* void printMatrix()											*/
/* 功能:打印邻接矩阵											*/
/* 																*/
/* 创建日期:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
void CMap::printMatrix()
{
	//这里的遍历数组应该可以再进行优化,使其能随机产出顶点字符
	//遍历的字符数组,每次使用都需要修改它
	char Row[] = "ABCDEF";//定义遍历数组
	cout << "  A   B   C   D   E   F" << endl;
	//按照行和列打印即可,利用二重循环可以打印出一个矩阵状的格式
	for (int i = 0; i < m_iCapacity; i++)
	{
		cout << Row[i];
		for (int k = 0; k < m_iCapacity; k++)
		{
			//可见是打印第i行,第k列
			cout << "[" << m_pMatrix[i*m_iCapacity + k] << "]" << " ";
		}
		cout << endl;
	}
}


/****************************************************************/
/* void depthFirstTraverse(int nodeIndex)						*/
/* 功能:深度优先遍历搜索,类似于树的前序遍历						*/
/* 重点:递归访问子树											*/
/* 创建日期:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
void CMap::depthFirstTraverse(int nodeIndex)
{
	//对于Demo1中的图来说,深度优先搜索应该是A->B->C->E->F->D->G->H
	//由于其搜索的层次不确定,所以使用递归的方式解决问题

	int value = 0;//定义权值的临时保存变量
	//首先输出第一个顶点的数据,然后将其置为已访问
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	//遍历之后的顶点
	for (int i = 0; i < m_iCapacity; i++)
	{
		//首先获取nodeIndex*m_iCapacity+i这个位置的权值,赋值给value
		getValueFromMatrix(nodeIndex, i, value);
		//判断此位置权值是否不等于0,即val是否为0
		//不等于则表示有边,有边就需要遍历访问
		if (value != 0)
		{
			//判断其是否被访问过
			if (m_pNodeArray[i].m_bIsVisited/*==true*/)
			{
				//若被访问过,则继续遍历之后的顶点和此顶点是否有边
				continue;
			}
			else
			{
				//如果未被访问过,则对此顶点继续进行深度优先搜索
				//直到形成环路的顶点为止,因为要形成环路,势必会遇到已访问的顶点
				depthFirstTraverse(i);
			}
		}
		else
		{
			//如果某个位置无边,则继续遍历之后的顶点和此顶点是否有边
			continue;
		}
	}
}


/****************************************************************/
/* void breadthFirstTraverse(int nodeIndex)						*/
/* 功能:广度优先遍历搜索										*/
/* [注意]广度优先遍历较深度优先遍历要更复杂一些					*/
/* 创建日期:2019-3-15						Author:Cyber Kaka	*/
/****************************************************************/
void CMap::breadthFirstTraverse(int nodeIndex)
{
	//对于Demo1中的图来说,广度优先搜索应该是A->B->D->C->F->G->H->E
	//由于其搜索的层次不确定,所以使用递归的方式解决问题

	//具体的实现是:首先访问A,将其存入一个数组
	//发现第一层只有A一个顶点,于是数组中仅仅保存A
	//将A从数组中取出,通过邻接矩阵找到相应的与A连接的顶点B和D
	//分别访问B,D,同时将B和D放入一个新的数组中
	//[注意]这个数组和A所在的数组是不同的
	//首先从第二层数组中拿出B,找到与B相连接的C和F,并访问C和F
	//同时将C与F放入一个新的数组,即第三层数组中
	//然后再从第二层数组中取出D,找到与D相连接的G和H,并访问G和H
	//将G和H放到C与F的这个第三层数组中
	//这样发现第二层两个顶点访问完了,接下来
	//再将C从第三层数组中取出,找到E,并将E放到新的第四层数组中
	//再将F从第三层数组中取出,发现与F相连的E被访问过了
	//再找G,发现与G相连的H被访问过了
	//再找H,发现与H相连的G被访问过了,从而第三层顶点访问完了
	//这时再访问E,发现没有和E相连的下层顶点,搜索结束

	//依然是首先访问nodeIndex对应的顶点,并将其置为已被访问
	cout << m_pNodeArray[nodeIndex].m_cData << " ";
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	//将当前的结点保存在一个数组中,仅仅保存结点索引即可
	vector<int> curVec;
	curVec.push_back(nodeIndex);

	breadthFirstTraverseImpl(curVec);
}


/****************************************************************/
/* void breadthFirstTraverseImpl(vector<int> preVec)			*/
/* 功能:广度优先遍历搜索的实际实现函数							*/
/* 																*/
/* 创建日期:2019-3-16						Author:Cyber Kaka	*/
/****************************************************************/
void CMap::breadthFirstTraverseImpl(vector<int> preVec)
{
	//定义临时的权值保存变量
	int value = 0;
	//定义vector数组
	vector<int> curVec;

	//遍历图,preVec即上一层的顶点数组,强制类型转换为int型,size()类型是vector
	for (int j = 0; j < (int)preVec.size(); j++)
	{
		//对前一层的数组preVec内的每个顶点进行广度优先遍历
		for (int i = 0; i < m_iCapacity; i++)
		{
			//循环判断传入的preVec中的顶点与其他顶点是否连接
			getValueFromMatrix(preVec[j], i, value);
			if (value != 0)
			{
				//若不等,则再判断顶点是否被访问过
				if (m_pNodeArray[i].m_bIsVisited)
				{
					//跳过被访问过的顶点
					continue;
				}
				else
				{
					//否则输出数据,并将顶点置为被访问
					cout << m_pNodeArray[i].m_cData << " ";
					m_pNodeArray[i].m_bIsVisited = true;
					//将当前连接的顶点放入当前的curVec数组
					//即放入索引即可表示放入顶点了
					curVec.push_back(i);
					//存点完成,接下来继续遍历下一层内容
				}
			}
		}
		//至此,对前一层的顶点进行遍历完成
	}
	//判断当前的数组保存的顶点个数是否为0,若为0则表示本层无顶点,跳出函数
	if ((int)curVec.size() == 0)
	{
		return;
	}
	else
	{
		//本层有点,则递归调用广度优先遍历
		breadthFirstTraverseImpl(curVec);
	}
}


/****************************************************************/
/* void primTree(int nodeIndex)									*/
/* 功能:普里姆生成树的实现函数									*/
/* 																*/
/* 创建日期:2019-3-16						Author:Cyber Kaka	*/
/****************************************************************/
void CMap::primTree(int nodeIndex)
{
	//边的权值的临时变量
	int value = 0;
	//定义一个数边的临时变量
	int edgeCount = 0;
	//放点的数组,理论上存点,逻辑上是存其索引
	//使用标准模版定义,给最小生成树保存顶点和边
	vector<int> nodeVec;	//存顶点的数组
	vector<Edge> edgeVec;	//存边的数组
	//打印传入的第一个顶点的数据
	//m_pNodeArray是图中保存顶点的数组
	cout << m_pNodeArray[nodeIndex].m_cData << endl;
	//将nodeIndex放入nodeVec中
	nodeVec.push_back(nodeIndex);
	//将当前点置为被访问
	m_pNodeArray[nodeIndex].m_bIsVisited = true;
	//最终拿到的边数,即edgeCount如果等于当前顶点数-1,则停止
	while (edgeCount < m_iCapacity - 1)
	{
		//用临时变量存储每一个点的索引
		int temp = nodeVec.back();//从nodeVec数组中取出最后的元素
		//寻找与该顶点连接的所有边
		//从第一个顶点开始遍历,一个顶点一个顶点地进行寻边
		for (int i = 0; i < m_iCapacity; i++)
		{
			//首先获取权值,并判断权值是否合法
			getValueFromMatrix(temp, i, value);
			if (value != 0)
			{
				if (m_pNodeArray[i].m_bIsVisited/*==true*/)
				{
					continue;
				}
				else
				{
					//定义一条边,将起点设置为temp
					//终点设置为i,权值为保存的value的值
					Edge edge(temp, i, value);
					//将得到的边存入保存边的数组中
					edgeVec.push_back(edge);
				}
			}
		}
		//从备选边的集合中找到最小权值的边,理论是存边,实际是存索引
		int edgeIndex = getMinEdge(edgeVec);
		//将边置为被选择状态
		edgeVec[edgeIndex].m_bSelected = true;
		//找到最小边之后,打印其相连的两个顶点以及边的权值
		cout << edgeVec[edgeIndex].m_iNodeIndexA;//开始点
		cout << "---->" << edgeVec[edgeIndex].m_iNodeIndexB;//终点
		cout << "(" << edgeVec[edgeIndex].m_iWeightValue << ")" << endl;//权值
		//将当前的这条边放到最小生成树的集合中
		m_pEdge[edgeCount] = edgeVec[edgeIndex];
		//边计数+1
		edgeCount++;
		//找到与当前最小边相连接的点
		int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;
		//将当前找到的这个点放入点的集合中
		nodeVec.push_back(nextNodeIndex);
		//将当前点置为被访问
		m_pNodeArray[nextNodeIndex].m_bIsVisited = true;
		//打印该点对应的数据
		cout << m_pNodeArray[nextNodeIndex].m_cData << endl;
	}
}


/****************************************************************/
/* int getMinEdge(vector<Edge> edgeVec)							*/
/* 功能:从一个边数组中获取最小边的索引							*/
/* 																*/
/* 创建日期:2019-3-16						Author:Cyber Kaka	*/
/****************************************************************/
int CMap::getMinEdge(vector<Edge> edgeVec)
{
	//定义保存最小权值的临时变量
	int minWeight = 0;
	//定义保存最小权值边的索引的临时变量
	int edgeIndex = 0;
	//先找到第一条没有被访问过的边
	unsigned int i = 0;//因为之后还要用到i,所以把i定义在外部
	for (i = 0; i < (edgeVec.size()); i++)
	{
		if (!edgeVec[i].m_bSelected)
		{
			//如果为假则说明这条边还没被选出来过
			minWeight = edgeVec[i].m_iWeightValue;
			//记录一下当前最小权值那条边的索引
			edgeIndex = i;
			//找到之后就可以跳出循环了
			break;
		}
		//如果没有找到,那就继续循环
	}
	//这样选出了一条没有被访问过的边
	//判断一下取到的权值,如果还是为初始值0的话
	//证明没有取到新边,也就是说所有边都被选过了,就返回-1
	if (minWeight == 0)
	{
		return -1;
	}
	//如果取到了新边,则进行接下来的操作
	//接下来拿别的没有被访问过的边与其对比
	//这时选的边应该是i在上次循环之后的边
	for (; i < (edgeVec.size()); i++)
	{
		//首先判断现在选的边是否被选过
		if (edgeVec[i].m_bSelected)
		{
			//若被选过,则直接找下一条
			continue;
		}
		else
		{
			//如果当前边的权值小于保存的minWeight
			if (minWeight > edgeVec[i].m_iWeightValue)
			{
				//将当前边的权值赋值给minWeight
				minWeight = edgeVec[i].m_iWeightValue;
				//并将最小边的索引更改为当前边
				edgeIndex = i;
			}
		}
	}
	//最后返回这条边的索引即可
	return edgeIndex;
}