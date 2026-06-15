class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;

        while(start<=end){
            int mid=start+(end-start)/2;
            
            if(nums[mid] == target) return mid;
            //right part is sorted
            if(nums[mid]>=nums[start]){
                if(target<nums[mid] && target>=nums[start]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }
            //left part is sorted
            else{
                if(target>nums[mid] && target<=nums[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};