class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int m=g.size();
        int n=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;int r=0;
        while(r<m && l<n){
            if(g[r] <= s[l]){
                r++;
            }l++;
        }
        return r;
    }
};