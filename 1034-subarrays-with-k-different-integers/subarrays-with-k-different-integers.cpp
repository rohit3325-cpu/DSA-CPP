class Solution {
public:
int atmost(vector<int>&nums,int k){
      int l=0;
      int ans=0;
      map<int,int> mpp;
        for(int r=0;r<nums.size();r++){
            mpp[nums[r]]++;
            if(mpp.size()>k){
                while(mpp.size()>k){
                    mpp[nums[l]]--;
                    if(mpp[nums[l]]==0){
                        mpp.erase(nums[l]);
                    }
                    l++;
                }
            }
            ans +=r-l+1;

        }
        return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
      return atmost(nums,k)-atmost(nums,k-1);
    }
};