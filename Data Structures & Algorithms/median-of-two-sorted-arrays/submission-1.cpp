class Solution {
public:
int n,m;
double solve(vector<int>& a, vector<int>& b){

    int l = -1;
    int h =n-1;

    int half = (n+m)/2;
    while(l<=h){

    int i = (l+h)/2;
    int j = half - i-2;
    int aleft,aright,bleft,bright;
    if(i>=0)aleft = a[i]; else aleft = INT_MIN;
    if((i+1) < n)aright = a[i+1];  else aright   = INT_MAX;
    if(j>=0)bleft = b[j]; else bleft = INT_MIN;
    if(j+1 <m)bright = b[j+1]; else bright = INT_MAX;

    if(aleft<=bright && bleft <=aright){
        if((n+m)%2 != 0) return min(aright,bright);
        else return (double)(max(aleft,bleft)+min(aright,bright))/2;
    }
    else if(aleft>bright){
        h =i-1;
    }
    else l= i+1;
    }
    return 0;
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        m = nums2.size();
        if(n<m) return  solve(nums1,nums2);
        swap(n,m);
        return solve(nums2,nums1);
    }
};
