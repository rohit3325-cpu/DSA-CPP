class Solution {
public:
     int solve(int i,int j,int m,int n,vector<vector<int>> &dp,vector<vector<int>>& dungeon){
        if(i==m-1 && j==n-1){
            return max(1, 1 - dungeon[i][j]);
        }
        if(i>=m || j>=n){
            return 1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        return dp[i][j]=max(1,min(solve(i+1,j,m,n,dp,dungeon),solve(i,j+1,m,n,dp,dungeon))-dungeon[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size();
        int n=dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp,dungeon);
       
    }
};