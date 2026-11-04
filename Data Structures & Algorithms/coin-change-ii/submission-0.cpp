class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> mat(coins.size(),vector<int>(amount+1,0));
        int m =coins.size();
        int n =amount+1;
        for(int i=0;i<coins.size();i++)mat[i][0] = 1;
        for(int i=1;i<n;i++) if(i%coins[0] == 0) mat[0][i] =1;
        for(int i=1;i<m;i++){
                int x =coins[i];
            for(int j=1;j<n;j++){
                int temp =0;
                while(temp*x<=j){
                    mat[i][j] +=  mat[i-1][j-temp*x];
                    temp++;
                }
            }
        }
        return mat[m-1][n-1];
    }
};
