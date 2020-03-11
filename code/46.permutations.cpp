/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
            }
        }
    }
};
// @lc code=end

