class Solution {
public:
    void solve(vector<int> &nums, vector<bool> &used, vector<vector<int>> &result,  vector<int> &curr) {
        if (curr.size()==nums.size()) {
            result.push_back(curr);
        }
        for (int i = 0; i < nums.size(); i++) {  
            if ( used[i]) 
                continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums, used, result, curr); 

            used[i] = false;       
            curr.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(), false);
        vector<vector<int>> result;
        vector<int> curr;
        solve(nums, used, result, curr);
        return result;
    }
};