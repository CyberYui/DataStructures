#include <iostream>
#include <stdlib.h>
#include <string>
#include "StackParentMatch.h"

using namespace std;

/*****************************************************************************/
/*	ջӦ��---����ƥ��														 */
/*																			 */
/*	����:��������һ������,�����ж������Ƿ�ƥ��								 */
/*		   		     			   											 */
/*	�ַ���ʾ��:[()]   [()()]  {[][()()]}  [[(())]}}							 */
/*																			 */
/*	ʵ��Ŀ��:ͨ�������������ջ���Ƶ�ʹ�ü���								 */
/*																			 */
/*  ��������:2019-03-11          Author:Cyber Kaka							 */
/*****************************************************************************/

//�����߼�:
//�Ե�һ���ַ���[()]Ϊ��
//����ջ���ǿյ�,ɨ���ַ���,�ҵ���[,���ջ������һ��,����û��,����ջ
//���ż���ɨ���ַ���,�ҵ�(,��ջ��δ�ҵ���һ��,������ջ,��ʱ(Ϊջ��
//���ż���ɨ���ַ���,�ҵ�),��ջ��ɨ�赽��(,��ջ�е�(��ջ,�Ӷ�ƥ����һ������
//����ɨ���ַ���,�ҵ�],��ջ��ɨ�赽��[,��ջ�е�[��ջ,�Ӷ�ƥ������һ������
//����ɨ��,�����ַ����Ѿ�����
//�ж�ջ���Ƿ���Ԫ��,����û��Ԫ��,�Ӷ��ж��ַ���������ƥ��
//��֮,�Ե�����Ϊ��,�����ջ��ʣ��Ԫ��,�Ӷ��ж��ַ�����������ƥ��

int main(void)
{
	//������Ҫ����һ��ջ,����޷�ƥ����ַ�
	//����ַ�����һ����Ҫ����ƥ��,������Ҫƥ�����һ��Ҳ����һ��ջ��
	//δ����ʹ�������һ���ŵ�ջ���ַ����Ա�,���û����ͬ��,
	//�ͼ���ɨ���ַ���,����ڵ�һ��ջ��,�ٽ�����һ��ջ�ĶԱ�
	//�Դ�����

	//��������ջ,��char���ͼ���
	MyStack<char> *pStack = new MyStack<char>(30);//����ַ�

	MyStack<char> *pNeedStack = new MyStack<char>(30);//��������ַ�

	//�����ַ�����
	char str[] = "[[(())]}}";//����д���鳤�ȵ�ԭ�������������ɼ�������ɷ�������

	//���������ʾ��ǰ������ַ�
	char currentNeed = 0;//�����ֵ��Ϊ���ɼ����ַ���ASCII��ֵ
	for (unsigned int i = 0; i < strlen(str); i++)
	{
		if (str[i] != currentNeed)
		{
			//����ַ�����û����ƥ��ջ��Ӧ������,���ַ���������ջ
			pStack->push(str[i]);
			//���бȶ�,�ж�����һ������,֮�󽫶�Ӧ�������Ÿ�currentNeed��ֵ
			//����Ӧ��currentNeed�����ж�,���������������,�������Ƹ�ƥ��ջ
			//���ж�д�ڷ�֧�ڲ���ԭ����Ϊ���պ���չ��ϸ������
			switch (str[i])
			{
			case '[':
				if (currentNeed != 0)
				{
					//���currentNeed�Ѿ�������,�����ݷŵ�ƥ��ջ��
					//���û������,�����Ӧ��ƥ��������ֵ��currentNeed
					pNeedStack->push(currentNeed);
					currentNeed = ']';
				}
				else
				{
					currentNeed = ']';
				}
				break;
				//if (currentNeed!=0)
				//{
				//	//���currentNeed�Ѿ�������,�����ݷŵ�ƥ��ջ��
				//	//���û������,�����Ӧ��ƥ��������ֵ��currentNeed
				//	pNeedStack->push(currentNeed);
				//}
				//currentNeed = ']';
				//break;
			case '(':
				if (currentNeed != 0)
				{
					pNeedStack->push(currentNeed);
					currentNeed = ')';
				}
				else
				{
					currentNeed = ')';
				}
				break;
			case '{':
				if (currentNeed != 0)
				{
					pNeedStack->push(currentNeed);
					currentNeed = '}';
				}
				else
				{
					currentNeed = '}';
				}
				break;
			default:
				cout << "�ַ�����ƥ��" << endl;
				system("pause");

				delete pStack;
				pStack = NULL;

				delete pNeedStack;
				pNeedStack = NULL;

				return 0;
			}
		}
		else
		{
			//����ַ�������ƥ��ջ��Ӧ������,����ǰƥ���Ѿ��γ�
			//������ջ�ж�Ӧ�İ������Ӧ�ñ�����,ƥ��ջ���������Ҳ������
			char elem = 0;//������ʱ����
			pStack->pop(elem);
			//���Ƴ��������֮��,ջ���ı�,��currentNeedҲ��Ҫ���ı�
			//��ʱ��currentNeed�����ݾ������ڸı���ջ��֮���ջ��ƥ�������
			//pNeedStack->pop(currentNeed);
			//�Ӷ�ɨ���ʱ����ܼ���ƥ����

			//���pop(currentNeed)ʧ�ܵĻ�,Ӧ�ý��丳ֵΪ��ֵ
			//�Դ����ƴ���
			if (!pNeedStack->pop(currentNeed))
			{
				currentNeed = 0;
			}
		}
	}

	//��ƥ�����֮��,�ж�һ���ַ����Ƿ��Ѿ�����
	if (pStack->stackEmpty())
	{
		cout << "�ַ���ƥ��" << endl;
	}
	else
	{
		cout << "�ַ�����ƥ��" << endl;
	}

	delete pStack;
	pStack = NULL;

	delete pNeedStack;
	pNeedStack = NULL;

	system("pause");
	return 0;
}