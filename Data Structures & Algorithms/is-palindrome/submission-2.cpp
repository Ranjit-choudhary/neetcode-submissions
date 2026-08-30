class Solution {
public:
bool isalpha(char c){
    if((c>='A' && c<='Z') || ( c>='a' && c <='z')||c>='0'&&c<='9') return 1;
    return 0;
}
    bool isPalindrome(string s) {
        int n=s.size();
        int l =0;
        int r = n-1;
        while(l<r){
            while(!isalpha(s[l]) && l<r) l++;
            while(!isalpha(s[r]) && l<r) r--;
            if(tolower(s[l]) != tolower(s[r]) ) return 0;
            l++;
            r--;
        }
        return 1;
    }
};
