class Solution {
public:
    void helper( vector<vector<int>> &ans,vector<int> &ds,vector<bool> &used,vector<int>& nums){
        
        //base
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }

        //recursive
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            used[i]=true;

            ds.push_back(nums[i]);
            helper(ans,ds,used,nums);

            ds.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> used(nums.size(),false);

        helper(ans,ds,used,nums);
        return ans;
    }
};