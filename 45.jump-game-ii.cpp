/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        //greedy
        if(nums.size()<=1) return 0;
        int end = nums[0];
        int start =0;
        int l_max = INT_MIN;
        int next_start;
        int ret =0;
        while(end<nums.size()-1){
            for(int idx=start+1;idx<=end;idx++){
                if(idx+nums[idx]>l_max){
                    l_max =idx+nums[idx];
                    next_start =idx;
                }
            }
            start=next_start;
            end = start+ nums[start];
            ret++;
        } 
        return ++ret;
    }
};
// @lc code=end

