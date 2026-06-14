class Solution {
public:
    void helper(int i,int target,vector<vector<int>> &result,vector<int> &ds,vector<int> &candidates){

        //base
        if(i == candidates.size()){
            if(target==0){
            result.push_back(ds);
            }
            return;
        }

        //recursive
        //take
        if(candidates[i]<=target){
            ds.push_back(candidates[i]);
            helper(i,target-candidates[i],result,ds,candidates);
            ds.pop_back();
        }

        //Not take
        helper(i+1,target,result,ds,candidates);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        helper(0,target,result,ds,candidates);
        return result;
    }
};