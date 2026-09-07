class Solution {
public:
    bool check(vector<int>& piles, int h,int mid){
        int t=0;
        for(int i=0;i<piles.size();i++){
            t+=( piles[i]+mid-1)/mid;
        }
        return t<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int hi = piles[0];
        for(int i=1;i<piles.size();i++){
            hi = max(hi,piles[i]);
        }
        int lo = 1;
        int ans=-1;
        while(lo<=hi){
            int mid = (hi+lo)/2;
            if(check(piles,h,mid)){
            hi = mid-1;
            ans = mid;
            } 
            else lo =mid+1;
        }
        return ans;
    }
};
