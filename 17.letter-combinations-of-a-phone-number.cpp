/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
         vector<string>letter({"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"});
         vector<string>ret;
         if(!digits.size())
            return ret;
         DFS(digits,"",ret,letter);
         return ret;
    }
    void DFS(string digit,string cur,vector<string>& ret,vector<string> letter){
        if(!digit.size()){
            ret.push_back(cur);
        }else{
            string s=letter[digit[0]-'0'];
            for(int i=0;i<s.size();i++){
                cur.push_back(s[i]);
                DFS(digit.substr(1),cur,ret,letter);
                cur.pop_back();
            }
        }
    }
    
};

