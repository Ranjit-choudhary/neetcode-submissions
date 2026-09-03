class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = i;
        }
        for(int l=0;l<n;l++){
            if(nums[l] >0) break;
                if(l>0 && nums[l] == nums[l-1])continue; 
            for(int i=l+1;i<n;i++){
                 if(i>l+1 && nums[i] == nums[i-1])continue; 
                int target = -nums[l]-nums[i];
                if(mp.find(target) != mp.end()){
                        int idx = mp[target];
                        if( i < idx && l<idx)
                        ans.push_back({nums[l],nums[i],nums[idx]});
                }
            }
        }
    return ans;
    }
};
