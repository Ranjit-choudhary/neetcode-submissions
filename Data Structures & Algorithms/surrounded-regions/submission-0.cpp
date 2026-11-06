class Solution {
public:
         int row,col;
    void solve(vector<vector<char>>& b) {
        vector<vector<char>> board = b;
           row = board.size();
         col = board[0].size();
         queue<pair<int,int>> q;
        for(int i=0;i<row;i++){
            if(board[i][0] == 'O')  {
                q.push({i,0});}
            
            if(board[i][col-1] == 'O' ) q.push({i,col-1});
        }
        for(int j=0;j<col;j++){
            if(board[0][j] == 'O') q.push({0,j});
            if(board[row-1][j] == 'O') q.push({row-1,j});
        }

        int dx[]={-1,1,0,0};
        int dy[]={0,0,-1,1};
        while(!q.empty()){
            
                auto temp = q.front();
                q.pop();

                int x =temp.first;
                int y = temp.second;
                
                board[x][y] = 'X';
                for(int d=0;d<4;d++){
                    int cx = x+dx[d];
                    int cy = y +dy[d];
                    if(cx>=0 && cy>=0 && cx<row && cy <col && board[cx][cy]== 'O'){

                        q.push({cx,cy});
                        board[cx][cy] = 'X';
                    }
                            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(b[i][j] == 'O' && board[i][j] == 'O')
                b[i][j] = 'X';
            }
        }
    }
};
