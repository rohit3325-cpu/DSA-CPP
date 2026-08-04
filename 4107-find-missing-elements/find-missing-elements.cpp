class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi=INT_MIN;
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        unordered_set<int> st(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=mini;i<maxi;i++){
            if(!st.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};