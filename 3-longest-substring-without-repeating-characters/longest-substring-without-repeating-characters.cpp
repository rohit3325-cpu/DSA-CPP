class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxl=0;
        for(int i=0;i<s.size();i++){
            vector<int> hash(256,0);

            for(int j=i;j<s.size();j++){
                if(hash[s[j]]==1){
                    break;
                }
                hash[s[j]]=1;
                int len=j-i+1;
                maxl=max(len,maxl);
            }
            
        }
        return maxl;
        
    }
};