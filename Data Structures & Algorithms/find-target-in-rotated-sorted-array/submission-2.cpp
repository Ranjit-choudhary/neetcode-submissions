class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int hi = nums.size()-1;
        int lo = 0;
        int pvt = -1;
        while(lo<hi){
            int mid = (hi+lo)/2;
            if(nums[mid] > nums[hi]){
            lo = mid+1;
            } 
            else {hi =mid;}
        }
        pvt =lo;

        if(target<nums[0]){
            lo = pvt;
            hi  = n-1;
        }
        else{
            lo = 0;
            if(pvt != 0)hi =pvt-1;
            else hi =n-1;
        }
while(lo<=hi){
            int mid = (hi+lo)/2;
            if(nums[mid] == target)return mid;
            if(nums[mid] > target){
                hi =mid-1;
            }
            else {lo =mid+1;}
        }
            return -1;
    }
};
