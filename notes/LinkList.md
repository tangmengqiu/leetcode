# <center>LinkList</center>
---

## 1链表去重
思路：不要想着在原链表上直接操作，那样比较麻烦，可以换一条思路，对于当前处理的node，如果它不重复，则把它加入新的一条链表中，如果重复直接跳过。
详细结题：[82.Remove Duplicates from Sorted List II](https://github.com/tangmengqiu/leetcode/blob/master/82.remove-duplicates-from-sorted-list-ii.cpp)

## 2链表翻转
![](https://tva1.sinaimg.cn/large/0082zybpgy1gbxhizo350j30q804qdg4.jpg)

如图所示，想要翻转第m 到第n个元素之间的一截链表，思路是：前M-1个元素原样遍历，记第m -1个元素为 pre ,第m 个为cur ,那么只需要将 cur后面的元素一次重复插入至pre后面,重复 n-m此，注意是n-m此而不是n-m+1次，是因为一共要翻转的是n-m+1个元素，但是第m个后面的 n-m个翻转后，m已经处在了正确的位置上，所以不用再做处理。这里也保证了下面代码 `cur->next->next`的正确性,这里用到一个方法：将cur后面一个元素挪到cur前一个位置上，pre之后：
```
 ListNode* tmp=pre->next;
 pre->next =cur->next;
 cur->next=cur->next->next;
 pre->next->next=tmp;
```
这里 使用了`cur->next->next`不做检查是因为 只处理 n-m个节点保证了cur节点后面至少还有一个节点。
详细结题：[92.reverse-linked-list-ii](https://github.com/tangmengqiu/leetcode/blob/master/92.reverse-linked-list-ii.cpp)
---