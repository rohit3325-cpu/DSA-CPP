class Solution {
public:
    string minWindow(string s, string t) {
        int m= s.length();
        int n= t.length();
        if(n>m) return "";
        vector<int> hash(256,0);
        for(char ch:t){
            hash[ch]++;
        }

        int l=0;
        int r=0;
        int minlen=INT_MAX;
        int count=n;
        int start=0;

        for(int r=0;r<m;r++){
            if(hash[s[r]] >0) count--;
            hash[s[r]]--;

            while(count==0){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    start=l;
                }

                hash[s[l]]++;
                if(hash[s[l]]>0) count++;
                l++;
            }
        }
        return minlen == INT_MAX?"":s.substr(start,minlen);
    }
};