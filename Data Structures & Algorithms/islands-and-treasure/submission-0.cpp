class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0 && !visited[i][j]){
                q.push({i,j});
                visited[i][j]=1;

            }}}
                int dist =1;
                while(!q.empty()){
                int level = q.size();
                while(level--){

                    auto [x,y] = q.front();
                    q.pop();
                visited[x][y]=1;

                for(int d=0;d<4;d++){
                    int nx = x+dx[d];
                    int ny = y+dy[d];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && visited[nx][ny] == 0 && grid[nx][ny] == INT_MAX){
                        q.push({nx,ny});
                        visited[nx][ny]=1;
                        grid[nx][ny] = dist;
                    }
                }
                }
                dist++;
                
                }
            
    }
};
