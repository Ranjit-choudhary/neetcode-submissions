class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string &s1,string &s2,string &s3,int i,int j,int k){
        if(dp[i][j] != -1) return dp[i][j];
        if(s1.size()-i + s2.size()-j != s3.size()-k){
            dp[i][j]=0;
        return false;

        } 
        if(k==s3.size()) { dp[i][j]=1;return true;}
        if(s1[i] == s3[k] && s2[j]==s3[k]){
            return (dp[i][j] = (solve(s1,s2,s3,i+1,j,k+1) || solve(s1,s2,s3,i,j+1,k+1)));
        } 
        else if(s1[i] == s3[k]) return (dp[i][j] = solve(s1,s2,s3,i+1,j,k+1));
        else if(s2[j] == s3[k]) return (dp[i][j] = solve(s1,s2,s3,i,j+1,k+1));
        dp[i][j] = 0;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int rows =s1.size();
        int cols =s2.size();
       dp.resize(rows+1);
        for (auto& row : dp) {
    row.resize(cols+1, -1);
        }
        return solve(s1,s2,s3,0,0,0);
    }
};
