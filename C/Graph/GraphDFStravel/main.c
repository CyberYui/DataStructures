#include <stdio.h>
#include "dfs_graphmatrix.h"
#include "graphmatrixutil.h"

/*
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
具体的图请见同目录下Graph_11.png
*/
int main(void)
{
	GraphMatrix *graphMatrix = NULL;
	graphMatrix = InitGraph(11);

	ReadGraph(graphMatrix);

	DFSGraphMatrix(graphMatrix);
	printf("\n");

	return 0;
}