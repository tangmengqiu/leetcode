/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ret;
        vector<int> tmp;
        findSum(candidates,0,tmp,target,ret);
        return ret;
    }
    void findSum(vector<int> &candidates,int pos,vector<int> tmp,int target, vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(tmp);
            return;
        }else if(target<0||candidates.size()==0)
            return;
        for(int i=pos;i<candidates.size()&&candidates[i]<=target;i++){
            if(i>pos&&candidates[i]==candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            findSum(candidates,i+1,tmp,target-candidates[i],ans);
            tmp.pop_back();
        }
    }
};
// @lc code=end

