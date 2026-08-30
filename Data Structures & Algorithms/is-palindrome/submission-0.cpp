class Solution {
public:
bool isalpha(char c){
    if((c>='A' && c<='Z') || ( c>='a' && c <='z')||c>='0'&&c<='9') return 1;
    return 0;
}
char to_lower(char c){
     if(c>='A' && c<='Z') return (char)('a'  + c - 'A');
     return c;
}
    bool isPalindrome(string s) {
        int n=s.size();
        int l =0;
        int r = n-1;
        while(l<r){
            while(!isalpha(s[l]) && l<r) l++;
            while(!isalpha(s[r]) && l<r) r--;
            if(to_lower(s[l]) != to_lower(s[r]) ) return 0;
            l++;
            r--;
        }
        return 1;
    }
};
