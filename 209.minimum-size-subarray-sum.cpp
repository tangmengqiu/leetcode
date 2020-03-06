/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int slow=0,fast=0,n=nums.size();
        int sum=0;
        int minLen=INT_MAX;
        while(fast<n){
            sum+=nums[fast++];
            while(sum>=s){
                minLen=min(minLen,fast-slow);
                sum-=nums[slow++];
            }
        }
        return minLen<INT_MAX?minLen:0;
    }
};
// @lc code=end

