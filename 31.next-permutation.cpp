/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool f=false;
        int pos=0;
        int target=-1;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]>nums[i]){
                    pos=i;
                    target=j;
                    f=true;
                }
            }
        }
        if(f){
            int tmp=nums[pos];
            nums[pos]=nums[target];
            nums[target]=tmp;
            sort(nums.begin()+pos+1,nums.end());
        }else{
            sort(nums.begin(),nums.end());
        }
        return;
    }
};
// @lc code=end

