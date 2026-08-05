class Solution {
public:
    string to_binary(int x){
        if(x==0) return "0";
        string s;
        while(x>0){
            s += char('0'+(x%2));
            x=x/2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int binarytodecimal(string s){
        int ans=0;
        for(char ch:s){
            ans = ans *2 +(ch-'0');
        }
        return ans;
    }
    int maxGoodNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;

        do{
            string s="";
            for (int x : nums)
                s += to_binary(x);

            ans = max(ans, binarytodecimal(s));

        }while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
};