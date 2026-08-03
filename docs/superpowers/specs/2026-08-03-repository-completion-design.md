# DataStructures Repository Completion Design

**Date:** 2026-08-03

## Goal

Complete the undergraduate-level, single-language gaps in the repository, then make the root README and every module guide accurate, bilingual, and consistent with the author's existing teaching-oriented style.

The README must be a durable repository index. It must not contain repair logs, phase summaries, or other time-sensitive change history.

## Scope

### Phase 1: Basic Structures and Trees

- Add a C string/KMP module.
- Add a C general-tree module.
- Extend `C++/MyBinTreeModel/` with non-recursive traversal and level-order operations.
- Add independent C++ modules for threaded binary trees, Huffman trees, and binary search trees.

### Phase 2: Graphs and Dictionary

- Extend `C++/MyMapModel/` with an adjacency-list representation, Dijkstra shortest paths, topological sorting, and critical-path calculation.
- Add an independent C++ skip-list module.

### Phase 3: Documentation

- Rewrite the root `README.md` as a concise Chinese/English repository guide.
- Remove bug-fix and phase-addition logs from the README.
- Replace the implementation table with paths, capabilities, and accurate availability notes.
- Update every existing C and C++ module guide with complete Chinese and English content.
- Create bilingual guides for all new modules.

## Module Design

Existing directories, public naming patterns, and teaching-oriented layouts remain intact. Each module continues to use a header, implementation source, standalone demo, and guide where that is the local convention.

- C implementations use explicit ownership, input checks, and conventional C error returns.
- C++ implementations preserve the repository's class-based teaching style. Where raw pointers are used to demonstrate a structure, destructors release all owned allocations.
- The graph additions stay within `C++/MyMapModel/` and use class families compatible with `MapBasic` and `MapAdv*`.
- New C++ tree and dictionary structures use focused directories so each can be learned and compiled independently.

## Documentation Style

Chinese remains the primary narrative and preserves the repository's explanatory, example-led style: definitions, operational steps, inline annotations, diagrams or code examples where useful, and file-by-file introductions. Each complete Chinese section is followed by an equivalent English section rather than a partial index translation.

The README uses durable sections only:

1. Repository purpose and language coverage.
2. Navigation by language and topic.
3. Accurate implementation matrix with paths and capability notes.
4. Local compilation guidance and platform caveats.
5. Link index for detailed bilingual guides.

The phrase `本科学习中未涉及` is used only for an item that is genuinely outside the agreed undergraduate scope. The planned items are all in scope and therefore receive implementations rather than placeholder explanations.

## Quality and Verification

Every new module has a deterministic demo. New code rejects invalid arguments or allocation failures explicitly and does not silently continue with invalid state. Existing code is not refactored except where a direct integration dependency requires a targeted correction.

Before delivery:

- Build and run each new or extended C demo with its required source files.
- Build and run each new or extended C++ demo with its required source files.
- Check every README and guide link against the final file layout.
- Check the root implementation matrix against the actual source and documented capabilities.

## Out of Scope

- Introducing third-party dependencies or a new global build system.
- Rewriting unrelated legacy implementations.
- Adding structures beyond a standard undergraduate data-structures curriculum.
