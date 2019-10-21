/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {\
        vector<int> ret;
        if (words.size()==0) return ret;
        map<string,int> dict;
        for(string w :words) ++dict[w];
        int len=words[0].length();
        int cnt=words.size();
        int lastScan=0;
        for(int i=0;i<len;i++){
            map<string,int> m;
            int count=0;
            int left=i;
            for(int j=i;j<s.length()-len;j+=len){
                string word=s.substr(j,len);
                if(dict[word]){
                    m[word]++;
                    if(m[word]<=dict[word]){
                        count++;
                    }else{
                        while(m[word]>dict[word]){
                            string w=s.substr(left,len);
                            m[w]--;
                            if(m[w]<dict[w]) count--;
                            left+=len;
                        }
                    }
                    if(count==cnt){
                        ret.push_back(left);
                        m[s.substr(left,len)]--;
                        count--;
                        left+=len;
                    }
                }else{
                    m.clear();
                    left+=len;
                    count=0;
                }
            }
        }
        return ret;
    }
   
};
// @lc code=end

