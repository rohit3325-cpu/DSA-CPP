class Solution {
public:
    int atmost(vector<int>& nums,int goal){
        if(goal<0) return 0;
        int l=0;
        int sum=0;
        int cnt=0;
        for(int r=0;r<nums.size();r++){
            sum += nums[r];
            while(sum>goal){
                sum -= nums[l];
                l++;
            }
            cnt += r-l+1;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atmost(nums,goal) - atmost(nums,goal-1);
    }
};