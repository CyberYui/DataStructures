#include <stdlib.h>
#include <stdio.h>
//�ҳ�t2-->t1��С���ʴ���
int step(int t1, int t2)
{
	if (t2 > t1)
	{
		//һ��֮�ڻش�
		return t2 - t1;
	}
	else
	{
		//����һ������֮����ܻش�
		return 3 + t2 - t1;
	}
}
//��ӡһ�����������
void array_print(int temp[3])
{
	int z;
	for (z = 0; z < 3; z++)
	{
		printf("%d ", temp[z]);
	}
}
//����ÿ��������������t3���λ����
//�������ʶ��ٴ�t3����ȷ�ش�����
//i����t1����,j����t2����,����t1,t2,t3
int times(int i, int j, int t1, int t2, int t3)
{
	int k;
	k = i - j;//����i-j�Ľ��
	int temp[3] = { 0 };
	//���i-j==0,��������ֵ����˵���ȷ��
	if (k == 0)
	{
		return t3;
	}
	//�޷�һ�ֵó�����,��Ҫ�ݹ�
	if (k > 0)
	{
		//
		temp[t2 - 1] = j;
		temp[t3 - 1] = i - j;
		temp[t1 - 1] = i;
		//��ӡ���εݹ������ת��
		array_print(temp);
		printf("\n");
		//�����ݹ�
		return times(j, i - j, t2, t3, t1) + step(t1, t3);//��ʱt1���,����t1��t3�Ĳ���,
	}
	//�޷�һ�ֵó�����,��Ҫ�ݹ�
	if (k < 0)
	{
		//
		temp[t2 - 1] = j;
		temp[t3 - 1] = j - i;
		temp[t1 - 1] = i;
		//��ӡ���εݹ������ת��
		array_print(temp);
		printf("\n");
		//�����ݹ�
		return times(i, j - i, t1, t3, t2) + step(t2, t3);//��ʱt2���,����t2��t3�Ĳ���,
	}
}

int main()
{
	int result;//������
	int a = 1, b = 2, c = 3;//ѧ��˳��
	int arr[3] = { 3,8,5 }; //������ѧ������������
	//�����±�
	int index = 0;
	//�洢��һ���һ������������
	int max_num = -1;
	int mid_num = -1;
	//�洢��һ���һ���������������±�
	int max_index = -1;
	int mid_index = -1;
	//ѭ��,�ҳ�������
	for (index = 0; index < 3; index++)
	{
		//�������С�������е�ĳ����ʱ,��������������±�
		if (max_num < arr[index])
		{
			max_num = arr[index];
			max_index = index;
		}
	}
	//ѭ��,�ҳ�һ������������
	for (index = 0; index < 3; index++)
	{
		//���������������
		if (mid_num < arr[index] && arr[index] != max_num)
		{
			mid_num = arr[index];
			mid_index = index;
		}
	}
	//t3ռ��������
	c = max_index + 1;
	//t2ռ��һ����
	b = mid_index + 1;
	//����λ��,ʹ��ѧ��˳��a,b,c������λc��ѧ�����������
	if ((c == 1 && b == 2) || (c == 2 && b == 1))
	{
		a = 3;
	}
	else if ((c == 2 && b == 3) || (c == 3 && b == 2))
	{
		a = 1;
	}
	else
	{
		a = 2;
	}
	//��ʼ���
	printf("�Ƶ�����:\n");
	array_print(arr);//�������һ��ԭʼ����
	printf("\n");
	//��֤c��������,��t1��t2��������Ӧ��������Ԫ�ض�Ӧ����
	//��������(3,5,8)����(5,3,8)������
	//ab˭ǰ˭������ν��ֻҪ�ҵ���ȷ�����ֵ��ab��ȷ���꼴��
	result = times(arr[a - 1], arr[b - 1], a, b, c);
	//�õ����
	printf("��%dλѧ��", c);
	printf("�ڵ�%d������ʱ�ش���ȷ\n", result);
	return 0;
}