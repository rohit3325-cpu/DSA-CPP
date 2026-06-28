class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count=0;
        unordered_set<int> collect;

        for(int i= nums.size()-1;i>=0;i--){
            count++;
            if(nums[i]<=k){
                collect.insert(nums[i]);
            }
            if(collect.size()==k){
                break;
            }
        }
        return count;
    }
};