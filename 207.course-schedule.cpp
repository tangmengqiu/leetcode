/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>edges(numCourses);
        vector<int> inCount(numCourses,0);
        for(auto pr:prerequisites){
            int before =pr[0];
            int later =pr[1];
            edges[later].push_back(before);
            inCount[before]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
            if(inCount[i]==0) q.push(i);
        while(!q.empty()){
            for(auto u: edges[q.front()]){
                if(--inCount[u]==0)
                    q.push(u);
            }
            q.pop();
            numCourses--;
        }
        return numCourses==0;
    }
};
// @lc code=end

