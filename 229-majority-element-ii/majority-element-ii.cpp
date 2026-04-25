class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0;int e1=0;int c2=0;int e2=1;

        for(int i=0;i<nums.size();i++){
            if(c1==0 && e2!=nums[i]){
                e1=nums[i];
                c1=1;
            }
            else if(c2==0 && e1!=nums[i]){
                e2=nums[i];
                c2=1;
            }
            else if(e1==nums[i]) c1++;
            else if(e2==nums[i]) c2++;
            else{
                c1--;
                c2--;
            }

        }

        //verify
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==e1){
                cnt1++;
            }else if(nums[i]==e2){
                cnt2++;
            }
        }

        vector<int> ans;
        int mini=nums.size()/3 +1;
        if(cnt1>=mini) ans.push_back(e1);
        if(cnt2>=mini  && e1!=e2) ans.push_back(e2);

        return ans;
    }
};