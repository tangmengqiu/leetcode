/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        vector<bool> flag(nums.size());
        vector<int> tmp;
        add(0,flag,tmp,nums,ret);
        return ret;
    }
    void add(int cnt,vector<bool> &flag,vector<int> &tmp,vector<int> &nums,vector<vector<int>> &ret){
        if(cnt==nums.size()){
            ret.push_back(tmp);
            return;
        }
       
        for(int i=0;i<flag.size();i++){
            if(!flag[i]){
                flag[i]=true;
                tmp.push_back(nums[i]);
                add(cnt+1,flag,tmp,nums,ret);
                flag[i]=false;
                tmp.pop_back();
                while(i<flag.size()-1&&nums[i]==nums[i+1]){
                    i++;
                }
            }
        }
        
    }
};
// @lc code=end

