/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.51%)
 * Likes:    4369
 * Dislikes: 498
 * Total Accepted:    626.2K
 * Total Submissions: 2.5M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.size()<3){
            return ret;
        }
        std::sort(nums.begin(),nums.end());
        int last=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==last||nums[i]>0)
                continue;
            int target=0-nums[i];
            int left=i+1,right=nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]==target){
                    vector<int> tmp={nums[i],nums[left],nums[right]};
                    ret.push_back(tmp);
                    int lastLeft=nums[left];
                    while(left+1<right&&nums[left+1]==lastLeft){
                        left++;
                    }
                    left++;
                }else if(nums[left]+nums[right]<target){
                   int lastLeft=nums[left];
                    while(left+1<right&&nums[left+1]==lastLeft){
                        left++;
                    }
                    left++;
                }else if(nums[left]+nums[right]>target){
                    int lastRight=nums[right];
                    while(right-1>left&&nums[right-1]==lastRight){
                        right--;
                    }
                    right--;
                }
            }
            last=nums[i];
        }
        return ret;
    }
};

