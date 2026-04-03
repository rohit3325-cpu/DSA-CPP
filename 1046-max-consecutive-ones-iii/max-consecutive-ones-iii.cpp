class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int zero =0;
        int maxl = 0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0){
                zero++;
            }
            while(zero>k){
                if(nums[l]==0) zero--;
                l++;
            }
            maxl=max((r-l+1),maxl);
        }
        return maxl;
    }
};