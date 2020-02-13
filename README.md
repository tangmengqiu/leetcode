# <center>leetcode journey</center>


### start date : 2019-3-30

### language : c++

## Notes
---
### 1. 二分查找
二分查找的变种非常丰富，对应33-35等题
### 1.1 严格相等
```
/**
 * 二分查找，找到该值在数组中的下标，否则为-1
 */
int binarySerach(vector<int> array, int key) {
    int left = 0;
    int right = array.size() - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;
        if (array[mid] == key) {
            return mid;
        }
        else if (array[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1;
}
```
二分查找中可以找等于目标的下标，当数组中出现可重复数字时也可以找第一个等于，最后一个等于，第一个大于，最后一个小于等等。。。
### 1.2 第一个相等
```
/**
 * 二分查找，找到该值在数组中第一次出现的下标，否则为-1
 */
int findFirstEqual(vector<int>& array, int key) {
    int left = 0;
    int right = array.size() - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;
      
        else if (array[mid] >= key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    //循环退出后，检查left下标是否合法、key在数组中是否存在
    if(left<array.size() && array[left]==key) return left;
    return -1;
}
```
![](https://tva1.sinaimg.cn/large/006y8mN6ly1g8f5eqot3wj30as063glu.jpg)

如上图所示，循环退出时，array[right]<key ,array[left]>=key ,所以要找的第一个相等的位置只可能是left(下标left合法，且取值为key，所以退出循环后还要加个判断)

### 1.3 最后一个相等
```
/**
 * 二分查找，找到该值在数组中最后一次出现的下标，否则为-1
 */
int findLastEqual(vector<int> array, int key) {
    int left = 0;
    int right = array.size() - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;
        else if (array[mid] <= key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    //循环退出后，检查right下标是否合法、key在数组中是否存在
    if(right>=0 && array[right]==key) return right;
    return -1;
}
```
![](https://tva1.sinaimg.cn/large/006y8mN6ly1g8f5ro32glj30bd05u0t0.jpg)

如上图所示，循环退出时，array[right]<= key ,array[left]>key ,所以要找的最后一个相等的位置只可能是right(下标right合法，且取值为key，所以退出循环后还要加个判断)
### 1.4最后一个小于或者等于Key的元素
```
// 查找最后一个等于或者小于key的元素
int findLastEqualSmaller(vector<int> array, int key) {
    int left = 0;
    int right = array.length - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;

        //如果把条件设为：查找最后一个小于key的下标
        //则这个if条件应该为： array[mid]>= key
        if (array[mid] > key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return right;
}
```
![](https://tva1.sinaimg.cn/large/006y8mN6ly1g8f5ro32glj30bd05u0t0.jpg)

如上图所示，循环退出时，array[right]<=key ,array[left]> key ,所以要最后一个小于等于key的位置就是right，且不需要判断

### 1.5 查找第一个大于或者等于key的元素下标
```
// 查找第一个等于或者大于key的元素
int findFirstEqualLarger(vector<int>& array, int key) {
    int left = 0;
    int right = array.size() - 1;

    // 这里必须是 <=
    while (left <= right) {
        int mid = (left + right) / 2;
        //如果把条件设为：查找第一个大于key的下标
        //则这个if条件应该为： array[mid]> key
        if (array[mid] >= key) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}
```
这里就不再用图赘述，总之，循环退出前最后一次左移right，保证了退出后left所指位置值>=key ，同理，退出后，right所指位置值 < key，故所指位置是第一个大于等于key的值。


### 2. 动态规划

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

### 3. 图片旋转

#### 3.1顺时针旋转90度：
step1: 先沿对角线将元素对换
step2: 沿中线，将对应两列元素对换
题解：[48.rotate-image](https://github.com/tangmengqiu/leetcode/blob/master/48.rotate-image.cpp) ,


---