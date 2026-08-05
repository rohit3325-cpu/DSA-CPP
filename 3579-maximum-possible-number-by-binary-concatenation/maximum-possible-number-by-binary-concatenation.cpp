class Solution {
public:
    string to_binary(int x){
      
        string s = bitset<32>(x).to_string();
        return s.substr(s.find('1'));
    
    }
  
    int maxGoodNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0;

        do{
            string s="";
            for (int x : nums)
                s += to_binary(x);

            ans = max(ans, stoi(s,nullptr,2));

        }while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
};