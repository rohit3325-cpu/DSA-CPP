class Solution {
public:
    string removeOuterParentheses(string s) {
        string result="";
        int open=0;
        for(char ch:s){
            if(ch == '('){
                open +=1;
                if(open>1) result +=ch;
            }
            else if(ch ==')'){
                open -=1;
                if(open>0) result +=ch;
            }
        }
        return result;
    }
};