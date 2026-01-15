class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int,int>> q;
        int perimeter=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j]=1;
                    i=m;
                    break;
                }
            }
        }
        
        //four direction
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;

                if(nx<0 || ny<0 || nx>=m || ny>=n || grid[nx][ny]==0){
                    perimeter++;
                }
                else if(!vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return perimeter;
    }
};