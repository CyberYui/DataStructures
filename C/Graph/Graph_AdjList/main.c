#include "GraphAdjListUtil.h"
#include <stdio.h>

/*
0 1
1 2
2 3
2 0
-1 -1
//��Ϊ���õ���ͷ�巨,��������2 3��2 0����ʹ�ڽӱ�Ϊ2-->0->3
*/
int main(void)
{
	GraphList *graphList = NULL;
	graphList = InitGraph(4);
	ReadGraph(graphList);
	WriteGraph(graphList);
	printf("\n");
	return 0;
}