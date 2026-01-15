class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        
        queue<pair<int,int>> q;
         
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                count+=1;
                q.push({i,j});
                grid[i][j]='0';
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    //four direction
                    for(int i=0;i<4;i++){
                        int nx=dx[i]+x;
                        int ny=dy[i]+y;
                        if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]=='1'){
                            q.push({nx,ny});
                            grid[nx][ny]='0';
                        }
                    }
                }
            }
            }
         }
         
        
        return count;
    }
};