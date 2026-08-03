# 二叉树 C++ 实现 / Binary Tree (C++)

## 介绍

本模块提供基于**链式存储（指针实现）**的二叉树 C++ 实现，贴近教材的链式二叉树风格，使用独立的 `BinTreeNode` 结点类和 `BinTree` 树类。

## 文件说明

| 文件 | 说明 |
|------|------|
| `BinTreeNode.h / .cpp` | 二叉树结点类，含数据域和左右孩子指针 |
| `BinTree.h / .cpp` | 二叉树类，封装所有操作 |
| `BinTreeDemo.cpp` | 演示程序 |

## 已实现操作

### 创建
- `CreateByPreOrder()` — 从前序输入（`-1` 表示空）创建二叉树

### 遍历（时间复杂度均为 O(n)）
- `PreOrder()` — 递归前序遍历（根-左-右）
- `InOrder()` — 递归中序遍历（左-根-右）
- `PostOrder()` — 递归后序遍历（左-右-根）
- `LevelOrder()` — 层次遍历（广度优先，借助 STL queue）

### 统计
- `NodeCount()` — 统计所有结点数
- `LeafCount()` — 统计叶子结点数
- `Height()` — 计算树高

### 查找
- `Search(val)` — 前序查找第一个值等于 `val` 的结点

### 其他
- `Mirror()` — 镜像翻转（左右子树互换）
- `IsEmpty()` — 判断是否为空树

## 编译运行

```bash
# Linux/g++
g++ BinTreeNode.cpp BinTree.cpp BinTreeDemo.cpp -o bintree_demo
./bintree_demo
```

## 示例输入输出

输入（前序，-1 表示空结点）：
```
1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
```

对应二叉树结构：
```
        1
       / \
      2   3
     / \   \
    4   5   6
```

输出示例：
```
前序遍历：1 2 4 5 3 6
中序遍历：4 2 5 1 3 6
后序遍历：4 5 2 6 3 1
层次遍历：1 2 3 4 5 6

结点总数: 6
叶子结点数: 3
树的高度: 3
```

## 关键代码解析

### 层次遍历（队列辅助）

```cpp
void BinTree::LevelOrder() {
    queue<BinTreeNode*> q;
    q.push(m_pRoot);
    while (!q.empty()) {
        BinTreeNode *pNode = q.front(); q.pop();
        cout << pNode->m_iData << " ";
        if (pNode->m_pLChild) q.push(pNode->m_pLChild);
        if (pNode->m_pRChild) q.push(pNode->m_pRChild);
    }
}
```

### 树高计算（递归）

```cpp
int BinTree::heightHelper(BinTreeNode *pNode) {
    if (pNode == NULL) return 0;
    int L = heightHelper(pNode->m_pLChild);
    int R = heightHelper(pNode->m_pRChild);
    return (L > R ? L : R) + 1;
}
```

## C / C++ 对应关系

| C 实现位置 | C++ 实现位置 |
|-----------|-------------|
| `C/Tree/BinTree/` | `C++/MyBinTreeModel/` |
| `BinTree.h / BinTree.c` | `BinTree.h / BinTree.cpp` |
| `CreateBinTree_Recursion()` | `CreateByPreOrder()` |
| `PreOrder_Recursion()` | `PreOrder()` |
| `InOrder_Recursion()` | `InOrder()` |
| `PostOrder_Recursion()` | `PostOrder()` |
