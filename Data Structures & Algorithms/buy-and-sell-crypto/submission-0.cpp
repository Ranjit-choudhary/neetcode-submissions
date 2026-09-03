class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> sm(n,0); //suffix max
        sm[n-1] = prices[n-1];
        for(int i =n-2;i>=0;i--){
            sm[i] = max(prices[i],sm[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int sell = -prices[i] + sm[i];
            if(sell>0) ans=max(ans,sell);
        }
        return ans;

    }
};
