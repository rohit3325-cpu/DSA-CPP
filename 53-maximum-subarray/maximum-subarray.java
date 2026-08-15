class Solution {
    public int maxSubArray(int[] nums) {
        int j=0;
        int curr_sum=0;
        int max_sum=nums[0];

       while(j<nums.length){
        curr_sum +=nums[j];
        max_sum= Math.max(max_sum,curr_sum);
        if (curr_sum < 0) {
                curr_sum = 0;
            }
        j++;
       }
       return max_sum;
    }
}