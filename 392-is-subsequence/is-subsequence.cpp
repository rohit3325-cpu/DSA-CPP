class Solution {
public:
bool helper(string &s,string &t,int idx1,int idx2){
    if(idx1 == s.size()){
        return true;
    }
    if( idx2>t.size()){
        return false;
    }

    if(s[idx1]==t[idx2]){
         return helper(s,t,idx1+1,idx2+1);
    }else{
        return helper(s,t,idx1,idx2+1);
    }
    
}
    bool isSubsequence(string s, string t) {
       return helper(s,t,0,0);
    }
};