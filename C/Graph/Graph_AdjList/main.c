#include "GraphAdjListUtil.h"
#include <stdio.h>

/*
0 1
1 2
2 3
2 0
-1 -1
//因为采用的是头插法,所以输入2 3和2 0才能使邻接表为2-->0->3
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