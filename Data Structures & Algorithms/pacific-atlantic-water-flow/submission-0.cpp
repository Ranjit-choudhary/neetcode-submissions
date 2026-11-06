class Solution {
public:
int row,col;
    bool propogate(int i,int j, vector<vector<bool>> &rp,vector<vector<bool>> &ra,vector<vector<bool>> &visited,vector<vector<int>>& heights){
        if(visited[i][j]){
            return rp[i][j] && ra[i][j];
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        visited[i][j] =1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            
            int sz=q.size();
            while(sz--){
                auto temp = q.front();
                q.pop();
                int x =temp.first;
                int y = temp.second;
                for(int d=0;d<4;d++){
                    int cx = x+dx[d];
                    int cy = y +dy[d];
                    if(cx>=0 && cy>=0 && cx<row && cy <col && !visited[cx][cy] && heights[cx][cy] <= heights[x][y]){

                        q.push({cx,cy});
                        visited[cx][cy] =1;
                    }
                    if(cx<0 || cy<0) rp[i][j] = 1;
                    if(cx>=row || cy>=col) ra[i][j] =1;
                    if(rp[i][j] && ra[i][j]) return 1;
                }
            }
            
        }
        return rp[i][j] && ra[i][j];
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
         row = heights.size();
         col = heights[0].size();

        vector<vector<bool>> rp(row,vector<bool>(col,0));
        vector<vector<bool>> ra(row,vector<bool>(col,0));
        vector<vector<int>> ans;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
        vector<vector<bool>> visited(row,vector<bool>(col,0));
                if(propogate(i,j,rp,ra,visited,heights)) ans.push_back({i,j});
            }
        }

        return ans;
    }
};
