#include "bfs_graphlist.h"
#include <stdio.h>

/*
//��Ϊ��ͷ�巨,����Ҫ��������
0 3
0 2
0 1
1 3
1 2
1 0
2 1
2 0
3 0
3 1
-1 -1
���ͼ��ͼ�����ͬ��Ŀ¼�µ�Graph_4.png
*/
int main(void)
{
	GraphList *graphList = NULL;

	graphList = InitGraph(4);

	ReadGraph(graphList);

	BFSGraphList(graphList);

	printf("\n");
	return 0;
}