class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice =prices[0];
        int ans=0;
        for(int i=1;i<n;i++){

            int sell = -minPrice + prices[i];
            minPrice = min(minPrice,prices[i]);
            ans=max(ans,sell);
        }
        return ans;

    }
};
