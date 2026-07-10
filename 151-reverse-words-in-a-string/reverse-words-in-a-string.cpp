class Solution {
public:
    string reverseWords(string s) {
        string word="";
        string result="";

        for(int i=s.length()-1;i>=0;i--){
            if(s[i]!= ' '){
                word +=s[i];
            }
            else if(!word.empty()){
                reverse(word.begin(),word.end());

                 if (!result.empty())
                    result += " ";
                result +=word;
                word="";
            }
        }
        if(!word.empty()){
            reverse(word.begin(),word.end());

             if (!result.empty())
                    result += " ";

            result += word;
        }
        return result;
    }
};