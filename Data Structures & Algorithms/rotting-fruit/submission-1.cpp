class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time =0;
        int row =grid.size();
        int col =grid[0].size();
        queue<pair<int,int>> q;
        int total =0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                if(grid[i][j] == 1) total++;
            }
        }
        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        int count =0;
        while(!q.empty()){
            int sz=q.size();
            int c=0;
            while(sz--){
                auto temp = q.front();
                q.pop();
                int x =temp.first;
                int y = temp.second;
                for(int d=0;d<4;d++){
                    int cx = x+dx[d];
                    int cy = y +dy[d];
                    if(cx>=0 && cy>=0 && cx<row && cy <col){
                        if(grid[cx][cy] == 1){
                            grid[cx][cy] =2;
                            q.push({cx,cy});
                            c++;
                            count++;
                        }
                    }
                }
            }
            if(c>0)time++;
        }
        cout<<total<<endl<<count;
        if(total != count) return -1;

        return time;
    }
};
