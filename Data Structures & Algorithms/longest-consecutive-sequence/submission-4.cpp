class Solution {
public:
       unordered_map<int,int> mp;
int solve(int x){
    if(mp.find(x) ==  mp.end()) return 0;
    return mp[x]=1 + solve(x-1);
}
    int longestConsecutive(vector<int>& nums) {
       int n = nums.size();
       for(int i=0;i<n;i++) mp[nums[i]] = -1;
       int mx=0;
       for(int i=0;i<n;i++) {
        if(mp[nums[i]] == -1){

                    mp[nums[i]] = 1 + solve(nums[i]-1);
                    mx=max(mx,mp[nums[i]]);
        }
       }
       return mx;

    }
};
