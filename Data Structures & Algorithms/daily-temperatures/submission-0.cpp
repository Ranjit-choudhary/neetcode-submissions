class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<pair<int,int>> st;
        int n = t.size();
        vector<int> ans(n,0);
        for(int i=0;i<t.size();i++){
            if(st.empty()) st.push_back({t[i],i});
            while(!st.empty() && st.back().first <t[i] ){
                int idx = st.back().second;
                ans[idx] = i - idx;
                st.pop_back();
            }
            st.push_back({t[i],i});
        }
        return ans;
    }
};
