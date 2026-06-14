class Solution {
public:
    void helper(int i,vector<int> &ds, set<vector<int>> &result,vector<int> &nums){

        //base 
        if(i== nums.size()){
            result.insert(ds);
            return;
        }

        //recursive
        ds.push_back(nums[i]);
        helper(i+1,ds,result,nums);
        ds.pop_back();

        helper(i+1,ds,result,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> result;
        vector<int> ds;
        helper(0,ds,result,nums);
        vector<vector<int>> ans(result.begin(),result.end());
        return ans;
    }
};