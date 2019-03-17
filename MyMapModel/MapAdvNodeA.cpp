#include "MapAdvNodeA.h"

Node::Node(char data)
{
	//初始化一个顶点
	m_cData = data;
	m_bIsVisited = false;//false表示未被访问
}