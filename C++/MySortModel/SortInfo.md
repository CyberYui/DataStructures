# 排序算法 C++ 实现 / Sorting Algorithms (C++)

## 介绍

本模块提供七种常见教材级内部排序算法的 C++ 实现，封装在 `Sort` 静态工具类中，使用 `vector<int>` 作为数组容器，接口风格与 C++ STL 类似。

## 文件说明

| 文件 | 说明 |
|------|------|
| `Sort.h` | 排序类声明 |
| `Sort.cpp` | 所有排序算法的实现 |
| `SortDemo.cpp` | 演示程序 |

## 编译运行

```bash
# Linux/g++
g++ Sort.cpp SortDemo.cpp -o sort_demo
./sort_demo
```

## 已实现算法

| 算法 | 时间复杂度（平均） | 空间复杂度 | 稳定性 |
|------|------------------|------------|--------|
| 冒泡排序 | O(n²) | O(1) | 稳定 |
| 插入排序 | O(n²) | O(1) | 稳定 |
| 选择排序 | O(n²) | O(1) | 不稳定 |
| 希尔排序 | O(n^1.3) | O(1) | 不稳定 |
| 归并排序 | O(n log n) | O(n) | 稳定 |
| 快速排序 | O(n log n) | O(log n) | 不稳定 |
| 堆排序 | O(n log n) | O(1) | 不稳定 |

## C / C++ 对应关系

| C 实现 | C++ 实现 |
|--------|---------|
| `C/Sort/Sort.c` | `C++/MySortModel/Sort.cpp` |
| `bubbleSort(arr, n)` | `Sort::bubbleSort(arr)` |
| `quickSort(arr, 0, n-1)` | `Sort::quickSort(arr, 0, n-1)` |
| 使用 `int[]` 数组 | 使用 `vector<int>` |
