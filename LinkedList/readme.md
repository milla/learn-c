## Linked List

### 链接与顺序表比较

#### 链表：
    - 时间：每个item的读取时间复杂度为O(n)，适合主要操作在修改的（删除、插入）
    - 空间：动态分配，空间利用率略低（有指针域）
#### 顺序表：
    - 时间：随机存取，每个item的存取时间复杂度为O(1)，适合大量存取操作
    - 空间：静态分配，空间利用率100%（不考虑闲置节点）

### 代码文件说明

| Problem Title        | Links    | 
| --------   | -----  | 
| Insert Node at the end of a linked list | [Code](01-linkedlist-create.c) \| [Test](01-linkedlist-create-test.c) \| [HackRank](https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem)   | 
| Insert Node at the begining of a linked list | [Code](01-linkedlist-create.c) \| [Test](01-linkedlist-create-test.c)  \| [HackRank](https://www.hackerrank.com/challenges/insert-a-node-at-the-head-of-a-linked-list/problem)  | 
| Delete Node at a given position in a linked list | [Code](03-linkedlist-delete.c) \| [Test](03-linkedlist-delete-test.c)  \| [HackRank]( https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem)   | 
| Delete Node in a Linked List | [Code](03-linkedlist-delete.c) \| [Test](03-linkedlist-delete-test.c)  \| [LeetCode](https://leetcode.com/problems/delete-node-in-a-linked-list/description/)   | 
| Reverse a linked list | [Code](04-linkedlist-reverse.c) \| [Test](04-linkedlist-reverse-test.c)  \| [HackRank](https://www.hackerrank.com/challenges/reverse-a-linked-list) \| [LeetCode](https://leetcode.com/problems/reverse-linked-list/)    | 
| Print elements of a linked list in reverse order as standard output | [Code](04-linkedlist-reverse.c) \| [Test](04-linkedlist-reverse-test.c) \| [HackRank](https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list-in-reverse/problem) | 
| Switch a node with its next | [Code](04-linkedlist-reverse.c)   \| [Test](04-linkedlist-reverse-test.c) \| Problem | 
| Compare two linked lists A and B | [Code](05-linkedlist-compare.c) \| [Test](05-linkedlist-compare-test.c) \|  [HackRank](https://www.hackerrank.com/challenges/compare-two-linked-lists/proble)| 
| Merge two sorted lists A and B as one linked list | [Code](06-linkedlist-merge.c) \| [Test](06-linkedlist-merge-test.c) \| [HackRank](https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem) \| [LeetCode](https://leetcode.com/problems/merge-two-sorted-lists/)  | 
| Get Nth element from the end in a linked list of integers | [Code](07-linkedlist-get.c) \| [Test](07-linkedlist-get-test.c) \| [HackRank](https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem)  | 
| Get Nth element from the end in a linked list of integers | [Code](07-linkedlist-get.c) \| [Test](07-linkedlist-get-test.c) \| [HackRank](https://www.hackerrank.com/challenges/get-the-value-of-the-node-at-a-specific-position-from-the-tail/problem)  | 
| Get length | [Code](07-linkedlist-get.c) \| [Test](07-linkedlist-get-test.c) \| Problem  | 
| Get Nth element | [Code](07-linkedlist-get.c) \| [Test](07-linkedlist-get-test.c) \| Problem  | 
| Remove all duplicate elements from a sorted linked list | [Code](08-linkedlist-distinct.c) \| [Test](08-linkedlist-distinct-test.c) \| [HackRank](https://www.hackerrank.com/challenges/delete-duplicate-value-nodes-from-a-sorted-linked-list/problem)  | 
| Detect a cycle in a linked list | [Code](09-linkedlist-cycle-detection.c) \| [Test](09-linkedlist-cycle-detection-test.c) \| [HackRank](https://www.hackerrank.com/challenges/detect-whether-a-linked-list-contains-a-cycle/problem)  | 
| Find merge point of two linked lists  | [Code](101-linkedlist-find-merge-point.c) \| [Test](101-linkedlist-find-merge-point-test.c) \| [HackRank](https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem)  | 
| Split to even & odd lists | [Code](11-linkedlist-split.c) \| [Test](11-linkedlist-split-test.c) \|  Problem  | 
| List intersect | [Code](12-linkedlist-intersect.c) \| [Test](12-linkedlist-intersect-test.c) \|  Problem  | 
| List difference | [Code](103-linkedlist-diff.c) \| [Test](103-linkedlist-diff-test.c) \|  Problem  | 


### 习题来源
- [HackRank](https://www.hackerrank.com/domains/data-structures/linked-lists)
- [LeetCode](https://leetcode.com/problemset/all/?search=linked%20list)
