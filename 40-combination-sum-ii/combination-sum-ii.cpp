class Solution {
public:
    void findCombinations(int i,int target,vector<int>&ds,vector<vector<int>> &ans,vector<int>& arr){
      
            if(target==0){
                ans.push_back(ds);
                return;
            }

        //recursive call
        for(int idx=i;idx<arr.size();idx++){
            if(idx>i && arr[idx]==arr[idx-1]){
                continue;
            }
            if(arr[idx]>target){
                break;
            }
            ds.push_back(arr[idx]);
            findCombinations(idx+1,target-arr[idx],ds,ans,arr);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0,target,ds,ans,candidates);
        return ans;
    }
};