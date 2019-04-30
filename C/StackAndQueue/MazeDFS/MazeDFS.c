#include <stdlib.h>
#include <stdio.h>
#include "mazeutil.h"
#include "LinkedStack.h"

//�Թ���ȱ����㷨
int MazeDFS(int entryX, int entryY, int exitX, int exitY, Maze* maze)
{
	//����˸�����Ķ�ά����
	//���ִ�������,���綫��(��)����(x,y+1),����Ϊ{0,1}
	int direction[8][2] = { {0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1} };
	//����������ջ,�ֱ𱣴�·���е��(x,y)��ֵ
	LinkedStack linkStackX = NULL;
	LinkedStack linkStackY = NULL;
	//��������ʼ����ʱ����,���ڴ������
	int posX = 0;//posָ�������ڵ�λ��
	int posY = 0;
	int preposX = 0;//preposָ֮ǰ̽����λ��,���ڻ�ͷ
	int preposY = 0;
	//����һ����Ƕ�ά�����ָ��,�����޸��߹���·��,���ظ���·
	int **mark;
	//����ѭ����������ʼ��
	int i = 0;
	int j = 0;
	//����ƶ�����ı���
	int mov = 0;//0��������,���ұߡ�
	//����ά�������ռ�,������ֵ
	mark = (int **)malloc(sizeof(int*)* maze->size);
	for (i = 0; i < maze->size; i++)
	{
		mark[i] = (int*)malloc(sizeof(int)* maze->size);
	}
	//ѭ��,������Ԫ�ظ���ֵ
	for (i = 0; i < maze->size; i++)
	{
		for (j = 0; j < maze->size; j++)
		{
			mark[i][j] = 0;
		}
	}
	//��ʼ��ջ
	linkStackX = SetNullStack_Link();
	linkStackY = SetNullStack_Link();
	//����ڵ����ñ�־λ,�����������Ϊ���������
	mark[entryX][entryY] = 1;//���Ҳ�����߹���,���Ա�־��Ϊ1
	//���������ջ
	Push_link(linkStackX, entryX);//�������������ջ
	Push_link(linkStackY, entryY);//�������������ջ
	//�ж�����ջ�Ƿ��ӦΪ��,��Ϊ�մ���û���ҵ�����
	//while (!IsNullStack_link(linkStackX) && !IsNullStack_link(linkStackY))
	while (!IsNullStack_link(linkStackX))//ֻ��Ҫ�ж�һ��,��Ϊ��ջ�ͳ�ջ���ǳɶԵ�
	{
		//ȡջ��Ԫ��
		preposX = Pop_seq_return(linkStackX);
		preposY = Pop_seq_return(linkStackY);
		Pop_link(linkStackX);
		Pop_link(linkStackY);
		printf("��ջԪ��Ϊ%d %d\t",preposX,preposY);//���ջ��Ԫ��
		//��ʼ�ƶ�,�Ӷ�����(����)��ʼ
		mov = 0;
		//����Ϊ0-7��˸�����(����,����,��,����,��,����.��,�����˸�����)
		while (mov < 8)
		{
			//����0�ŵ��±�ΪmovԪ�غ͵�1�ŵ��±�ΪmovԪ����ɷ������������
			//����mov=0,������,�䷽�����������ӦΪ(0,1),�����ķ�ʽ����
			//direction[0][0]=0
			//direction[0][1]=1
			posX = preposX + direction[mov][0];
			posY = preposY + direction[mov][1];
			if (posX == exitX && posY == exitY)//��������յ���
			{
				//���ڵ���ջ,��Ϊ���ڵ�֮ǰ��������ջ��
				Push_link(linkStackX, preposX);
				Push_link(linkStackY, preposY);
				//�����ջ����
				printf("\n��������Թ�·������:\n");
				printf("(%d,%d)\t", entryX, entryY);//��ӡ��ڵ�
				//while (!IsNullStack_link(linkStackX) && !IsNullStack_link(linkStackY))
				//���ε���ջ��Ԫ��
				while (!IsNullStack_link(linkStackX))//ֻ��Ҫ�ж�һ��,��Ϊ��ջ�ͳ�ջ���ǳɶԵ�
				{
					//ȡջ��Ԫ��
					posX = Pop_seq_return(linkStackX);
					posY = Pop_seq_return(linkStackY);
					//��ջ
					Pop_link(linkStackX);
					Pop_link(linkStackY);
					printf("(%d,%d)\t", posX, posY);//���ջ��Ԫ��
				}
				return 1;
			}
			//���û�е����յ�,�Ǿͻ���·������ͨ
			//�鿴��ǰ��λ���Ƿ���·,����ǽ
			//maze->data[posX][posY] == 0
			//�鿴��ǰ��λ���Ƿ�û�߹�,�����Ƿ�Ϊ0
			//mark[posX][posY] == 0
			if (maze->data[posX][posY] == 0 && mark[posX][posY] == 0)
			{
				mark[posX][posY] = 1;//�޸ı��,��ʼ̽��
				//�Ȱ�֮ǰ�ĵ���ջ
				Push_link(linkStackX, preposX);
				Push_link(linkStackY, preposY);
				printf("��ջԪ����(%d,%d)\t",preposX,preposY);//���ջ��Ԫ��
				//Ϊ�´�ǰ����׼��,���ڵ�λ�û��Ϊ�߹���λ��
				preposX = posX;
				preposY = posY;
				mov = 0;//��ǰ����,�������´Ӷ���ʼ˳ʱ����
			}
			//�����ǰ̽����λ�ò���ͨ·,Ҳ��ǹ�,�Ǿ��Ȼ������򿴿�
			else
			{
				//һ�������оͻ�һ��
				mov++;
			}
			//�����λ�����з���̽����,Ҳû���ҵ�����,�ͻ�����ѭ��,���ݵ�ȡջ��Ԫ��
		}
		//��ջ��,Ҳû�ҵ�����ʱ,���Թ���·��,�Ǹ����Թ�,�򷵻�0
		printf("��ǰ�Թ�û�г���,����������!\n");
		return 0;
	}
}