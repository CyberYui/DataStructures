#include <stdio.h>
#include <stdlib.h>
#include "LinkedStack.h"

//����ƥ���㷨
int BracketMatch(LinkedStack top)
{
	int flag = 1;//��־
	//���岢��ʼ������ı��ʽ����ʱ����
	char ch = "a";
	char temp = "b";
	printf("������Ҫ�жϵı��ʽ,��#�Ž���:");
	//ֱ��������ʽ֮����#��ʾ��������
	scanf_s("%c", &ch);
	while (ch != '#')
	{
		//С����
		if (ch == '(')//��������,ѹ��ջ��
		{
			Push_link(top, ch);
		}
		else
		{
			if (ch == ')')//������,����Ƿ��ջ
			{
				//��ȡ��ջ��Ԫ��,���ǲ���ƥ��
				temp = Pop_seq_return(top);//����������Ŷ�����,��Ȼջ��,��flag=0
				if (temp == '(')
				{
					//����ƥ��,ջ����ջ
					Pop_link(top);
				} 
				else
				{
					//��ƥ��,flag=0,����ѭ��
					flag = 0;//�����Ų���������������
					break;
				}
			} 
		}
		//������
		if (ch == '[')//��������,ѹ��ջ��
		{
			Push_link(top, ch);
		}
		else
		{
			if (ch == ']')//������,����Ƿ��ջ
			{
				//��ȡ��ջ��Ԫ��,���ǲ���ƥ��
				temp = Pop_seq_return(top);//����������Ŷ�����,��Ȼջ��,��flag=0
				if (temp == '[')
				{
					//����ƥ��,ջ����ջ
					Pop_link(top);
				}
				else
				{
					//��ƥ��,flag=0,����ѭ��
					flag = 0;//�����Ų���������������
					break;
				}
			}
		}
		//������
		if (ch == '{')//��������,ѹ��ջ��
		{
			Push_link(top, ch);
		}
		else
		{
			if (ch == '}')//������,����Ƿ��ջ
			{
				//��ȡ��ջ��Ԫ��,���ǲ���ƥ��
				temp = Pop_seq_return(top);//����������Ŷ�����,��Ȼջ��,��flag=0
				if (temp == '{')
				{
					//����ƥ��,ջ����ջ
					Pop_link(top);
				}
				else
				{
					//��ƥ��,flag=0,����ѭ��
					flag = 0;//�����Ų���������������
					break;
				}
			}
		}
		scanf_s("%c", &ch);
	}//while end
	//ѭ��������
	if (!flag || !IsNullStack_link(top))
	{
		//����в���������,�����������Ŷ�����,��ƥ��
		printf("\n��ƥ��!\n");
		return 0;
	} 
	else
	{
		printf("\nƥ��!\n");
		return 1;
	}
}

int main()
{
	LinkedStack sstack = SetNullStack_Link();//����һ������ջ
	BracketMatch(sstack);

	system("pause");
	return 0;
}