class Solution {
public:
    void bfs(int i, int j, int m, int n, vector<vector<char>> &board) {
        queue<pair<int,int>> q;
        q.push({i,j});
        board[i][j] = 'S';

        int dx[4] = {0,0,-1,1};
        int dy[4] = {-1,1,0,0};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int d=0; d<4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];

                if(nx>=0 && ny>=0 && nx<m && ny<n && board[nx][ny]=='O'){
                    board[nx][ny] = 'S';
                    q.push({nx,ny});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(m==0) return;
        int n = board[0].size();

        // border rows
        for(int j=0; j<n; j++){
            if(board[0][j]=='O') bfs(0,j,m,n,board);
            if(board[m-1][j]=='O') bfs(m-1,j,m,n,board);
        }

        // border columns
        for(int i=0; i<m; i++){
            if(board[i][0]=='O') bfs(i,0,m,n,board);
            if(board[i][n-1]=='O') bfs(i,n-1,m,n,board);
        }

        // final conversion
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='S') board[i][j]='O';
            }
        }
    }
};
