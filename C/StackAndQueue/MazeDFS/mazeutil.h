#ifndef MAZE_H
#define MAZE_H

/****************************************************************/
/* 结构名:Maze 或 MAZE_STRU										*/
/* 功能:表示迷宫的结构											*/
/* 创建日期:2019-4-29						Author:Cyber Kaka	*/
/****************************************************************/
typedef struct MAZE_STRU
{
	int size;	//迷宫大小
	int **data;	//二维数组保存迷宫结构
}Maze;

/*************************************************/
/* 函数名:		InitMaze(int size)
/* 函数功能:	初始化迷宫,分配空间,并将所有点置为0
/* 输入参数		size--迷宫大小
/* 返回值:		用邻接矩阵表示的图
/*************************************************/
Maze* InitMaze(int size);

/*************************************************/
/* 函数名:		ReadMaze(Maze* maze)
/* 函数功能:	读入迷宫结构,0代表可以走的路,1代表墙
/* 输入参数		maze--二维数组表示的地图
/* 返回值:		无
/*************************************************/
void ReadMaze(Maze* maze);

/*************************************************/
/* 函数名:		WriteMaze(Maze* maze)
/* 函数功能:	将迷宫的结构显示出来
/* 输入参数		maze--迷宫
/* 返回值:		无
/*************************************************/
void WriteMaze(Maze* maze);

/*********************************************************************/
/* MazeDFS(int entryX, int entryY, int exitX, int exitY, Maze* maze) */
/* 功能:深度优先搜索路径											 */
/* 输入参数maze--迷宫结构											 */
/*		   entryX,entryY--迷宫入口的x和y坐标						 */
/*		   exitX,exitY--迷宫出口的x和y坐标							 */
/* 返回值:没有路径则返回0,有路径则返回1								 */
/* 创建日期:2019-4-29						Author:Cyber Kaka		 */
/*********************************************************************/
int MazeDFS(int entryX, int entryY, int exitX, int exitY, Maze* maze);

#endif	// MAZE_H
