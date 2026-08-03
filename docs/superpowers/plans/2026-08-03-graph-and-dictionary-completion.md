# Graph and Dictionary Completion Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Complete the C++ graph and dictionary topics represented by existing C modules.

**Architecture:** Keep all graph classes in `C++/MyMapModel/` and use the existing `CMap` name rather than `Map`. Give every algorithm its own header, implementation, and deterministic demo. The skip list is an independent `My*Model` C++ module with explicit ownership and reproducible random-level behavior.

**Tech Stack:** C++11, g++, `vector`, `queue`, `stack`, `cstdlib`.

---

### Task 1: Add the C++ adjacency-list graph

**Files:**
- Create: `C++/MyMapModel/MapAdjList.h`
- Create: `C++/MyMapModel/MapAdjList.cpp`
- Create: `C++/MyMapModel/AdjListDemo.cpp`

- [ ] **Step 1: Define `CMapAdjList`**

Store vertex labels and adjacency lists. Provide `addNode(char)`, `addEdge(int from, int to, int weight = 1)`, `printAdjList()`, `depthFirstTraverse(int)`, and `breadthFirstTraverse(int)`. Reject indexes outside the added-node range.

- [ ] **Step 2: Implement deterministic traversal**

Visit adjacent vertices in insertion order. Demo with `A..F` and edges `A->B`, `A->C`, `B->D`, `C->D`, `D->E`, `E->F`; print repeatable DFS and BFS output.

- [ ] **Step 3: Build, run, and commit**

Run: `cd C++/MyMapModel && g++ -std=c++11 MapAdjList.cpp AdjListDemo.cpp -o adjlist_demo && ./adjlist_demo`

```bash
git add C++/MyMapModel/MapAdjList.h C++/MyMapModel/MapAdjList.cpp C++/MyMapModel/AdjListDemo.cpp
git commit -m "feat: add C++ adjacency list graph"
```

### Task 2: Add Dijkstra and topological-sort graph modules

**Files:**
- Create: `C++/MyMapModel/MapDijkstra.h`
- Create: `C++/MyMapModel/MapDijkstra.cpp`
- Create: `C++/MyMapModel/DijkstraDemo.cpp`
- Create: `C++/MyMapModel/MapTopologicalSort.h`
- Create: `C++/MyMapModel/MapTopologicalSort.cpp`
- Create: `C++/MyMapModel/TopologicalSortDemo.cpp`

- [ ] **Step 1: Implement Dijkstra**

Expose `dijkstra(int source) const` returning `vector<int>`, using `INT_MAX` for unreachable vertices. Reject a source outside the graph. Use the C Dijkstra demo graph and print distances `0, 5, 29, 13, 17, 15` from source `0`.

- [ ] **Step 2: Implement topological sorting**

Expose `topologicalSort() const`, returning an empty vector if a cycle prevents completion. Build indegrees, enqueue zero-indegree vertices in ascending index order, and print the result. Use the existing C sample DAG and emit `0 1 2 4 5 3`.

- [ ] **Step 3: Build, run, and commit**

Run:

```bash
cd C++/MyMapModel && g++ -std=c++11 MapDijkstra.cpp DijkstraDemo.cpp -o dijkstra_demo && ./dijkstra_demo
g++ -std=c++11 MapTopologicalSort.cpp TopologicalSortDemo.cpp -o topo_demo && ./topo_demo
```

```bash
git add C++/MyMapModel/MapDijkstra.* C++/MyMapModel/DijkstraDemo.cpp C++/MyMapModel/MapTopologicalSort.* C++/MyMapModel/TopologicalSortDemo.cpp
git commit -m "feat: add C++ shortest path and topological sort"
```

### Task 3: Add C++ critical-path calculation

**Files:**
- Create: `C++/MyMapModel/MapCriticalPath.h`
- Create: `C++/MyMapModel/MapCriticalPath.cpp`
- Create: `C++/MyMapModel/CriticalPathDemo.cpp`

- [ ] **Step 1: Define the activity-network API**

Define an edge record containing source, destination, and duration. Expose `addEdge(int from, int to, int weight)` and `criticalPath(vector<EdgeInfo> &result) const`. Reject negative durations and return `false` for a cyclic graph.

- [ ] **Step 2: Implement event-time computation**

Use a topological order to calculate earliest event times forward, then initialize latest event times to the project duration and calculate backward. Add an edge to `result` only when its earliest and latest start times are equal. Preserve insertion order in demo output.

- [ ] **Step 3: Demonstrate, build, and commit**

Use the existing C critical-path network, print earliest/latest event arrays, then print the zero-slack edges. Run:

```bash
cd C++/MyMapModel && g++ -std=c++11 MapCriticalPath.cpp CriticalPathDemo.cpp -o critical_demo && ./critical_demo
```

```bash
git add C++/MyMapModel/MapCriticalPath.h C++/MyMapModel/MapCriticalPath.cpp C++/MyMapModel/CriticalPathDemo.cpp
git commit -m "feat: add C++ critical path module"
```

### Task 4: Add the C++ skip-list module

**Files:**
- Create: `C++/MySkipListModel/SkipListNode.h`
- Create: `C++/MySkipListModel/SkipListModel.h`
- Create: `C++/MySkipListModel/SkipListModel.cpp`
- Create: `C++/MySkipListModel/SkipListDemo.cpp`

- [ ] **Step 1: Define ownership and public API**

`SkipListModel` owns a head node with `maxLevel + 1` forward pointers. Implement constructor `SkipListModel(int maxLevel = 3)`, destructor, `insert(int)`, `search(int) const`, `erase(int)`, and `print() const`. Reject duplicate inserts and non-positive max levels.

- [ ] **Step 2: Implement randomized levels safely**

Use `std::rand()` only in a private `randomLevel()` and free every node exactly once in the destructor. The search, insertion, and erase traversals run from the highest level down to level zero.

- [ ] **Step 3: Demonstrate, build, and commit**

Call `std::srand(1)`, insert `10, 20, 30, 15, 25`, find `15`, reject `99`, erase `20`, and print the sorted level-zero sequence.

Run:

```bash
cd C++/MySkipListModel && g++ -std=c++11 SkipListModel.cpp SkipListDemo.cpp -o skiplist_demo && ./skiplist_demo
```

```bash
git add C++/MySkipListModel
git commit -m "feat: add C++ skip list module"
```
