class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int r = nums.size();
        int c = nums[0].size();
        int hi = r*c-1;
        int lo = 0;
        while(lo<=hi){
            int mid = (hi+lo)/2;
            int nr = mid/c;
            int nc = mid%c;
            if(nums[nr][nc] == target) return 1;
            if(nums[nr][nc] < target) lo =mid+1;
            else hi =mid-1;
        }
        return 0;
    }
};
