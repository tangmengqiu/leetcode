/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0) return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        cout<<"m: "<<m<<" n: "<<n<<endl;
        int hight[n+1]={0},left[n+1]={0},right[n+1];
        fill(right,right+n+1,n);
        int ans=0;
        for(int i=0;i<m;i++){
            int curLeft=0,curRight=n;
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0'){
                    left[j]=0;
                    hight[j]=0;
                    curLeft=j+1;
                }else{
                    left[j]=max(left[j],curLeft);
                    hight[j]++;
                }
            }
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='0'){
                    curRight=j;
                    right[j]=n;
                }else{
                    right[j]=min(right[j],curRight);
                }
            }
            for(int j=0;j<n;j++){
                cout<<"right: "<<right[j]<<" left: "<<left[j]<<endl;
                ans=max(ans,hight[j]*(right[j]-left[j]));
            }
        }
        return ans;
    }
};
// @lc code=end

