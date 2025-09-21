class Solution {
public:

    int nicearray(vector<int>& nums,int k){
        if(k<0) return 0;
      int l=0;
      int sum=0;
      int cnt=0;
      for(int r=0;r<nums.size();r++){
        sum += (nums[r]%2);
        while(sum>k){
            sum -= (nums[l]%2);
            l++;
        }
        cnt = cnt+(r-l+1);
      }
      return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return nicearray(nums,k)-nicearray(nums,k-1);
    }
};