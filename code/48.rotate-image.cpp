/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =matrix.size();
        //沿对角线置换
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int tmp =matrix [i][j];
                matrix [i][j]= matrix[j][i];
                matrix[j][i]=tmp;
            }
        }
        //沿中线 对换
        for(int i=0;i< n;i++){
            for(int j= 0;j<n/2;j++){
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
    }
};
// @lc code=end

