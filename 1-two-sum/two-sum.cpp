class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         unordered_map<int,int> mp;

        for(int i = 0; i < nums.size(); i++){
            int x = nums[i];
            int y = target - x;

            if(mp.count(y)){
                return {mp[y], i};  // found pair
            }

            mp[x] = i;
        }

        return {};
    }
};