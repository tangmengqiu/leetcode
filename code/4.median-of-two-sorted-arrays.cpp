/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (26.99%)
 * Likes:    4795
 * Dislikes: 687
 * Total Accepted:    484.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * You may assume nums1 and nums2 cannot be both empty.
 * 
 * Example 1:
 * 
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * Example 2:
 * 
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        int L1,R1,L2,R2,c1,c2,low=0,high=2*m;
        while(low<=high){
            c1=(high+low)/2;
            c2=n+m-c1;
            L1=(c1==0)?INT_MIN:nums1[(c1-1)/2];
            R1=(c1==2*m)?INT_MAX:nums1[c1/2];
            L2=(c2==0)?INT_MIN:nums2[(c2-1)/2];
            R2=(c2==2*n)?INT_MAX:nums2[c2/2];
            if(L1>R2){
                high=c1-1;
            }else if(L2>R1){
                low=c1+1;
            }else{
                break;
            }
        }
        return (max(L1,L2)+min(R1,R2))/2.0;
    }
};

