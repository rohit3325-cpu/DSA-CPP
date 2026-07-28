class Solution {
public:
    string smallestPalindrome(string s) {
        string st;
        string ans;
        if(s.length()==1){
            return s;
        }
        if(s.length()%2==0){
        for(int i=0;i<s.length()/2;i++){
            st +=s[i];
        }
        sort(st.begin(),st.end());
        ans +=st;
        
        reverse(st.begin(),st.end());
        ans +=st;
        }else{
             for(int i=0;i<s.length()/2;i++){
            st +=s[i];
        }
        sort(st.begin(),st.end());
        ans +=st;
        ans +=s[(s.length()/2)];
        reverse(st.begin(),st.end());
        ans +=st;
        }
        return ans;
    }
};