// 排序算法演示主程序
// 依次演示七种排序算法对同一数组的排序结果

#include <stdio.h>
#include <string.h>
#include "Sort.h"

/*
编译命令 (Linux/gcc):
  gcc Sort.c main.c -o sort_demo
  ./sort_demo

输出示例:
  原始数组: 64 34 25 12 22 11 90
  冒泡排序: 11 12 22 25 34 64 90
  插入排序: 11 12 22 25 34 64 90
  ...
*/

int main(void)
{
	// 测试数据（共 7 个元素）
	int source[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(source) / sizeof(source[0]);
	int arr[7];	// 每次测试前从 source 复制，保证数据一致

	printf("===== 排序算法演示 =====\n");
	printf("原始数组: ");
	printArray(source, n);
	printf("\n");

	// ---- 1. 冒泡排序 ----
	memcpy(arr, source, sizeof(source));
	bubbleSort(arr, n);
	printf("冒泡排序: ");
	printArray(arr, n);

	// ---- 2. 插入排序 ----
	memcpy(arr, source, sizeof(source));
	insertionSort(arr, n);
	printf("插入排序: ");
	printArray(arr, n);

	// ---- 3. 选择排序 ----
	memcpy(arr, source, sizeof(source));
	selectionSort(arr, n);
	printf("选择排序: ");
	printArray(arr, n);

	// ---- 4. 希尔排序 ----
	memcpy(arr, source, sizeof(source));
	shellSort(arr, n);
	printf("希尔排序: ");
	printArray(arr, n);

	// ---- 5. 归并排序 ----
	memcpy(arr, source, sizeof(source));
	mergeSort(arr, n);
	printf("归并排序: ");
	printArray(arr, n);

	// ---- 6. 快速排序 ----
	memcpy(arr, source, sizeof(source));
	quickSort(arr, 0, n - 1);
	printf("快速排序: ");
	printArray(arr, n);

	// ---- 7. 堆排序 ----
	memcpy(arr, source, sizeof(source));
	heapSort(arr, n);
	printf("堆  排序: ");
	printArray(arr, n);

	return 0;
}
