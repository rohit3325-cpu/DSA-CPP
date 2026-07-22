class Solution {
public:
    string decodeString(string s) {
        stack<int>nums;
        stack<string>chars;

        int num=0;
        string curr="";

        for(char ch:s){

            if(isdigit(ch)){
                num=(num*10)+(ch-'0');
            }

            else if(ch == '['){
                nums.push(num);
                chars.push(curr);

                num=0;
                curr="";
            }
            else if(ch==']'){
                int repeat=nums.top();
                nums.pop();

                string prev=chars.top();
                chars.pop();
                
                while(repeat--){
                    prev +=curr;
                }
                curr=prev;

            }
            else{
                curr +=ch;
            }
        }
        return curr;
    }
};