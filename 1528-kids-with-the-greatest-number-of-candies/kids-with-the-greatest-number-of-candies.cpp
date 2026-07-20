class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxi=0;
        for(int i=0;i<candies.size();i++){
            maxi=max(maxi,candies[i]);
        }
        vector<bool> ans;
        for(int i=0;i<candies.size();i++){
            int sum=0;
            sum=candies[i]+extraCandies;
            ans.push_back(sum>=maxi);
        }
        return ans;
    }
};