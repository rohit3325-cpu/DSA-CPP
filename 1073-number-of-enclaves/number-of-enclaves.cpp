class Solution {
public:
void dfs(int i, int j, int m, int n, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] != 1)
            return;

        grid[i][j] = 0;

        dfs(i+1, j, m, n, grid);
        dfs(i-1, j, m, n, grid);
        dfs(i, j+1, m, n, grid);
        dfs(i, j-1, m, n, grid);
    }
    int numEnclaves(vector<vector<int>>& grid) {
         int m = grid.size();
        if(m == 0) return 0;
        int n = grid[0].size();
        int count =0;
        // top & bottom border
        for(int j = 0; j < n; j++){
            if(grid[0][j] == 1) dfs(0, j, m, n, grid);
            if(grid[m-1][j] == 1) dfs(m-1, j, m, n, grid);
        }

        // left & right border
        for(int i = 0; i < m; i++){
            if(grid[i][0] == 1) dfs(i, 0, m, n, grid);
            if(grid[i][n-1] == 1) dfs(i, n-1, m, n, grid);
        }

        // final conversion
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) {
                    count+=1;
                }
               
            }
        }
        return count;
    } 
    
    
};