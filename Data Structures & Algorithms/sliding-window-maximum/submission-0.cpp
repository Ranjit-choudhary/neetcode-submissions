class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k>nums.size()) return {};
        vector<int> window(k),ans(nums.size() - k+1);
        multiset<int> s;
        int cnt=0;
        for(int i =0;i<k;i++){
            s.insert(nums[i]);
        }
            ans[cnt++] = *s.rbegin();

        for(int i=k;i<nums.size();i++){
            s.erase(s.find(nums[i-k]));
            s.insert(nums[i]);
            ans[cnt++] = *s.rbegin();
        }
        return ans;
    }
};
