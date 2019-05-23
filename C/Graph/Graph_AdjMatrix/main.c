#include "GraphAdjMatrixUtil.h"
#include <stdio.h>

//输入的内容:
/*
0 1 1
1 0 1
0 2 1
2 0 1
0 3 1
3 0 1
2 3 1
3 2 1
0 0 0 //结束
*/

/*
ARC1:
   A B C D
A [0 1 1 1]
B [1 0 0 0]
C [1 0 0 1]
D [1 0 1 0]
>>可以在内存中对应这些内容
*/
int main(void)
{
	GraphMatrix *graphMatrix = NULL;
	graphMatrix = InitGraph(4);
	ReadGraph(graphMatrix);
	WriteGraph(graphMatrix);
	printf("\n");
	return 0;
}