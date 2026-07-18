class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mn=nums[0];
        int mx=nums[nums.size()-1];

        return gcd(mn,mx);
    }
};