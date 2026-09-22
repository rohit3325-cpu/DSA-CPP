class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(),nums.end());

    
        int res=1;

        int count=1;
        for(int e=1;e<nums.size();e++){
            if(nums[e]==nums[e-1]+1){
                count++;

            }else if(nums[e]==nums[e-1]){
                continue;
            }else{
                count=1;
            }
            res=max(res,count);
        }
        return res;
    }
};