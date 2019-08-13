/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 *
 * https://leetcode.com/problems/zigzag-conversion/description/
 *
 * algorithms
 * Medium (32.81%)
 * Likes:    1141
 * Dislikes: 3482
 * Total Accepted:    346.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '"PAYPALISHIRING"\n3'
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number
 * of rows like this: (you may want to display this pattern in a fixed font for
 * better legibility)
 * 
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a
 * number of rows:
 * 
 * 
 * string convert(string s, int numRows);
 * 
 * Example 1:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 3
 * Output: "PAHNAPLSIIGYIR"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "PAYPALISHIRING", numRows = 4
 * Output: "PINALSIGYAHRPI"
 * Explanation:
 * 
 * P     I    N
 * A   L S  I G
 * Y A   H R
 * P     I
 * 
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==0||s.size()==0){
            return "";
        }
        if(numRows==1){
            return s;
        }
        int size_v=2*numRows-2;
        int numGroup=(s.size()+size_v-1)/size_v;
        vector<char>  tmp [numRows];
        for(int i=0;i < numGroup;i++){
            int start=i*size_v;
            int k=0;
            for(int j=start;j<start+numRows&&j<s.size();j++){
                tmp[k++].push_back(s[j]);
            }
            for(int j=start+numRows;j<start+size_v&&j<s.size();j++){
                int row=(i+1)*size_v-j;
                tmp[row].push_back(s[j]);
            }
        }
       string ans;
       for(int i=0;i<numRows;i++){
           for(auto it=tmp[i].begin();it!=tmp[i].end();it++){
               ans.push_back(*it);
           }
       }
       return ans;
    }

};

