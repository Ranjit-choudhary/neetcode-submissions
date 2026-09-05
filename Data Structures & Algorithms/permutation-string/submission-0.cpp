class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2) return false;
        vector<int> arr1(27,0);
        vector<int> arr2(27,0);
        for(int i=0;i<n1;i++){
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            arr1[x]++;
            arr2[y]++;
        }
        if(arr1 == arr2) return true;
        int j=n1;
        while(j<n2){
            int x = s2[j] - 'a';
            arr2[x]++;
            arr2[s2[j-n1]-'a']--;
            j++;
            if(arr1 == arr2) return true;
        }
    return 0;
    }
};
