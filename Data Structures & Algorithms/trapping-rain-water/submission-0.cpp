class Solution {
public:
    int trap(vector<int>& ht) {
        int n= ht.size();
     //min ht seen till now
     vector<int> leftMax(n),rightMax(n);
     int mn =0;
     leftMax[0]=ht[0];
    for(int i=1;i<n;i++){
        leftMax[i] = max(leftMax[i-1],ht[i]);
     }
     rightMax[n-1]=ht[n-1];
    for(int i=n-2;i>=0;i--){
        rightMax[i] = max(rightMax[i+1],ht[i]);
     }
     int res =0;
     for(int i=0;i<n;i++){
        res+=min(leftMax[i],rightMax[i]) - ht[i];
     }    
     return res;
    }
};
