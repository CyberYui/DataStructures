#include <stdlib.h>
#include <stdio.h>
#include "LinkedStack.h"
#include "mazeutil.h"

void main()
{
	Maze *maze;
	int mazeSize = 0;//���岢��ʼ���Թ���С
	//���岢��ʼ����ںͳ���
	int entryX = 0;
	int entryY = 0;
	int exitX = 0;
	int exitY = 0;
	int find = 0;
	printf("�������Թ���С:");
	scanf_s("%d", &mazeSize);//��ȡ������Թ���С
	maze = InitMaze(mazeSize);//��ʼ���Թ�
	ReadMaze(maze);//��ȡ�Թ�
	printf("������Թ��ṹ����:\n");
	printf("�������Թ�����ڵ�x,y,���ڵ�x,y:\n");
	scanf_s("%d%d%d%d", &entryX, &entryY, &exitX, &exitY);//������ںͳ���
	//�����������
	find = MazeDFS(entryX, entryY, exitX, exitY, maze);

	system("pause");
	return 0;
}