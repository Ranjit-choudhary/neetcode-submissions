class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
     int sum =0;
     for(int num:nums) sum+=num;
    if(abs(target)>sum) return 0;
     if((target +sum )% 2 != 0) return 0;
     int req = (target +sum  )/2;
    vector<int> dp(req+1,0);
    dp[0]=1;
     for(int num:nums){
        for(int i =req;i>=num;i--){
            dp[i] += dp[i-num];
        }
     }
     return dp[req];
    }
};
