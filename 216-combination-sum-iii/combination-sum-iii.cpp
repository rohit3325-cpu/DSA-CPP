class Solution {
public:
    void helper(int i,int k,int n,vector<int> &ds,vector<vector<int>> & ans){
        if(n==0 && k==0){
            ans.push_back(ds);
            return;
        }
         
         //recursive
         for(int j=i;j<=9;++j){
            if(j> n || k<=0) break;
            ds.push_back(j);
            helper(j+1,k-1,n-j,ds,ans);
            ds.pop_back();
         }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(1,k,n,ds,ans);
        return ans;
    }
};