/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (43.08%)
 * Likes:    4448
 * Dislikes: 155
 * Total Accepted:    551.8K
 * Total Submissions: 1.3M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=INT_MIN;
        for(int i=0;i<nums.size();i++){
            int temp=0;
            for(int j=i;j<nums.size();j++){
                temp+=nums[j];
                if (temp>maxSum)
                    maxSum=temp;
                if (temp<0&&nums[j]<0){
                    i=j;
                    break;
                }
            }
        }
        return maxSum;
    }
};

