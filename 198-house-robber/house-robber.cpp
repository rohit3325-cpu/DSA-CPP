class Solution {
public:
int solve(int i,vector<int> &dp,vector<int> &nums){
   if(i==0) return nums[0];
   
   if(i<0) return 0;
   if(dp[i]!=-1) return dp[i];

   int pick = nums[i]+ solve(i-2,dp,nums);
   int notpick = solve(i-1,dp,nums);

   return dp[i]=max(pick,notpick);

    
}
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        
        return solve(nums.size()-1,dp,nums);
    }
};