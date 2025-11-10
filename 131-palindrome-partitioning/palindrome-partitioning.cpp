class Solution {
public:
  bool ispalindrome(int l,int r,string s){
    while(l<=r){
        if(s[l++]!=s[r--]) return false;
       
    }
     return true;
    
}
    void helper(int idx,vector<string> &curr, string &s,vector<vector<string>> &ans){
         if(idx == s.length()){
            ans.push_back(curr);
            return;
         }

         for(int i=idx;i<s.length();i++){
            if(ispalindrome(idx,i,s)){
                curr.push_back(s.substr(idx,i-idx+1));
                helper(i+1,curr,s,ans);
                curr.pop_back();
            }
         }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(0,curr,s,ans);
        return ans;
    }
};