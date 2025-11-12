class Solution {
public:
bool helper(int idx,vector<int> &nums,int sum,vector<vector<int>> &dp){
    if(sum==0){
        return true;
    }
    if(idx>=nums.size()||sum<0){
         return false;
    }
    
    if (dp[idx][sum]!=-1){
        return dp[idx][sum];
    }
    int pick=helper(idx+1,nums,sum-nums[idx],dp);
    int notpick=helper(idx+1,nums,sum,dp);
    return dp[idx][sum]=pick || notpick;
}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
                 sum +=nums[i];
        }
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
        if(sum%2==0){
            return helper(0,nums,sum/2,dp);
        }
        return false;
    }
};