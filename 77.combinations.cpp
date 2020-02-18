/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    // vector<vector<int>> combine(int n, int k) {
    //     vector<vector<int>> ret;
    //     vector<bool> used(n,false);
    //     vector<int> pre;
    //     add(n,k,used,pre,ret);
    //     return ret;
    // }
    // void add(int n,int k,vector<bool>& used ,vector<int> &pre,vector<vector<int>>& ret){
    //     if(pre.size()==k){
    //         ret.push_back(pre);
    //         return;
    //     }
    //     int last;
    //     if(pre.empty()) last =0;
    //     else last = pre[pre.size()-1];
    //     for(int i=last;i<n;i++){
    //         if(!used[i]){
    //             used[i]=true;
    //             pre.push_back(i+1);
    //             add(n,k,used,pre,ret);
    //             pre.pop_back();
    //             used[i]=false;
    //         }
    //     }
    // }
    //smarter one
    vector<vector<int>> combine(int n, int k){
        vector<vector<int>> ret;
        int i=0;
        vector<int> p(k,0);
        while(i>=0){
            p[i]++;
            if(p[i]>n) i--;
            else if(i==k-1) ret.push_back(p);
            else{
                i++;
                p[i]=p[i-1];
            }
        }
        return ret;
    }
};
// @lc code=end

