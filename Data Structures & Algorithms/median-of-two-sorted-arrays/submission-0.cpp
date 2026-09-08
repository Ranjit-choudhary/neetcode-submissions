class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> arr(m+n);
        int idx=0;
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]) arr[idx++] = nums1[i++];
            else arr[idx++] = nums2[j++];
        }
        while(i<n) arr[idx++] = nums1[i++];
        while(j<m) arr[idx++] = nums2[j++];

        double ans;
        n =arr.size();
        if(n==0) return arr[0];
        if(n %2 == 0) ans = (double)(arr[n/2] + arr[n/2-1])/2;
        else ans = arr[n/2];
        return ans;
    }
};
