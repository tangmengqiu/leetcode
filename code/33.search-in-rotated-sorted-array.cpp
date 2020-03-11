/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target) return mid;

            if(nums[mid]<nums[right]){
                //right part is ascending
                if(nums[mid]<target&&nums[right]>=target) left=mid+1;
                else right=mid-1;
            }else{
                //left part is ascending
                if(nums[left]<=target&&nums[mid]>target) right=mid-1;
                else left=mid+1;
            }
        }
        return -1;
    }
};
// @lc code=end

