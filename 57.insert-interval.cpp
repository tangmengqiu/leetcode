/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ret;
        int p=0;
        while(p<intervals.size()&&intervals[p][1]<newInterval[0]){
            ret.push_back(intervals[p]);
            p++;
        }
        while(p<intervals.size()&&intervals[p][0]<=newInterval[1]){
            newInterval[0]=min(intervals[p][0],newInterval[0]);
            newInterval[1]=max(intervals[p][1],newInterval[1]);
            p++;
        }
        ret.push_back(newInterval);
        while(p<intervals.size()){
            ret.push_back(intervals[p]);
            p++;
        }
        return ret;
    }
};
// @lc code=end

