class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n =nums.size();
        int left =0 ,zerocnt =0 ,maxlen =0;
        for(int right =0 ;right <n ;right++){
            if(nums[right]==0) zerocnt++;
            while(zerocnt > 1){
                if(nums[left]==0) zerocnt--;
                left++;
            }
            maxlen =max(maxlen ,right - left +1);
        }
        return maxlen -1 ;
    }
};