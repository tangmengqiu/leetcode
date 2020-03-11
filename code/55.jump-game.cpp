/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size()-1,maxReach =0;
        for(int i=0;i<=n;i++){
            if(maxReach<i) return false;
            maxReach=max(maxReach,i+nums[i]);
            if(maxReach>=n) return true;
        }
        return false;
    }
};
// @lc code=end

