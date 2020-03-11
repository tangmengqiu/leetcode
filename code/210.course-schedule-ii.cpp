/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>edges(numCourses);
        vector<int> degree(numCourses,0);
        for(auto pr:prerequisites){
            int before =pr[0];
            int later =pr[1];
            edges[later].push_back(before);
            degree[before]++;
        }
        queue<int> q;
        vector<int> ret;
        for(int i=0;i<numCourses;i++){
           if(!degree[i]) q.push(i);
        }
        while(!q.empty()){
            ret.push_back(q.front());
            numCourses--;
            for(int u: edges[q.front()]){
               if(--degree[u]==0){
                   q.push(u);
               } 
            }
            q.pop();
        }
        if(numCourses==0) return ret;
        else return vector<int>{};
    }
};
// @lc code=end

