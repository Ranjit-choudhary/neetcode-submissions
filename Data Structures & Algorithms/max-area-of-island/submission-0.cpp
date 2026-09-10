class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        vector<pair<int,int>> st;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 && !visited[i][j]){
        int count =0;

                st.push_back({i,j});
                while(!st.empty()){
                count++;
                    auto [x,y] = st.back();
                    st.pop_back();
                visited[x][y]=1;

                for(int d=0;d<4;d++){
                    int nx = x+dx[d];
                    int ny = y+dy[d];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && visited[nx][ny] == 0 && grid[nx][ny] == 1){
                        st.push_back({nx,ny});
                        visited[nx][ny]=1;
                    }
                }
                }
                ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};
