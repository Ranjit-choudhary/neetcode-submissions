class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n = tokens.size();
        for(int i=0;i<n;i++){
            string s = tokens[i];
            if(s == "+" || s == "-" || s== "*" || s=="/"){
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                if(s == "+") st.push(a+b);
                else if(s == "-") st.push(a-b);
                else if(s == "*") st.push(a*b);
                else if(s == "/") st.push(a/b);
            }
            else{
                st.push(stoi(s));
            }
        }
        return st.top();
    }
};
