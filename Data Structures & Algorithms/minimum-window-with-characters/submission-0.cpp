class Solution {
public:
    bool check(vector<int> &schar,vector<int> &tchar){
        for(int i=0;i<128;i++){
            if(schar[i] < tchar[i]) return false;
        }   
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> schar(128,0) , tchar(128,0);
        for(int i=0;i<t.size();i++){
            tchar[t[i]]++;
        }
        int minlen = s.size()+2;
        int low = 0;
        int beststart = 0;
        for(int i=0;i<s.size();i++){
            schar[s[i]]++;
            while(check(schar,tchar)){
                if(i-low +1<minlen){
                    minlen = i-low+1;
                    beststart = low;
                }
                schar[s[low]]--;
                low++;
            }
        }
        if(minlen == s.size()+2) return "";
        return s.substr(beststart,minlen);
    }
};
