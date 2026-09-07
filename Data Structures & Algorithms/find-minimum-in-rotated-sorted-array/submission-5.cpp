class Solution {
public:
    int findMin(vector<int> &nums) {
        int hi = nums.size()-1;
        int lo = 0;
        int ans=-1;
        while(lo<hi){
            int mid = (hi+lo)/2;
            if(nums[mid] > nums[hi]){
            lo = mid+1;
            } 
            else {hi =mid;}
        }
        return nums[lo];

    }
};
