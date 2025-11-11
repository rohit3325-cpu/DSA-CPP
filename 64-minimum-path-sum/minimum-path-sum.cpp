class Solution {
public:
 int helper(int row,int col,int m,int n,vector<vector<int>> &dp,vector<vector<int>> &grid){
    if(row==m-1&&col==n-1){
        return grid[row][col];
    }
    if(row>=m||col>=n){
        return 1e9;
    }
    if(dp[row][col] !=-1){
        return dp[row][col];
    }
   int right = helper(row,col+1,m,n,dp,grid);
   int down = helper(row+1,col,m,n,dp,grid);
    return dp[row][col] =grid[row][col]+ min(right,down);
 }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
       vector<vector<int>> dp(m,vector<int>(n,-1));
       return helper(0,0,m,n,dp,grid); 
    }
};