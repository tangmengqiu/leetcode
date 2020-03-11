/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
class Solution {
public:
    bool isValid(string s) {
        int len=s.length();
        if ((len%2)!=0)
            return false;

        return fk(s);
    }
    bool fk(string s){
       vector<char>sk;
       for(auto it=s.begin();it!=s.end();it++){
           if (sk.size()!=0){
               if (!isMatch(sk.back(),*it)){
                    sk.push_back(*it);
               }else{
                    sk.pop_back();
                }
           }else{
               sk.push_back(*it);
           }
       }
       if(sk.size()>0){
           return false;
       }
       return true;

    }
    bool isMatch(char a,char b){
       switch (a)
       {
       case '(':
           return b==')'?true:false;
           break;
       case '{':
           return b=='}'?true:false;
           break;
       case '[':
           return b==']'?true:false;
       default:
           return false;
           break;
       } 
    }
};

