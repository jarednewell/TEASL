# TEASL: Ternary Tree Enhanced Append-only Skip List: A High-Performance Blockchain Data Search Index

## Introduction

TEASL’s transformational algorithm constructs a ternary tree search index from an append-only skip list, elaborating on the known inverse relationship between a binary tree and a deterministic skip list and applies it to a ternary search tree. The ternary tree is constructed from the append-only skip list data structure sequentially and in real-time with blockchain block updates. Moreover, no index data duplication exists, that is, all previously constructed updates are required to form a complete index. TEASL has more consistent blockchain data retrieval times while adapting by remaining optimal and current as the blockchain increases in size. 

TEASL is suitable for a distributed client–server model which is blockchain. In this distributed configuration, index traversal occurs in two steps: First, the local ternary tree in the TEASL index is accessed on the client device, thus reducing the search space size. Second, data is retrieved from the blockchain server via the EASL index, refined by the results of the ternary tree. Resulting in a reduced cost for data retrieval via the network. The TEASL construction algorithm allows the granularity of the ternary tree to be increased or reduced, allowing a trade-off between TEASL’s query performance times and the storage performance. This enables this indexing technique to be adapted to different resource-constrained client devices, such as IoT hardware types.

![TEASL index construction from the skip list to the ternary tree as 5 steps.](https://ars.els-cdn.com/content/image/1-s2.0-S0020025525009636-gr6_lrg.jpg)


## The Node Construction Algorithm
The algorithm and the supporting structure included in this repository is written in C++, all definitions and the implementation of TEASL is included in the following article:

https://doi.org/10.1016/j.ins.2025.122827

## Reference
If you intend on using TEASL and this repository we request you reference using the following:

Harvard
```
Newell, J., Rehman, S. ur, Mamun, Q. and Islam, M.Z. (2026)
‘Ternary tree enhanced append-only skip list: A high-performance blockchain data search index’,
Information Sciences, 730, p. 122827.
doi: https://doi.org/10.1016/j.ins.2025.122827.
```

APA
```
Newell, J., Rehman, S. u., Mamun, Q., & Islam, M. Z. (2026).
Ternary tree enhanced append-only skip list: A high-performance blockchain data search index.
Information Sciences, 730, 122827.
https://doi.org/10.1016/j.ins.2025.122827
```

BibTeX
```
@article{NEWELL2026122827,
title = {Ternary tree enhanced append-only skip list: A high-performance blockchain data search index},
journal = {Information Sciences},
volume = {730},
pages = {122827},
year = {2026},
issn = {0020-0255},
doi = {https://doi.org/10.1016/j.ins.2025.122827},
url = {https://www.sciencedirect.com/science/article/pii/S0020025525009636},
author = {Jared Newell and Sabih ur Rehman and Quazi Mamun and Md Zahidul Islam},
keywords = {Blockchain, Data index, Append-only skip list, Ternary tree, Search algorithm, Internet of things},
}
```
