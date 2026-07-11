class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        int maxp=nums[0];
        int minp=nums[0];
        int ans=nums[0];

        for(int i=1;i<n;i++){
            int curr=nums[i];

            int tempmax=max({curr,curr*maxp,curr*minp});
            int tempmin=min({curr,curr*maxp,curr*minp});

            maxp=tempmax;
            minp=tempmin;

            ans=max(ans,maxp);
        }
        return ans;
    }
};