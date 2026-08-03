// 排序算法演示程序（C++ 版本）
//
// 编译命令 (Linux/g++):
//   g++ Sort.cpp SortDemo.cpp -o sort_demo
//   ./sort_demo

#include <iostream>
#include <vector>
#include "Sort.h"
using namespace std;

int main(void)
{
	// 测试数据
	vector<int> source = {64, 34, 25, 12, 22, 11, 90};
	vector<int> arr;	// 每次排序前从 source 复制，保证数据一致

	cout << "===== 排序算法演示（C++）=====" << endl;
	cout << "原始数组: ";
	Sort::printArray(source);
	cout << endl;

	// ---- 1. 冒泡排序 ----
	arr = source;
	Sort::bubbleSort(arr);
	cout << "冒泡排序: ";
	Sort::printArray(arr);

	// ---- 2. 插入排序 ----
	arr = source;
	Sort::insertionSort(arr);
	cout << "插入排序: ";
	Sort::printArray(arr);

	// ---- 3. 选择排序 ----
	arr = source;
	Sort::selectionSort(arr);
	cout << "选择排序: ";
	Sort::printArray(arr);

	// ---- 4. 希尔排序 ----
	arr = source;
	Sort::shellSort(arr);
	cout << "希尔排序: ";
	Sort::printArray(arr);

	// ---- 5. 归并排序 ----
	arr = source;
	Sort::mergeSort(arr);
	cout << "归并排序: ";
	Sort::printArray(arr);

	// ---- 6. 快速排序 ----
	arr = source;
	Sort::quickSort(arr, 0, (int)arr.size() - 1);
	cout << "快速排序: ";
	Sort::printArray(arr);

	// ---- 7. 堆排序 ----
	arr = source;
	Sort::heapSort(arr);
	cout << "堆  排序: ";
	Sort::printArray(arr);

	return 0;
}
