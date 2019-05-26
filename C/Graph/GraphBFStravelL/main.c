#include "bfs_graphlist.h"
#include <stdio.h>

/*
//因为是头插法,所以要倒着输入
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
相关图的图像参照同名目录下的Graph_4.png
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