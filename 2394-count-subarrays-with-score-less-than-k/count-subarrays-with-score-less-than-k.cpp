class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum=0,cnt=0,l=0;
        for(long long r=0;r<nums.size();r++){
            sum +=nums[r];
            while(sum*(r-l+1) >=k){
                sum -= nums[l];
                l++;
            }
            cnt += r-l+1;
        }
        return cnt;
    }
};