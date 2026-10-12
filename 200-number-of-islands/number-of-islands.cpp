class Solution {
public:
    
    void bfs(int m, int n,int s,int e, vector<vector<char>>& grid ){
        queue<pair<int,int>> q;

        q.push({s,e});
        grid[s][e]='0';

        while(!q.empty()){
            int x=q.front().first;
            int  y=q.front().second;
            q.pop();

            int dx[4] ={1,-1,0,0};
            int dy[4]={0,0,-1,1};

            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];

                if(nx >=0 && ny >=0 && nx<m && ny<n && grid[nx][ny]=='1'){
                    q.push({nx,ny});
                    grid[nx][ny]='0';
                }
            }
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    islands+=1;
                    bfs(m,n,i,j,grid);
                }
            }
        }
        return islands;
    }
};