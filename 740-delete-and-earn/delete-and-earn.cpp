class Solution {
public:
    int solve(int i,vector<int> &points,vector<int> &dp){
        if(i<=0) return 0;

        if(dp[i]!=-1) return dp[i];

        return dp[i]=max((solve(i-1,points,dp)),points[i]+solve(i-2,points,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> points(maxi+1,0);
        for(int num:nums){
            points[num]+=num;
        }

        vector<int> dp(maxi+1,-1);
        return solve(maxi,points,dp);
    }
};