/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        if(nums.size()<4){
            return ret;
        }
        int len=nums.size();
        for(int i=0;i<len-3;i++){
            if(i>0&&nums[i]==nums[i-1]) continue;
            if(nums[i]+nums[len-1]+nums[len-2]+nums[len-3]<target) continue;
            if(nums[i]+nums[i+2]+nums[i+1]+nums[i+3]>target) break;
            for(int j=i+1;j<len-2;j++){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                if(nums[i]+nums[j]+nums[len-1]+nums[len-2]<target) continue;
                if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                int left=j+1,right=len-1;
                while(left<right){
                    if(nums[i]+nums[j]+nums[left]+nums[right]==target){
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[left]);
                        tmp.push_back(nums[right]);
                        ret.push_back(tmp);
                        do{left++;}while(nums[left]==nums[left-1]&&left<right);
                        do{right--;}while(nums[right]==nums[right+1]&&left<right);
                    }
                    else if(nums[i]+nums[j]+nums[left]+nums[right]<target)
                        left++;
                    else 
                        right--;
                }
            }
        }
        return ret;
    }
};

