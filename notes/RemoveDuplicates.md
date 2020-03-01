# <center>RemoveDuplicates</center>
---

## 1思路
加入要求一个排好序的数组重复的元素最多出现 2次，那么可以选择直接在元数组上覆盖
```
int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int n: nums){
            if(i<2||n>nums[i-2])
                nums[i++]=n;
        }
        return i;
}
```
可以很轻易地扩展到：
排好序的数组元素重复不得超过k 个：
```
int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int n: nums){
            if(i<k||n>nums[i-k])
                nums[i++]=n;
        }
        return i;
}
```
---