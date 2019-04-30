#include <stdlib.h>
#include <stdio.h>
#include "LinkedStack.h"
#include "mazeutil.h"

void main()
{
	Maze *maze;
	int mazeSize = 0;//定义并初始化迷宫大小
	//定义并初始化入口和出口
	int entryX = 0;
	int entryY = 0;
	int exitX = 0;
	int exitY = 0;
	int find = 0;
	printf("请输入迷宫大小:");
	scanf_s("%d", &mazeSize);//读取输入的迷宫大小
	maze = InitMaze(mazeSize);//初始化迷宫
	ReadMaze(maze);//读取迷宫
	printf("输入的迷宫结构如下:\n");
	printf("请输入迷宫的入口点x,y,出口点x,y:\n");
	scanf_s("%d%d%d%d", &entryX, &entryY, &exitX, &exitY);//读入入口和出口
	//深度优先搜索
	find = MazeDFS(entryX, entryY, exitX, exitY, maze);

	system("pause");
	return 0;
}