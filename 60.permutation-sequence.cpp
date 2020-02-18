/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
       string s;
       int fact=1;
       int i,j;
       for(int i=0;i<n;i++){
           s.push_back('0'+i+1);
           fact*=(i+1);
       }
       for(i=0,k--;i<n;i++){
           fact/=(n-i);
           j= i+ k/fact;
           char c=s[j];
           for(;j>i;j--){
               s[j]=s[j-1];
           }
           k%=fact;
           s[i]=c;
       }
       return s;
    }
   
};
// @lc code=end

