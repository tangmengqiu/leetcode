/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*
            better solution:
            int counter = 0, majority;
            for (int num : nums) {
                if (!counter) {
                    majority = num;
                }
                counter += num == majority ? 1 : -1;
            }
            return majority;
        */
        sort(nums.begin(),nums.end());
        if(nums.size()==1) return nums[0];
        for(int i=0;i<nums.size()-1;i++){
            int count=0;
            while(i<nums.size()-1&&nums[i+1]==nums[i]){
                count++;
                i++;
            }
            if(count>=nums.size()/2)
                return nums[i];
        }
        return 0;
    }
};
// @lc code=end

