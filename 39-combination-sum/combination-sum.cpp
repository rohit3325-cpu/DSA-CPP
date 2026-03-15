class Solution {
public:
    void findCombinations(int i,int target,vector<int> &ds,vector<int> &arr,vector<vector<int>>&ans){
        if(i==arr.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return ;
        }

        //recurrsive
        if(arr[i]<=target){
            ds.push_back(arr[i]);
            findCombinations(i,target-arr[i],ds,arr,ans);
            ds.pop_back();
        }
         findCombinations(i+1,target,ds,arr,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0,target,ds,candidates,ans);
        return ans;

    }
};