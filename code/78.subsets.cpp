/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        int n =nums.size();
        vector<int> emp;
        ret.push_back(emp);
        for(int i=1;i<=nums.size();i++){
            vector<int> tmp;
            backTrack(nums,n,ret,tmp,i,0);
        }
        return ret;
    }
    void backTrack(vector<int> &nums,int n,vector<vector<int>> &ret,vector<int> &tmp,int need,int idx){
        if(need==0) {
            ret.push_back(tmp);
            return ;
        }
        if(idx>=n) return;
        for(int i=idx;i<n;i++){
            tmp.push_back(nums[i]);
            backTrack(nums,n,ret,tmp,need-1,i+1);
            tmp.pop_back();
        }
    }
};
// @lc code=end

