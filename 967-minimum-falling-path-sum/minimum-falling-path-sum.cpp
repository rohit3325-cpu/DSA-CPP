class Solution {
public:
int helper(int row,int col,int m,int n,vector<vector<int>> &matrix,vector<vector<int>> &dp){
     if (col < 0 || col >= n) return 1e9; 
    if (row == m - 1) return matrix[row][col]; 
    if(dp[row][col]!=-101){
        return dp[row][col];
    }
    int down=helper(row+1,col,m,n,matrix,dp);
    int left=helper(row+1,col-1,m,n,matrix,dp);
    int right=helper(row+1,col+1,m,n,matrix,dp);
    return dp[row][col]=matrix[row][col]+min(down,min(left,right));
}
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-101));
        int mini=INT_MAX;
        for(int col=0;col<n;col++){
            mini= min(mini, helper(0,col,m,n,matrix,dp));
        }
       return mini;

    }
};