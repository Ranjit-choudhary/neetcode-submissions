class Solution {
public:
    bool isValid(string s) {
        vector<char> st;
        for(int i=0;i<s.size();i++){
            char x = s[i];
            if(x == '(' || x == '{' || x == '[') st.push_back(x);
            else{
                if(st.empty() ) return false;
                if(st.back() == '('){
                    if(x == ')') st.pop_back();
                    else return false;
                }
                else if(st.back() == '{'){
                    if(x == '}') st.pop_back();
                    else return false;
                }
                else if(st.back() == '['){
                    if(x == ']') st.pop_back();
                    else return false;
                }
            
            }
        }
        return st.empty();
    }
};
