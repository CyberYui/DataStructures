// 排序算法类定义头文件（C++ 版本）
//
// Sort 类（静态工具类，所有方法均为 static）:
//   void bubbleSort(vector<int>& arr);    // 冒泡排序
//   void insertionSort(vector<int>& arr); // 插入排序
//   void selectionSort(vector<int>& arr); // 选择排序
//   void shellSort(vector<int>& arr);     // 希尔排序
//   void mergeSort(vector<int>& arr);     // 归并排序
//   void quickSort(vector<int>& arr, int low, int high); // 快速排序
//   void heapSort(vector<int>& arr);      // 堆排序
//   void printArray(const vector<int>& arr); // 打印数组
//
// 使用方式：
//   vector<int> arr = {5, 2, 8, 1, 9};
//   Sort::bubbleSort(arr);
//   Sort::printArray(arr);
//
// 时间复杂度对比（同 C 版本）：
//   冒泡/插入/选择: O(n^2)
//   希尔:           约 O(n^1.3)
//   归并/快排/堆:   O(n log n)
//
// 创建日期: 2024-1-1
// Author: Cyber Kaka
//****************************************************************************

#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>
using namespace std;

class Sort
{
public:

	/****************************************************************/
	/* static void printArray(const vector<int>& arr)				*/
	/* 功能:打印 vector 数组内容									*/
	/* 创建日期: 2024-1-1					Author:Cyber Kaka		*/
	/****************************************************************/
	static void printArray(const vector<int>& arr);

	/****************************************************************/
	/* static void bubbleSort(vector<int>& arr)						*/
	/* 功能:冒泡排序（带提前退出优化）								*/
	/*   时间复杂度: O(n^2)  稳定排序								*/
	/* 创建日期: 2024-1-1					Author:Cyber Kaka		*/
	/****************************************************************/
	static void bubbleSort(vector<int>& arr);

	/****************************************************************/
	/* static void insertionSort(vector<int>& arr)					*/
	/* 功能:直接插入排序											*/
	/*   时间复杂度: O(n^2)  稳定排序								*/
	/* 创建日期: 2024-1-1					Author:Cyber Kaka		*/
	/****************************************************************/
	static void insertionSort(vector<int>& arr);

	/****************************************************************/
	/* static void selectionSort(vector<int>& arr)					*/
	/* 功能:简单选择排序											*/
	/*   时间复杂度: O(n^2)  不稳定排序							*/
	/* 创建日期: 2024-1-1					Author:Cyber Kaka		*/
	/****************************************************************/
	static void selectionSort(vector<int>& arr);

	/****************************************************************/
	/* static void shellSort(vector<int>& arr)						*/
	/* 功能:希尔排序（缩小增量插入排序）							*/
	/*   时间复杂度: 约 O(n^1.3)  不稳定排序						*/
	/* 创建日期: 2024-1-1					Author:Cyber Kaka		*/
	/****************************************************************/
	static void shellSort(vector<int>& arr);

	/****************************************************************/
	/* static void mergeSort(vector<int>& arr)						*/
	/* 功能:归并排序（递归版）										*/
	/*   时间复杂度: O(n log n)  稳定排序							*/
	/* 创建日期: 2024-1-1					Author:Cyber Kaka		*/
	/****************************************************************/
	static void mergeSort(vector<int>& arr);

	/****************************************************************/
	/* static void quickSort(vector<int>& arr, int low, int high)	*/
	/* 功能:快速排序（递归版，Lomuto 划分）						*/
	/*   时间复杂度: O(n log n) 平均  不稳定排序					*/
	/* 创建日期: 2024-1-1					Author:Cyber Kaka		*/
	/****************************************************************/
	static void quickSort(vector<int>& arr, int low, int high);

	/****************************************************************/
	/* static void heapSort(vector<int>& arr)						*/
	/* 功能:堆排序（大顶堆）										*/
	/*   时间复杂度: O(n log n)  不稳定排序						*/
	/* 创建日期: 2024-1-1					Author:Cyber Kaka		*/
	/****************************************************************/
	static void heapSort(vector<int>& arr);

private:
	// 归并排序辅助：将两段有序子数组合并
	static void merge(vector<int>& arr, int left, int mid, int right);

	// 归并排序递归辅助
	static void mergeSortHelper(vector<int>& arr, int left, int right);

	// 快速排序划分辅助（Lomuto 方案），返回 pivot 最终位置
	static int partition(vector<int>& arr, int low, int high);

	// 堆排序：对以下标 i 为根的子树进行堆化（大顶堆）
	static void heapify(vector<int>& arr, int n, int i);
};

#endif // SORT_H
