class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        
        int lo = 0;
        int hi = mp[key].size()-1;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(mp[key][mid].first == timestamp){
                ans = mid;
                break;
            }
            else if(mp[key][mid].first < timestamp){
                ans = mid;
             lo =mid+1;
            }
            else {hi = mid-1;}
        }
        if(ans == -1) return "";
        return mp[key][ans].second;
    }
};
