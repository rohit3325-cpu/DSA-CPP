class Solution {
public:
int helper(int row,int col,int m,int n,vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid){
    if(row == m-1 && col==n-1){
        return 1;
    }
   
    if(row>=m || col >=n || obstacleGrid[row][col]==1){
        return 0;
    }
    if(dp[row][col] != -1){
        return dp[row][col];
    }
    return dp[row][col]=helper(row+1,col,m,n,dp,obstacleGrid)+helper(row,col+1,m,n,dp,obstacleGrid);
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
         if (obstacleGrid[0][0] == 1) return 0;
         if(obstacleGrid[m-1][n-1] == 1) return 0;
       return helper(0,0,m,n,dp,obstacleGrid);
    }
};