#include "Sort.h"
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/****************************************************************/
/* void Sort::printArray(const vector<int>& arr)				*/
/* 功能:打印 vector 数组										*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void Sort::printArray(const vector<int>& arr)
{
	for (int i = 0; i < (int)arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

/****************************************************************/
/* void Sort::bubbleSort(vector<int>& arr)						*/
/* 功能:冒泡排序												*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void Sort::bubbleSort(vector<int>& arr)
{
	int n = arr.size();
	bool swapped = false;		//优化标志：本轮是否发生交换

	for (int i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		// 若本轮无交换，序列已有序，提前退出
		if (!swapped)
		{
			break;
		}
	}
}	// 时间复杂度: O(n^2)

/****************************************************************/
/* void Sort::insertionSort(vector<int>& arr)					*/
/* 功能:直接插入排序											*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void Sort::insertionSort(vector<int>& arr)
{
	int n = arr.size();

	for (int i = 1; i < n; i++)
	{
		int key = arr[i];	//保存当前待插入的元素
		int j = i - 1;

		// 将比 key 大的元素后移
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;	//插入到正确位置
	}
}	// 时间复杂度: O(n^2)

/****************************************************************/
/* void Sort::selectionSort(vector<int>& arr)					*/
/* 功能:简单选择排序											*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void Sort::selectionSort(vector<int>& arr)
{
	int n = arr.size();

	for (int i = 0; i < n - 1; i++)
	{
		int minIdx = i;		//记录最小值下标

		// 在 arr[i+1..n-1] 中找到最小值
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIdx])
			{
				minIdx = j;
			}
		}

		// 将最小值换到当前位置
		if (minIdx != i)
		{
			swap(arr[i], arr[minIdx]);
		}
	}
}	// 时间复杂度: O(n^2)

/****************************************************************/
/* void Sort::shellSort(vector<int>& arr)						*/
/* 功能:希尔排序												*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void Sort::shellSort(vector<int>& arr)
{
	int n = arr.size();

	// 初始增量取 n/2，每次减半，直到为 1
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		// 对每个间距 gap 做插入排序
		for (int i = gap; i < n; i++)
		{
			int key = arr[i];
			int j = i - gap;

			while (j >= 0 && arr[j] > key)
			{
				arr[j + gap] = arr[j];
				j -= gap;
			}
			arr[j + gap] = key;
		}
	}
}	// 时间复杂度: 约 O(n^1.3)

/****** 归并排序辅助函数 ******/

/****************************************************************/
/* void Sort::merge(vector<int>& arr, int left, int mid, int right) */
/* 功能:合并两个有序子数组 arr[left..mid] 和 arr[mid+1..right]	*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void Sort::merge(vector<int>& arr, int left, int mid, int right)
{
	// 临时数组存放左右两段数据
	vector<int> leftArr(arr.begin() + left, arr.begin() + mid + 1);
	vector<int> rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);

	int i = 0, j = 0, k = left;

	// 合并两个子数组
	while (i < (int)leftArr.size() && j < (int)rightArr.size())
	{
		if (leftArr[i] <= rightArr[j])	//稳定排序：相等取左边
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

	// 复制剩余元素
	while (i < (int)leftArr.size())
	{
		arr[k++] = leftArr[i++];
	}
	while (j < (int)rightArr.size())
	{
		arr[k++] = rightArr[j++];
	}
}

/****************************************************************/
/* void Sort::mergeSortHelper(vector<int>& arr, int left, int right) */
/* 功能:归并排序递归实现										*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void Sort::mergeSortHelper(vector<int>& arr, int left, int right)
{
	if (left >= right)
	{
		return;	//子数组只有一个元素时递归终止
	}

	int mid = left + (right - left) / 2;	//取中间位置，防止溢出

	mergeSortHelper(arr, left, mid);			//递归排序左半部分
	mergeSortHelper(arr, mid + 1, right);	//递归排序右半部分
	merge(arr, left, mid, right);			//合并两个有序子数组
}

/****************************************************************/
/* void Sort::mergeSort(vector<int>& arr)						*/
/* 功能:归并排序入口函数										*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void Sort::mergeSort(vector<int>& arr)
{
	mergeSortHelper(arr, 0, (int)arr.size() - 1);
}	// 时间复杂度: O(n log n)

/****** 快速排序辅助函数 ******/

/****************************************************************/
/* int Sort::partition(vector<int>& arr, int low, int high)		*/
/* 功能:Lomuto 划分，以 arr[high] 为 pivot						*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
int Sort::partition(vector<int>& arr, int low, int high)
{
	int pivot = arr[high];	//选末尾元素为基准
	int i = low - 1;		//i 指向小于 pivot 的最后一个元素

	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);	//将小于 pivot 的元素移到左侧
		}
	}

	// 将 pivot 放到正确位置
	swap(arr[i + 1], arr[high]);
	return i + 1;
}

/****************************************************************/
/* void Sort::quickSort(vector<int>& arr, int low, int high)	*/
/* 功能:快速排序（递归版）										*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void Sort::quickSort(vector<int>& arr, int low, int high)
{
	if (low < high)
	{
		int pivotIdx = partition(arr, low, high);	//划分，获取 pivot 位置

		quickSort(arr, low, pivotIdx - 1);		//递归排序左部分
		quickSort(arr, pivotIdx + 1, high);		//递归排序右部分
	}
}	// 时间复杂度: O(n log n) 平均

/****** 堆排序辅助函数 ******/

/****************************************************************/
/* void Sort::heapify(vector<int>& arr, int n, int i)			*/
/* 功能:对以下标 i 为根的子树做堆化（大顶堆）					*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void Sort::heapify(vector<int>& arr, int n, int i)
{
	int largest = i;		//假设当前节点最大
	int left = 2 * i + 1;	//左孩子下标
	int right = 2 * i + 2;	//右孩子下标

	if (left < n && arr[left] > arr[largest])
	{
		largest = left;
	}
	if (right < n && arr[right] > arr[largest])
	{
		largest = right;
	}

	// 若根不是最大值，则交换并继续堆化
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

/****************************************************************/
/* void Sort::heapSort(vector<int>& arr)						*/
/* 功能:堆排序												*/
/* 创建日期: 2024-1-1						Author:Cyber Kaka	*/
/****************************************************************/
void Sort::heapSort(vector<int>& arr)
{
	int n = arr.size();

	// 第一阶段：建大顶堆（从最后非叶结点向上堆化）
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	// 第二阶段：逐步将堆顶（最大值）移到末尾，重新堆化
	for (int i = n - 1; i > 0; i--)
	{
		swap(arr[0], arr[i]);	//将堆顶与末尾互换
		heapify(arr, i, 0);		//重新堆化（堆大小减1）
	}
}	// 时间复杂度: O(n log n)
