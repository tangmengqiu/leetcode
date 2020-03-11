/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.79%)
 * Likes:    1303
 * Dislikes: 92
 * Total Accepted:    376.9K
 * Total Submissions: 823.7K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        int minDis=INT_MAX;
        int ret=0;
        for(int i=0;i<nums.size()-2;i++){
          int left=i+1;
          int right=nums.size()-1;
          while(left<right){
              int tmp=nums[i]+nums[left]+nums[right];
              if(tmp==target){
                  return tmp;
              }
              if(abs(tmp-target)<minDis){
                  ret=tmp;
                  minDis=abs(target-tmp);
              }
              if(tmp<target)
                left++;
              else
                right--;
          }
        }
        return ret;
    }
};

