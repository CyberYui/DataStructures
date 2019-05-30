#include <stdio.h>
#include <stdlib.h>
#include "graphmatrixutil.h"

/*
0 1 5
1 0 5
0 2 30
2 0 30
0 3 14
3 0 14
1 2 24
2 1 24
2 3 17
3 2 17
1 4 14
4 1 14
1 5 10
5 1 10
4 5 25
5 4 25
2 5 17
5 2 17
3 5 8
5 3 8
0 0 0
//图的具体内容见同名目录下的Graph_6.png文件
*/
int main(void)
{
	GraphMatrix *graphMatrix = NULL;
	GraphMatrix *tree = NULL;
	tree = InitGraph(6);
	graphMatrix = InitGraph(6);
	ReadGraph(graphMatrix);

	tree = prim(1, graphMatrix);

	WriteGraph(tree);

	return 0;
}