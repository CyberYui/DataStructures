// 排序算法实现文件
// 包含七种常见内部排序算法的 C 语言实现
// 所有算法均针对 int 数组进行升序排列

#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/****************************************************************/
/* void printArray(int arr[], int n)							*/
/* 功能:打印整型数组内容										*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void printArray(int arr[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

/****************************************************************/
/* void bubbleSort(int arr[], int n)							*/
/* 功能:冒泡排序												*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void bubbleSort(int arr[], int n)
{
	int i = 0;		// 外层循环计数器（轮次）
	int j = 0;		// 内层循环计数器（比较位置）
	int temp = 0;	// 交换临时变量
	int swapped = 0;	// 优化标志：本轮是否发生交换

	// 共进行 n-1 轮冒泡
	for (i = 0; i < n - 1; i++)
	{
		swapped = 0;	// 每轮开始前重置标志

		// 每轮将当前最大值冒泡到 arr[n-1-i]
		for (j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				// 交换相邻两个元素
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;	// 本轮发生了交换
			}
		}

		// 若本轮没有发生任何交换，说明已经有序，提前退出
		if (!swapped)
		{
			break;
		}
	}
}	// 时间复杂度: O(n^2)

/****************************************************************/
/* void insertionSort(int arr[], int n)							*/
/* 功能:直接插入排序											*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void insertionSort(int arr[], int n)
{
	int i = 0;		// 外层循环：当前待插入元素的下标
	int j = 0;		// 内层循环：向前查找插入位置
	int key = 0;	// 当前待插入的元素值

	// 从第 1 个元素开始，前面 arr[0..i-1] 已有序
	for (i = 1; i < n; i++)
	{
		key = arr[i];	// 保存当前要插入的元素
		j = i - 1;

		// 将比 key 大的元素依次后移一位
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		// 找到了插入位置，放入 key
		arr[j + 1] = key;
	}
}	// 时间复杂度: O(n^2)

/****************************************************************/
/* void selectionSort(int arr[], int n)							*/
/* 功能:简单选择排序											*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void selectionSort(int arr[], int n)
{
	int i = 0;		// 外层循环：当前已排好的边界
	int j = 0;		// 内层循环：在未排序部分查找最小值
	int minIdx = 0;	// 记录当前最小值的下标
	int temp = 0;	// 交换临时变量

	for (i = 0; i < n - 1; i++)
	{
		// 假设当前位置的元素为最小值
		minIdx = i;

		// 在 arr[i+1..n-1] 中寻找更小的元素
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;	// 更新最小值下标
			}
		}

		// 将找到的最小值换到 arr[i]
		if (minIdx != i)
		{
			temp = arr[i];
			arr[i] = arr[minIdx];
			arr[minIdx] = temp;
		}
	}
}	// 时间复杂度: O(n^2)

/****************************************************************/
/* void shellSort(int arr[], int n)								*/
/* 功能:希尔排序												*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void shellSort(int arr[], int n)
{
	int gap = 0;	// 增量（分组间隔）
	int i = 0;		// 外层循环（从 gap 开始的位置）
	int j = 0;		// 内层循环（在同组中向前查找插入位置）
	int key = 0;	// 当前待插入的元素值

	// 初始增量取 n/2，每次缩半，直到增量为 1
	for (gap = n / 2; gap > 0; gap /= 2)
	{
		// 对每个间距 gap 做插入排序
		for (i = gap; i < n; i++)
		{
			key = arr[i];
			j = i - gap;

			// 在同一组内向前查找插入位置
			while (j >= 0 && arr[j] > key)
			{
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = key;
		}
	}
}	// 时间复杂度: 约 O(n^1.3)，依赖增量序列

/*------ 归并排序辅助函数 ------*/

/****************************************************************/
/* static void merge(int arr[], int left, int mid, int right)	*/
/* 功能:将 arr[left..mid] 和 arr[mid+1..right] 两个有序子数组	*/
/*       合并成一个有序数组										*/
/****************************************************************/
static void merge(int arr[], int left, int mid, int right)
{
	int i = 0, j = 0, k = 0;
	int n1 = mid - left + 1;	// 左子数组长度
	int n2 = right - mid;		// 右子数组长度

	// 申请临时空间存放两个子数组
	int *leftArr = (int*)malloc(sizeof(int) * n1);
	int *rightArr = (int*)malloc(sizeof(int) * n2);

	// 拷贝数据到临时数组
	for (i = 0; i < n1; i++)
	{
		leftArr[i] = arr[left + i];
	}
	for (j = 0; j < n2; j++)
	{
		rightArr[j] = arr[mid + 1 + j];
	}

	// 合并两个有序子数组回 arr[left..right]
	i = 0;	// 左子数组起始下标
	j = 0;	// 右子数组起始下标
	k = left;	// 合并后数组的起始写入位置

	while (i < n1 && j < n2)
	{
		// 稳定排序：相等时取左边（保持原有相对顺序）
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}

	// 复制左子数组中剩余元素
	while (i < n1)
	{
		arr[k] = leftArr[i];
		i++;
		k++;
	}

	// 复制右子数组中剩余元素
	while (j < n2)
	{
		arr[k] = rightArr[j];
		j++;
		k++;
	}

	// 释放临时数组空间
	free(leftArr);
	free(rightArr);
}

/****************************************************************/
/* static void mergeSortHelper(int arr[], int left, int right)	*/
/* 功能:归并排序递归实现										*/
/****************************************************************/
static void mergeSortHelper(int arr[], int left, int right)
{
	int mid = 0;
	if (left >= right)
	{
		return;	// 递归终止条件：子数组只有一个元素或为空
	}

	mid = left + (right - left) / 2;	// 取中间位置，避免整数溢出

	mergeSortHelper(arr, left, mid);		// 递归排序左半部分
	mergeSortHelper(arr, mid + 1, right);	// 递归排序右半部分
	merge(arr, left, mid, right);			// 合并两个有序子数组
}

/****************************************************************/
/* void mergeSort(int arr[], int n)								*/
/* 功能:归并排序入口函数										*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void mergeSort(int arr[], int n)
{
	mergeSortHelper(arr, 0, n - 1);
}	// 时间复杂度: O(n log n)

/*------ 快速排序辅助函数 ------*/

/****************************************************************/
/* static int partition(int arr[], int low, int high)			*/
/* 功能:快速排序划分函数（Lomuto 方案）						*/
/*   选取 arr[high] 为基准 pivot，将小于 pivot 的元素置于左侧	*/
/*   返回 pivot 最终所在的下标									*/
/****************************************************************/
static int partition(int arr[], int low, int high)
{
	int pivot = arr[high];	// 选取末尾元素为基准
	int i = low - 1;		// i 指向小于 pivot 的最后一个元素
	int j = 0;
	int temp = 0;

	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			// 交换 arr[i] 和 arr[j]，将小于等于 pivot 的元素移到左侧
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	// 将 pivot 交换到正确位置（i+1）
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;

	return i + 1;	// 返回 pivot 的最终位置
}

/****************************************************************/
/* void quickSort(int arr[], int low, int high)					*/
/* 功能:快速排序（递归版）										*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void quickSort(int arr[], int low, int high)
{
	int pivotIdx = 0;	// pivot 划分后的位置

	if (low < high)
	{
		// 划分数组，获取 pivot 的最终下标
		pivotIdx = partition(arr, low, high);

		// 递归排序 pivot 左右两部分
		quickSort(arr, low, pivotIdx - 1);
		quickSort(arr, pivotIdx + 1, high);
	}
}	// 时间复杂度: O(n log n) 平均, O(n^2) 最坏

/*------ 堆排序辅助函数 ------*/

/****************************************************************/
/* static void heapify(int arr[], int n, int i)					*/
/* 功能:以下标 i 为根，对子树进行"堆化"（大顶堆）				*/
/*   前提：arr[i] 的左右子树均已满足大顶堆性质				*/
/*   n 为堆的当前有效大小										*/
/****************************************************************/
static void heapify(int arr[], int n, int i)
{
	int largest = i;		// 假设当前节点最大
	int left = 2 * i + 1;	// 左孩子下标（从 0 开始）
	int right = 2 * i + 2;	// 右孩子下标
	int temp = 0;

	// 找出 arr[i]、左孩子、右孩子中的最大值
	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}
	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}

	// 若最大值不是根节点，则交换并继续向下堆化
	if (largest != i)
	{
		temp = arr[i];
		arr[i] = arr[largest];
		arr[largest] = temp;

		heapify(arr, n, largest);	// 递归维护被交换的子树
	}
}

/****************************************************************/
/* void heapSort(int arr[], int n)								*/
/* 功能:堆排序												*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void heapSort(int arr[], int n)
{
	int i = 0;
	int temp = 0;

	// 第一阶段：建大顶堆（从最后一个非叶节点向根节点依次堆化）
	// 最后一个非叶节点下标为 n/2 - 1
	for (i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	// 第二阶段：逐步将堆顶（最大值）移到末尾，然后重新堆化
	for (i = n - 1; i > 0; i--)
	{
		// 将堆顶 arr[0] 与末尾 arr[i] 交换
		temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;

		// 重新对缩小后的堆进行堆化（堆大小减 1）
		heapify(arr, i, 0);
	}
}	// 时间复杂度: O(n log n)
