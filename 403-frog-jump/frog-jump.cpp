class Solution {
public:
    bool solve(int i,int k,vector<int> &stones,vector<vector<int>> &dp,unordered_map<int,int> &mp){
        if(i==stones.size()-1){
            return true;
        }
        if(dp[i][k]!=-1) return dp[i][k];
          bool ne=false;
          bool n0=false;
          bool np=false;
          if(k>1 && mp.find(stones[i]+k-1)!=mp.end()){
            ne=solve(mp[stones[i]+k-1],k-1,stones,dp,mp);
          }
           if(mp.find(stones[i]+k)!=mp.end()){
            n0=solve(mp[stones[i]+k],k,stones,dp,mp);
          }
           if(mp.find(stones[i]+k+1)!=mp.end()){
            np=solve(mp[stones[i]+k+1],k+1,stones,dp,mp);
          }
          return dp[i][k]=ne || n0 || np;

    }
    bool canCross(vector<int>& stones) {
        if(stones[1]-stones[0]>1){
            return false;
        }
        vector<vector<int>> dp(stones.size(),vector<int>(stones.size()+1,-1));
        unordered_map<int,int> mp;
        for(int i=0;i<stones.size();i++){
            mp[stones[i]]=i;
        }
        return solve(1,1,stones,dp,mp);
    }
};