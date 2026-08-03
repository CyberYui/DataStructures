# Bilingual Documentation Implementation Plan

> **For agentic workers:** REQUIRED SUB-SKILL: Use superpowers:subagent-driven-development (recommended) or superpowers:executing-plans to implement this plan task-by-task. Steps use checkbox (`- [ ]`) syntax for tracking.

**Goal:** Replace outdated and incomplete repository documentation with accurate, complete Chinese/English guides that match the final source tree.

**Architecture:** The root README is the durable bilingual navigation and coverage index; module guides explain one topic at a time. Preserve the author's concept-first, example-led teaching style and existing inline HTML where it improves explanation. Do not place changelogs, repair narratives, or phase reports in the README.

**Tech Stack:** Markdown, existing GitHub links, gcc/g++ commands already proven by module demos.

---

### Task 1: Rewrite the root README

**Files:**
- Modify: `README.md`

- [ ] **Step 1: Replace the current duplicated structure**

Write one Chinese section and one equivalent English section. Include repository purpose, language coverage, topic navigation, compilation examples, and links to every detailed module guide. Remove `本次修复说明 / Bug Fixes`, `阶段二新增内容 / Phase 2 Additions`, historical “已修复” labels, and any directory name explanation that is only a repair log.

- [ ] **Step 2: Publish an accurate implementation matrix**

For each structure, list C and C++ paths after the code phases are complete. Distinguish separately implemented modules from expanded operations in an existing module. Do not leave an em dash for any planned undergraduate topic. If a future item is genuinely outside scope, label it exactly `本科学习中未涉及 / Not covered in undergraduate study`.

- [ ] **Step 3: Validate all root links and commit**

Run:

```bash
python3 - <<'PY'
from pathlib import Path
import re
text = Path("README.md").read_text()
for path in re.findall(r'`((?:C|C\+\+)/[^`]+)`', text):
    assert Path(path).exists(), path
PY
```

```bash
git add README.md
git commit -m "docs: rewrite bilingual repository README"
```

### Task 2: Make every C guide bilingual and current

**Files:**
- Modify: all existing `C/**/*.md` guides
- Create: `C/String/String_C_Learning.md`
- Create: `C/Tree/GeneralTree/GeneralTree_Info.md`

- [ ] **Step 1: Preserve and complete the Chinese narrative**

For every C guide, retain its topic definitions, derivations, code walkthroughs, and examples. Correct stale paths and wording, add the C string and general-tree cross-references to `C/Tree/Tree_C_Learning.md` and the root-facing topic index, and explain files and demo commands where absent.

- [ ] **Step 2: Add full English counterparts**

After each guide's complete Chinese content, add `## English` with the same definitions, operation explanations, examples, complexity notes, file roles, and compile/run instructions. Translate technical meaning rather than line-by-line syntax; keep code blocks and paths identical.

- [ ] **Step 3: Check links and commit**

Run:

```bash
find C -name '*.md' -print0 | xargs -0 grep -L '^## English$'
```

Expected: no output.

```bash
git add C
git commit -m "docs: complete bilingual C module guides"
```

### Task 3: Make every C++ guide bilingual and current

**Files:**
- Modify: `C++/MyBinTreeModel/BinTreeInfo.md`
- Modify: `C++/MyLinkedListModel/LinkedList.md`
- Modify: `C++/MyListModel/ListInfo.md`
- Modify: `C++/MyMapModel/MapInfo.md`
- Modify: `C++/MyOwnString/StringInfo.md`
- Modify: `C++/MyQueueModel/QueueInfo.md`
- Modify: `C++/MySortModel/SortInfo.md`
- Modify: `C++/MyStackModel/StackInfo.md`
- Modify: `C++/MyTreeModel/TreeInfo.md`
- Create: `C++/MyThreadBinTreeModel/ThreadBinTreeInfo.md`
- Create: `C++/MyHuffmanTreeModel/HuffmanTreeInfo.md`
- Create: `C++/MyBSTreeModel/BSTInfo.md`
- Create: `C++/MySkipListModel/SkipListInfo.md`

- [ ] **Step 1: Update Chinese module descriptions**

Use the existing file-by-file introduction style. `BinTreeInfo.md` must cover non-recursive traversals; `MapInfo.md` must cover adjacency list, Dijkstra, topological sort, and critical path; each new guide must document public operations, deterministic demo input/output, ownership behavior, and exact g++ command.

- [ ] **Step 2: Add full English counterparts**

Append an `## English` equivalent to every existing C++ guide and write both language sections in new guides. Avoid historical phrases such as “新增” or “阶段”; describe final capabilities only.

- [ ] **Step 3: Validate guide coverage and commit**

Run:

```bash
find 'C++' -name '*.md' -print0 | xargs -0 grep -L '^## English$'
```

Expected: no output.

```bash
git add 'C++'
git commit -m "docs: complete bilingual C++ module guides"
```

### Task 4: Reconcile documentation with source

**Files:**
- Modify: `README.md` and any guide with a stale link, path, or command

- [ ] **Step 1: Verify all documented project paths**

Extract backticked `C/` and `C++/` paths from all Markdown files and verify every path exists. Inspect compile commands against the corresponding source files and correct any that omit a required implementation file.

- [ ] **Step 2: Verify durable README content**

Confirm no heading or section contains `修复`, `Bug Fix`, `阶段`, `Phase`, `新增`, or `Additions`. Confirm the implementation table lists all final C/C++ pairs.

- [ ] **Step 3: Commit reconciliation**

```bash
git add README.md C 'C++'
git commit -m "docs: reconcile repository documentation"
```
