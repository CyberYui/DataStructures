#include "bfs_graphmatrix.h"
#include <stdio.h>

/*
0 1 1
1 0 1
0 2 1
2 0 1
1 3 1
3 1 1
1 4 1
4 1 1
3 7 1
7 3 1
4 7 1
7 4 1
2 5 1
5 2 1
2 6 1
6 2 1
8 9 1
9 8 1
8 10 1
10 8 1
9 10 1
10 9 1
0 0 0
相关图的图像参照同名目录下的Graph_11.png
*/
int main(void)
{
	GraphMatrix *graphMatrix = NULL;

	graphMatrix = InitGraph(11);

	ReadGraph(graphMatrix);

	BFSGraphMatrix(graphMatrix);

	printf("\n");
	return 0;
}