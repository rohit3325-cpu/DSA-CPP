class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }else{
                    mat[i][j]=-1;
                }
            }
        }
        //four direction
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};

        while(!q.empty()){
            int k=q.size();
            while(k--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx<0 || ny<0 || nx>=m || ny>=n || mat[nx][ny]!=-1){
                        continue;
                    }
                    mat[nx][ny]=mat[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }
        return mat;
    }
};