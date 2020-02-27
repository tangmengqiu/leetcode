/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ret;
        vector<vector<int>> adj(n);
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        vector<bool> pushed(n,false);
        for(int i=0;i<n;i++){
            if(adj[i].size()<=1){
                q.push(i);
                pushed[i]=true;
            }
                
        }
        while(n>2){
            int qs= q.size();
             queue<int> tmp;
            for(int i=0;i<qs;i++){
                int cur =q.front();
                q.pop();
                n--;
                for(auto nb:adj[cur]){
                    auto it = find(adj[nb].begin(),adj[nb].end(),cur);
                    if(it!=adj[nb].end()){
                        adj[nb].erase(it);
                    }
                    if(adj[nb].size()<=1&&!pushed[nb]){
                        tmp.push(nb);
                        pushed[nb]=true;

                    }
                }
            }
            q=tmp;
        }
        while(!q.empty()){
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};
// @lc code=end

