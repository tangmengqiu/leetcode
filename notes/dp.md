
# <center>Dynamic Planning</center>
---

计算 1+2+3+4 = ?  10 (计算事会挨个加起来，耗时4个单位）

那计算 1+2+3+4 +5 =？ ->15 （很快得出答案，耗时两个单位，为何？因为我记住了前面是10，在10基础上加上5，很快就能算出答案是15）

所以动归的核心思想就是：记住已经解决过子问题的解（空间换时间）

问题的性质：求出f(n)，只需要知道几个更小的f(c)。我们将求解f(c)称作求解f(n)的“子问题”。

这就是DP（动态规划，dynamic programming）：

　　将一个问题拆成几个子问题，分别求解这些子问题，即可推断出大问题的解。

求解的方式有两种：①自顶向下的备忘录法 ②自底向上

动态规划的三大步骤
第一步骤：定义数组元素的含义

第二步骤：找出数组元素之间的关系式（也就是可以利用历史数据来推出新的元素值）

第三步骤：找出初始值。（即边界）

以85.Maximal Rectangle 为例，计算‘1’所占最大矩形面积：

![](https://tva1.sinaimg.cn/large/006tNbRwly1g9koujmufhj30ge0a0jrq.jpg)

计算矩形面积，需要知道长和高，按每一行处理，高即为当前第 j 行往上连续为1的个数，长度即为该高度左右扫动的最大距离，扫动条件为该高度上全是1.

设 用hight [][] hight[i][j]记录该点的高度，那么left[i][j]为该点扫动的最左，right[i][j]即为最右（第一步，定义数组元素含义）

第二步:推导
```
height[i][j] = matrix[i][j] == '1' ? height[i - 1][j]++ : 0;
left[i][j] = max(left[i - 1][j], currLeft)，currLeft表示对ith行而言，从（i，j)向左连续为'1'直至(i, currLeft)那个点;
right[i][j] = min(right[i - 1][j], currRight)， currRight表示ith行而言，从（i，j)向右连续为'1'直至(i, currRight - 1)那个点;
```
第三步:初始化

显然hight 全部初始为0，left也初始为0,right初始为 n。值得注意的是，我们在计算第`i`行的`hight,elft,right`时，只依赖到了第`i-1`行的状态（若当前是'1'，则hight[j]++,即在计算前，hight[j]是上一轮的状态，加个1就好了，同理，left[j]=max(left[j],curLeft),right[j]=min(right[j].curRight);若当前是'0'，则hight归零，【left也归零，curLeft=j+1, right设为n,curRight=j】方便下次计算)，所以不需要用到二维数组，只需要一维数组，保存上一行的状态就可。

另外，数组的初始化，初始为非`0`数值时，不可用`memset`,一定不要（除非是`char`类型）！用`fill`替代！

完整题解：
 [85.maximal-rectangle](https://github.com/tangmengqiu/leetcode/blob/master/85.maximal-rectangle.cpp),