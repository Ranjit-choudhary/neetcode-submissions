class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m =text1.size();
        int n = text2.size();
        
        vector<vector<int>> mat(m,vector<int>(n,0));
        if(text1[0] == text2[0]) mat[0][0] =1;
        for(int i=1;i<m;i++) {if(text1[i] == text2[0]) mat[i][0] =1; else mat[i][0] = mat[i-1][0];}
        for(int j=1;j<n;j++) {if(text1[0] == text2[j]) mat[0][j] =1; else mat[0][j] = mat[0][j-1];}


        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(text1[i] == text2[j]) {
                    mat[i][j] = 1+mat[i-1][j-1];}
                else mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }

        return mat[m-1][n-1];
        
            }
};
