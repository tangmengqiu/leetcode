/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (33.16%)
 * Total Accepted:    431.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    //============================================
    // This is my first try and results show:
   
    // ✔ Accepted
    // ✔ 118/118 cases passed (8 ms)
    // ✔ Your runtime beats 98.63 % of cpp submissions
    // ✔ Your memory usage beats 11.34 % of cpp submissions (12 MB)

    //which means: time is good but space is bad! 
    //============================================

   

    string longestCommonPrefix(vector<string>& strs) {
        return ds(0,strs.size()-1,strs);
    }
    string ds(int left,int right,vector<string>& strs){
        if (left>right){
            return "";
        }else if(left==right){
            return strs[left];
        }else if(left==right-1){
            return twoStringLongestCommonPrefix(strs[left],strs[right]);
        }else{
            int mid=(left+right)/2;
            std::string leftLCP=ds(left,mid,strs);
            std::string rightLCP=ds(mid+1,right,strs);
            return twoStringLongestCommonPrefix(leftLCP,rightLCP);
        }
    }
    string twoStringLongestCommonPrefix(std::string str1,std::string str2){
        std::string lcp;
        for(int i=0;i<str1.size()&&i<str2.size();i++){
            if(str1[i]==str2[i]){
                lcp.push_back(str1[i]);
            }else{
                return lcp;
            }
        }
        return lcp;
    } 
    
   
 
};

