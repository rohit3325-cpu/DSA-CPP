class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n=nums.length;
       HashMap<Integer,Integer> mp=new HashMap<>();

        for(int i = 0; i < n; i++){
            int x = nums[i];
            int y = target - x;

            if(mp.containsKey(y)){
                return new int[]{mp.get(y), i};  // found pair
            }

            mp.put(nums[i],i);
        }

        
        return new int[]{};
    }
}