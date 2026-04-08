class Solution {
public:
  int atmost(vector<int>& nums,int k){
    if(k<0) return 0;
     int l=0;int maxl=0;
     int cnt=0;

     for(int r=0;r<nums.size();r++){
        if(nums[r]%2 !=0) cnt +=1;

        while(cnt>k){
             if(nums[l]%2 !=0)cnt -= 1;
            l++;
        }

        maxl += r-l+1;
     }
     return maxl;
  }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};