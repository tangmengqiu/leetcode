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

---