#include <stdlib.h>
#include <stdio.h>
#include "mazeutil.h"
#include "LinkedStack.h"

//迷宫深度遍历算法
int MazeDFS(int entryX, int entryY, int exitX, int exitY, Maze* maze)
{
	//定义八个方向的二维数组
	//数字代表增量,例如东边(→)就是(x,y+1),增量为{0,1}
	int direction[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
	//建立两个链栈,分别保存路径中点的(x,y)的值
	LinkedStack linkStackX = NULL;
	LinkedStack linkStackY = NULL;
	//创建并初始化临时变量,用于存放坐标
	int posX = 0;//pos指现在所在的位置
	int posY = 0;
	int preposX = 0;//prepos指之前探索的位置,便于回头
	int preposY = 0;
	//建立一个标记二维数组的指针,用于修改走过的路径,不重复走路
	int **mark;
	//建立循环变量并初始化
	int i = 0;
	int j = 0;
	//标记移动方向的变量
	int mov = 0;//0代表正东,即右边→
	//给二维数组分配空间,并赋初值
	mark = (int **)malloc(sizeof(int*)* maze->size);
	for (i = 0; i < maze->size; i++)
	{
		mark[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	//循环,给所有元素赋初值
	for (i = 0; i < maze->size; i++)
	{
		for (j = 0; j < maze->size; j++)
		{
			mark[i][j] = 0;
		}
	}
	//初始化栈
	linkStackX = SetNullStack_Link();
	linkStackY = SetNullStack_Link();
	//给入口点设置标志位,入口坐标是作为参数传入的
	mark[entryX][entryY] = 1;//入口也算是走过的,所以标志变为1
	//起点坐标入栈
	Push_link(linkStackX, entryX);//横坐标进横坐标栈
	Push_link(linkStackY, entryY);//纵坐标进纵坐标栈
	//判断两个栈是否对应为空,不为空代表没有找到出口
	//while (!IsNullStack_link(linkStackX) && !IsNullStack_link(linkStackY))
	while (!IsNullStack_link(linkStackX))//只需要判断一个,因为入栈和出栈都是成对的
	{
		//取栈顶元素
		preposX = Pop_seq_return(linkStackX);
		preposY = Pop_seq_return(linkStackY);
		Pop_link(linkStackX);
		Pop_link(linkStackY);
		printf("出栈元素为%d %d\t",preposX,preposY);//输出栈顶元素
		//开始移动,从东方向(即→)开始
		mov = 0;
		//方向为0-7这八个方向(即东,东南,南,西南,西,西北.北,东北八个方向)
		while (mov < 8)
		{
			//即第0排的下标为mov元素和第1排的下标为mov元素组成方向的增量坐标
			//假如mov=0,即往东,其方向的增量坐标应为(0,1),得来的方式如下
			//direction[0][0]=0
			//direction[0][1]=1
			posX = preposX + direction[mov][0];
			posY = preposY + direction[mov][1];
			if (posX == exitX && posY == exitY)//如果到达终点了
			{
				//出口点入栈,因为出口点之前并不存在栈中
				Push_link(linkStackX, preposX);
				Push_link(linkStackY, preposY);
				//按序出栈即可
				printf("\n深度搜索迷宫路径如下:\n");
				printf("(%d,%d)\t", entryX, entryY);//打印入口点
				//while (!IsNullStack_link(linkStackX) && !IsNullStack_link(linkStackY))
				//依次弹出栈顶元素
				while (!IsNullStack_link(linkStackX))//只需要判断一个,因为入栈和出栈都是成对的
				{
					//取栈顶元素
					posX = Pop_seq_return(linkStackX);
					posY = Pop_seq_return(linkStackY);
					//出栈
					Pop_link(linkStackX);
					Pop_link(linkStackY);
					printf("(%d,%d)\t", posX, posY);//输出栈顶元素
				}
				return 1;
			}
			//如果没有到达终点,那就还有路可以走通
			//查看当前的位置是否是路,不是墙
			//maze->data[posX][posY] == 0
			//查看当前的位置是否没走过,其标记是否为0
			//mark[posX][posY] == 0
			if (maze->data[posX][posY] == 0 && mark[posX][posY] == 0)
			{
				mark[posX][posY] = 1;//修改标记,开始探索
				//先把之前的点入栈
				Push_link(linkStackX, preposX);
				Push_link(linkStackY, preposY);
				printf("入栈元素是(%d,%d)\t",preposX,preposY);//输出栈顶元素
				//为下次前进做准备,现在的位置会变为走过的位置
				preposX = posX;
				preposY = posY;
				mov = 0;//往前走了,方向重新从东开始顺时针找
			}
			//如果当前探索的位置不是通路,也标记过,那就先换个方向看看
			else
			{
				//一个方向不行就换一个
				mov++;
			}
			//当这个位置所有方向都探索完,也没有找到出口,就会跳出循环,回溯到取栈顶元素
		}
		//当栈空,也没找到出口时,即迷宫无路径,是个死迷宫,则返回0
		printf("当前迷宫没有出口,死在这里啦!\n");
		return 0;
	}
}