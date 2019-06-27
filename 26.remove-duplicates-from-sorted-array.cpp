/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution {
    public: int removeDuplicates(vector<int> & nums) {
        int len = 0;
        int s = nums.size();
        if(s==0){
            return 0;
        }
        for (int i = 0; i < s; i++) {
            if(nums[i]>nums[len]){
                nums[++len]=nums[i];
            }
        }
        return len+ 1;
    }
};

