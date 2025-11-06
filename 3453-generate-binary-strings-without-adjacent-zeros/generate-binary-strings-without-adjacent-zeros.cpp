class Solution {
public:
  void  helper(int i,int n,string& curr,vector<string> &ans){
      if(i == n){
          ans.push_back(curr);
          return;
      }
      if(curr.empty() || curr.back() != '0'){
              curr += "0";
      helper(i+1,n,curr,ans);
      curr.pop_back();
      }
      
      
      curr += "1";
      helper(i+1,n,curr,ans);
      curr.pop_back();
      
  }
    vector<string> validStrings(int n) {
          vector<string> ans;
        string curr="";
        helper(0,n,curr,ans);
        
        return ans;
    }
};