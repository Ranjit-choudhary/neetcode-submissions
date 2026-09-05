class Solution {
public:
    int characterReplacement(string s, int k) {
        // window length - freq of most repeating chat <=k
        int i=0;int j=0;
        int n = s.size();
        vector<int> arr(27,0);
        int mx = 0;
            int mostfreq =0;
        while(j<n){
            int x = s[j] -'A';
            arr[x]++;
            int window_length = j-i+1;
            //most freq char
                mostfreq = max(mostfreq,arr[x]);
            while(j-i+1 - mostfreq >k) {
                arr[s[i]-'A']--;
                i++;
            }
            mx= max(mx,j-i+1);
            j++;

        }
        return mx;
    }
};
