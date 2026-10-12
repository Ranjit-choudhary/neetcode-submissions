class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k>nums.size()) return {};
        deque<int> d;
        vector<int> ans(nums.size()-k+1);
        int cnt= 0;
        for(int i=0;i<nums.size();i++){
            while(!d.empty() && d.front()<=i-k) d.pop_front();
            while(!d.empty() && nums[d.back()] <nums[i]) d.pop_back();
            d.push_back(i);
            if(i >= k-1) ans[cnt++] = nums[d.front()];
        }
        return ans;
    }
};
