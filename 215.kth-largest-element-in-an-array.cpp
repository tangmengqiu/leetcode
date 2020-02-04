/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*
        better performance:
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
        */
        int left = 0, right =nums.size() -1 ,kth;
        while(1){
            int idx = pivot(nums,left,right);
            if(idx==k-1){
                kth=nums[idx];
                break;
            }
            if(idx<k-1){
                left=idx+1;
            }else{
                right =idx-1;
            }
        }
        return kth;
    }
private:
    int pivot(vector<int>& nums,int l,int r){
        int p = nums[l];
        while(l<r){
            while(l<r&&nums[r]<p)r--;
            nums[l]=nums[r];
            while(l<r&&nums[l]>=p)l++;
            nums[r]=nums[l];
        }
        nums[l]=p;
        return l;
    }

};

// @lc code=end

