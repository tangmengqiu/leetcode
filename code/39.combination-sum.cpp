/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        sort(candidates.begin(),candidates.end());
        for(int i=0;i<candidates.size();i++){
            if(candidates[i]>target) break;
            if(candidates[i]==target){
                ret.push_back({candidates[i]});
                break;
            }
            vector<int> left = vector<int>(candidates.begin()+i,candidates.end());
            vector<vector<int>> tmp =combinationSum(left,target-candidates[i]);
            for(auto t:tmp){
                t.insert(t.begin(),candidates[i]);
                ret.push_back(t);
            }
        }
        return ret;
    }
      
};
// @lc code=end

