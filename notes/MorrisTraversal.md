# <center>Morris Traversal</center>
---
## 1.介绍
通常树的遍历可以采用两种办法：
* 递归，代价是递归栈的内存消耗 o(n)
* 用栈来模拟递归，代价是栈的内存申请 o(n)


Morris 遍历可以使用于:空间：o(1),时间：o(n), 不允许使用栈的情况。

## 2.Morris 原理：
他用到了线索二叉树的概念:
>一个二叉树通过如下的方法“穿起来”：所有应该为空的右孩子指针指向该结点在中序序列中的后继，所有应该为空的左孩子指针指向该结点的中序序列的前驱

Morris不需要为每个节点额外分配指针指向其前驱（predecessor）和后继节点（successor），只需要利用`叶子节`点中的左右空指针指向某种顺序遍历下的前驱节点或后继节点就可以了。morris遍历利用的是树的叶节点左右孩子为空（树的大量空闲指针），实现空间开销的极限缩减。
## 3.Morris 原则
>1.如果cur无左孩子，cur向右移动（cur=cur.right）

>2.如果cur有左孩子，找到cur左子树上最右的节点，记为mostright
>* 2.1如果mostright的right指针指向空，让其指向cur，cur向左移动（cur=cur.left）
>* 2.2如果mostright的right指针指向cur，让其指向空，cur向右移动（cur=cur.right）

## 4.根据这两条原则模拟遍历

![](https://tva1.sinaimg.cn/large/0082zybpgy1gc8hnh7hxtj30ue0ewjxi.jpg)

* s1: cur=1，其左子树最右的节点是5，根据规则2.1：`node(5).right = 1` cur左移到2
* s2: cur=2,其左子树最左节点是4，根据规则2.1：`node(4).right = 2` cur左移到4；
* s3: cur=4,无左孩子,根据规则1：因为在s2中，cur=4的right指针指向了 2，所以cur回到2
* s4: cur=2,有左孩子,其左子树最左节点是4，根据规则2.2：将node(4)的right置空（恢复树形状），cur移动到5
* s5: cur=5,无左孩子,根据规则1：因为在s1中，node(5)的right指针指向了node(1)，所以cur回到  1;
* s6: cur=1,有左孩子,其左子树最左节点是5，根据规则2.2：将node(5)的right置空（恢复树形状），cur向右移动到3

...重复以上过程

### 3.1实现前序遍历
```
void morrisPre(TreeNode *root) {
    if(root == null){
        return;
    }
    TreeNode* cur = root;
    TreeNode* mostRight = null;
    while (cur != nullptr){
        mostRight = cur->left;

        //如果cur存在左孩子，规则2：
        if(mostRight != null){
            // 向左子树的最右边遍历，寻找mostRight
            while (mostRight->right !=null && mostRight->right != cur){
                mostRight = mostRight->right;
            }
            // 规则2.1
            if(mostRight->right == null){
                mostRight->right = cur;
                // visit(cur);
                cur = cur->left;
                continue;
            }else {
                //规则2.2
                mostRight->right = null;
                cur = cur->right;
            }
        }else {
            //不存在左子树，规则1
            // visit(cur);
            cur = cur->right;
        }
    }
}
```


### 3.2实现后序遍历
后序遍历的处理要复杂一点，基本流程不变，只是在出现触发规则：2.1的时候，将most->right置空，并且cur=cur->right时，要将cur左孩子的反斜45°那条路径（下图虚线所示）上的节点反向遍历，如果不好理解看下图：

![](https://tva1.sinaimg.cn/large/0082zybpgy1gc94h8lh9uj30ys0ochdt.jpg)

例如，当从发现d->right=b=cur时，就将最左的斜线（只包含d)反向遍历：[d],第二次触发 b->right=a=cur时，将第二条斜线反向遍历加入统计：[d,e,b],以此类推，但需要注意最后一个点是g点，需要特殊处理，应该将root(1)->g这条路径方向遍历，所以在处理过程中，每一次cur像右移动，都应该记录下一次，最后的记录就是整个树最右的节点（g)。

例题：[145.二叉树后序遍历](145.binary-tree-postorder-traversal.cpp)
