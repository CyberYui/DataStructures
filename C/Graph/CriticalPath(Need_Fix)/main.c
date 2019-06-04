#include <stdio.h>
#include <stdlib.h>
#include "graphlistutil.h"
#include "graphinverselistutil.h"
#include "LinkedStack.h"
#include "criticalpath.h"

/*计算一个图的关键路径*/
/*
0 1 14
1 5 22
1 2 25
2 3 17
2 6 34
3 4 24
4 7 13
5 6 35
6 4 12
-1 -1 -1
//图的具体内容查看本目录下Graph_8.png
*/

//项目仍有些许问题,需要修改
int main()
{
	GraphList *graphList = InitGraph(8);
	ReadGraph(graphList);
	//WriteGraph(graphList);

	GraphInverseList *graphInverseList = InitInverseGraph(8);
	ReadInverseGraph(graphInverseList);
	//WriteInverseGraph(graphInverseList);

	criticalPath(graphList, graphInverseList);

	int result = 0;

	return 0;
}