class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1>n2) return false;
        vector<int> arr1(26,0);
        vector<int> arr2(26,0);
        for(int i=0;i<n1;i++){
            int x = s1[i] - 'a';
            int y = s2[i] - 'a';
            arr1[x]++;
            arr2[y]++;
        }
        int matches = 0;
        for(int i=0;i<26;i++){
            if(arr1[i] == arr2[i]) matches++;
        }
        if(matches == 26) return true;
        int j=n1;
        while(j<n2){
            int x = s2[j] - 'a';
            if(arr2[x] == arr1[x]) matches--;
            arr2[x]++;
            if(arr2[x] == arr1[x]) matches++;

            x=s2[j-n1]-'a';
            if(arr2[x] == arr1[x]) matches--;
            arr2[s2[j-n1]-'a']--;
            if(arr2[x] == arr1[x]) matches++;

            j++;
            if(matches == 26) return true;
        }
    return 0;
    }
};
