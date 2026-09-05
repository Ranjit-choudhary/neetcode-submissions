class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n= s.size();
        int i=0;
        int j=0;
        int mx =0;
        while(j<n){
        char x = s[j];
        if(mp.find(x) == mp.end()){
            mp[x] = j;
            
        }
        else{
            i = max(i,mp[x]+1);
            mp[x] = j;
        }
            mx=max(mx,j-i+1); 
            j++;
        }
        return mx;
    }
};
