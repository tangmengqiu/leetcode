/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ret;
        if(intervals.empty()) return ret;
        sort(intervals.begin(),intervals.end(),cmp);
        for(auto it=intervals.begin();it!=intervals.end();it++){
            sort((*it).begin(),(*it).end());
        } 
        ret.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=ret.back()[ret.back().size()-1]){
                ret.back()[ret.back().size()-1]=max(intervals[i][intervals[i].size()-1],ret.back()[ret.back().size()-1]);
            }else{
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
    static bool cmp(const vector<int>&a,const vector<int>& b){
        return *(a.begin())<*(b.begin());
    }
};
// @lc code=end

