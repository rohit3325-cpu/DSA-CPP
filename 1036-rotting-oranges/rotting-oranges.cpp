class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m=grid.size();
        int n=grid[0].size();
        int tot=0;
        int cnt=0;
        int time=0;
        queue<pair<int,int>> q;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }else{
                if(grid[i][j]==1){
                    cnt +=1;
                }
            }
        }
       }

       //for all direction
       int dx[4]={1,-1,0,0};
       int dy[4]={0,0,1,-1};

       while(!q.empty()){
        int k=q.size();
        bool rotten = false;
        while(k--){
          auto[x,y] = q.front();
          q.pop();

          for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];;
          if(nx >= 0 && ny >= 0 && nx < m && ny < n && grid[nx][ny] == 1){
            grid[nx][ny] =2;
            q.push({nx,ny});
            cnt--;
            rotten = true;
          }
            
          }
          }
          if(rotten) time++;
       }
       return cnt ==0 ? time:-1;
    }      
};