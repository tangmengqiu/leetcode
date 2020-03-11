/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros =0, twos= nums.size()-1;
        for(int i=0;i<=twos;i++){
            while(nums[i]==2&&i<twos) swap(nums[i],nums[twos--]);
            while(nums[i]==0&&i>zeros) swap(nums[i],nums[zeros++]);
        }
    }
};
// @lc code=end

