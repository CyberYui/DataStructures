# Basic and Tree Completion Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Add the undergraduate-level C and C++ basic-structure and tree implementations absent from the repository.

**Architecture:** Preserve the repository's standalone teaching-module layout: a header, implementation, deterministic demo, and later bilingual guide. C modules use opaque pointer aliases and explicit destroy functions. C++ modules use focused classes with constructors and destructors; non-recursive traversal belongs in the existing `BinTree` class.

**Tech Stack:** C11, C++11, gcc, g++, standard library containers only.

---

### Task 1: Add the C string and KMP module

**Files:**
- Create: `C/String/String.h`
- Create: `C/String/String.c`
- Create: `C/String/main.c`

- [ ] **Step 1: Add the public string interface**

Define `MyString` as `{ char *str; int length; }` and declare `CreateString`, `DestroyString`, `StringLength`, `StringCompare`, `Index_BF`, `GetNext`, `GetNextVal`, and `Index_KMP`. Use 0-based positions and return `-1` for invalid arguments or no match.

- [ ] **Step 2: Add deterministic demonstrations**

Use `text = "ababcabcacbab"` and `pattern = "abcac"`; both brute-force and KMP searches must report index `5`. Use `"aaaaa"` and `"bba"` to demonstrate the `-1` no-match case. Destroy all allocated strings and arrays before return.

- [ ] **Step 3: Build and run the module**

Run: `cd C/String && gcc -std=c11 -Wall -Wextra String.c main.c -o string_demo && ./string_demo`

Expected: the two matching methods return `5`; the no-match case returns `-1`.

- [ ] **Step 4: Commit the module**

```bash
git add C/String
git commit -m "feat: add C string KMP module"
```

### Task 2: Add the C general-tree module

**Files:**
- Create: `C/Tree/GeneralTree/GeneralTree.h`
- Create: `C/Tree/GeneralTree/GeneralTree.c`
- Create: `C/Tree/GeneralTree/main.c`

- [ ] **Step 1: Define the child-sibling representation**

Declare `CTNode` with `data`, `firstchild`, and `nextsibling`; typedef `CTree` as `CTNode *`. Declare `CreateNode`, `AddChild`, `PreOrder`, `PostOrder`, `TreeDepth`, `NodeCount`, `LeafCount`, `FindNode`, and `DestroyTree`.

- [ ] **Step 2: Implement ownership and traversal operations**

`CreateNode` returns `NULL` after an allocation failure. `AddChild` rejects `NULL` parent or child and appends a child after the existing sibling chain. `TreeDepth(NULL)` returns `0`; `LeafCount` treats a node with no `firstchild` as one leaf; `DestroyTree` frees a child subtree before its sibling.

- [ ] **Step 3: Add the fixed classroom tree demo**

Create `A(B(C,D),E(F))` using `CreateNode` and `AddChild`. Print preorder `A B C D E F`, postorder `C D B F E A`, depth `3`, node count `6`, leaf count `3`, and a successful search for `E`.

- [ ] **Step 4: Build and run the module**

Run: `cd C/Tree/GeneralTree && gcc -std=c11 -Wall -Wextra GeneralTree.c main.c -o general_tree_demo && ./general_tree_demo`

Expected: all fixed traversal and statistic values are printed, then the tree is destroyed without diagnostics.

- [ ] **Step 5: Commit the module**

```bash
git add C/Tree/GeneralTree
git commit -m "feat: add C general tree module"
```

### Task 3: Extend the C++ binary-tree traversal API

**Files:**
- Modify: `C++/MyBinTreeModel/BinTree.h`
- Modify: `C++/MyBinTreeModel/BinTree.cpp`
- Create: `C++/MyBinTreeModel/BinTreeNRDemo.cpp`

- [ ] **Step 1: Add the three public operations**

Declare `PreOrderNonRecursion()`, `InOrderNonRecursion()`, and `PostOrderNonRecursion()` with the existing comment-banner format. Keep the existing recursive and `LevelOrder()` APIs unchanged.

- [ ] **Step 2: Implement stack-based traversals**

Use `std::stack<BinTreeNode *>`. Preorder pushes right before left; inorder iterates leftward then visits; postorder uses a last-visited pointer. For an empty tree, print the existing traversal label followed by a newline and do not dereference `m_pRoot`.

- [ ] **Step 3: Add and run the deterministic demo**

Build the current preorder-input tree `1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1`. Print non-recursive preorder `1 2 4 5 3 6`, inorder `4 2 5 1 3 6`, postorder `4 5 2 6 3 1`, and existing level order `1 2 3 4 5 6`.

Run: `cd C++/MyBinTreeModel && g++ -std=c++11 BinTreeNode.cpp BinTree.cpp BinTreeNRDemo.cpp -o bintree_nr_demo && printf '1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1\n' | ./bintree_nr_demo`

- [ ] **Step 4: Commit the extension**

```bash
git add C++/MyBinTreeModel/BinTree.h C++/MyBinTreeModel/BinTree.cpp C++/MyBinTreeModel/BinTreeNRDemo.cpp
git commit -m "feat: add nonrecursive C++ binary traversals"
```

### Task 4: Add C++ threaded binary tree, Huffman tree, and BST modules

**Files:**
- Create: `C++/MyThreadBinTreeModel/ThreadBinTreeNode.h`
- Create: `C++/MyThreadBinTreeModel/ThreadBinTree.h`
- Create: `C++/MyThreadBinTreeModel/ThreadBinTree.cpp`
- Create: `C++/MyThreadBinTreeModel/ThreadBinTreeDemo.cpp`
- Create: `C++/MyHuffmanTreeModel/HuffmanTree.h`
- Create: `C++/MyHuffmanTreeModel/HuffmanTree.cpp`
- Create: `C++/MyHuffmanTreeModel/HuffmanTreeDemo.cpp`
- Create: `C++/MyBSTreeModel/BSTNode.h`
- Create: `C++/MyBSTreeModel/BST.h`
- Create: `C++/MyBSTreeModel/BST.cpp`
- Create: `C++/MyBSTreeModel/BSTDemo.cpp`

- [ ] **Step 1: Implement the threaded tree**

`ThreadBinTreeNode` contains `m_iData`, child pointers, and `m_iLTag`/`m_iRTag`. `ThreadBinTree` exposes `CreateByPreOrder`, `InThreading`, `InOrderThreadTraverse`, and `IsEmpty`. Threading must create predecessor/successor links only where a child pointer is `NULL`; destruction must follow real-child tags only. Demonstrate inorder output `4 2 5 1 3 6` from the same fixed tree as Task 3.

- [ ] **Step 2: Implement the Huffman tree**

Expose `CreateByWeights(const int weights[], int n)`, `PreOrder()`, and `WPL() const`. Represent each node with `weight`, `parent`, `lchild`, and `rchild`; select the two minimum parentless nodes at each construction step. With `{5, 9, 12, 13, 16, 45}`, report root weight `100` and WPL `224`. Reject null arrays and `n < 2`.

- [ ] **Step 3: Implement the BST**

Expose `Insert(int)`, `Search(int)`, `Delete(int)`, `InOrder()`, `PreOrder()`, `PostOrder()`, and `Height()`. Reject duplicate inserts. Deletion handles leaf, one-child, and two-child nodes by replacing the target with its inorder successor. Insert `50, 30, 70, 20, 40, 60, 80`, print inorder `20 30 40 50 60 70 80`, find `60`, delete `30`, and print `20 40 50 60 70 80`.

- [ ] **Step 4: Build and run all three demos**

Run:

```bash
cd C++/MyThreadBinTreeModel && g++ -std=c++11 ThreadBinTree.cpp ThreadBinTreeDemo.cpp -o thread_bintree_demo
cd ../MyHuffmanTreeModel && g++ -std=c++11 HuffmanTree.cpp HuffmanTreeDemo.cpp -o huffman_tree_demo && ./huffman_tree_demo
cd ../MyBSTreeModel && g++ -std=c++11 BST.cpp BSTDemo.cpp -o bst_demo && ./bst_demo
```

Expected: threaded inorder, Huffman root/WPL, and BST before/after-deletion outputs match the stated examples.

- [ ] **Step 5: Commit the tree modules**

```bash
git add C++/MyThreadBinTreeModel C++/MyHuffmanTreeModel C++/MyBSTreeModel
git commit -m "feat: add advanced C++ tree modules"
```
