# 排序算法 / Sorting Algorithms

## 介绍

本模块提供七种常见教材级内部排序算法的 C 语言实现，均针对 `int` 数组进行升序排列。

## 已实现算法

| 算法 | 时间复杂度（平均） | 时间复杂度（最坏） | 空间复杂度 | 稳定性 |
|------|------------------|--------------------|------------|--------|
| 冒泡排序 (Bubble Sort) | O(n²) | O(n²) | O(1) | 稳定 |
| 插入排序 (Insertion Sort) | O(n²) | O(n²) | O(1) | 稳定 |
| 选择排序 (Selection Sort) | O(n²) | O(n²) | O(1) | 不稳定 |
| 希尔排序 (Shell Sort) | O(n^1.3) | O(n²) | O(1) | 不稳定 |
| 归并排序 (Merge Sort) | O(n log n) | O(n log n) | O(n) | 稳定 |
| 快速排序 (Quick Sort) | O(n log n) | O(n²) | O(log n) | 不稳定 |
| 堆排序 (Heap Sort) | O(n log n) | O(n log n) | O(1) | 不稳定 |

## 文件说明

- `Sort.h` — 函数声明及注释
- `Sort.c` — 所有排序算法的实现
- `main.c` — 演示程序，对同一数组依次运行七种排序

## 编译运行

```bash
# Linux/gcc
gcc Sort.c main.c -o sort_demo
./sort_demo
```

## 关键代码解析

### 冒泡排序

每轮将最大元素"冒泡"到末尾，附带提前退出优化（一轮未发生交换即认为已排好序）：

```c
for (i = 0; i < n - 1; i++) {
    swapped = 0;
    for (j = 0; j < n - 1 - i; j++) {
        if (arr[j] > arr[j + 1]) {
            // 交换
            swapped = 1;
        }
    }
    if (!swapped) break;  // 提前退出
}
```

### 快速排序划分（Lomuto 方案）

```c
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // 取末尾为基准
    int i = low - 1;
    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i + 1;
}
```

### 堆排序（大顶堆）

两阶段：① 建堆 `O(n)`；② 逐步将堆顶取出并维护堆 `O(n log n)`：

```c
// 建大顶堆（从最后非叶节点向上堆化）
for (i = n/2 - 1; i >= 0; i--) heapify(arr, n, i);
// 逐步排序
for (i = n-1; i > 0; i--) {
    swap(arr[0], arr[i]);
    heapify(arr, i, 0);
}
```
