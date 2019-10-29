/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       // if(nums[0]>target||nums.back()<target) return {-1,-1};
        int start=lower_bound(nums,target);
        int end=lower_bound(nums,target+1)-1;
        if(start<nums.size()&&nums[start]==target) return {start,end};
        return {-1,-1};
    }
    int lower_bound(vector<int>& nums,int target){
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        return left;
    }
};
// @lc code=end

