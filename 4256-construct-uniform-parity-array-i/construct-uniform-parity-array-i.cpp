class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        if(nums1.size()==1) return true;
        int odd=0, even=0;
        for(int x:nums1){
            if(x%2) odd++;
            else even++;
        }

        if(odd >= 2 || odd==1) return true;
        if(odd>=1 && even>=1) return true;
        if(even>=2) return true;

        return false;
    }
};