class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        vector<pair<int,double>> st,pt;
        int n = speed.size();
        for(int i=0;i<n;i++){
            pt.push_back({position[i],(double)(target - position[i])/speed[i]});
        }
        sort(pt.begin(),pt.end());
        for(int i=n-1;i>=0;i--){
            if(st.empty()) st.push_back(pt[i]);
            else{
                if(pt[i].second > st.back().second) st.push_back(pt[i]);
            }
        }
        return st.size();
    }
};
