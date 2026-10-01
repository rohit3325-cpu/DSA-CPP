class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=nums[i];
            int sum=0;
            while(j>0){
                sum +=j%10;
                j=j/10;
            }
            if(sum==i){
                return i;
            }
        }
        return -1;
    }
};