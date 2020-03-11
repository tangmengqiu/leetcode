/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> endpoints;
        vector<vector<int>> ret;
        multiset<int> hight;
        for(auto b :buildings){
            endpoints.push_back({b[0],-b[2]});
            endpoints.push_back({b[1],b[2]});
        }
        sort(endpoints.begin(),endpoints.end());
        hight.insert(0);
        int preHight =0;
        for(auto e: endpoints){
            if(e.second<0){
                // left endpoints
                hight.insert(-e.second);
            }else{
                //right endpoints
                hight.erase(hight.find(e.second));
            }
            int h = *hight.rbegin();
            if(h!=preHight){
                ret.push_back({e.first,h});
                preHight =h;
            }
        }
        return ret;
    }
};
// @lc code=end

