class Solution {
public:
    bool checkvowel(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int maxvowel=0;
        int left=0,vowel=0;
        for(int right=0;right<s.length();right++){
            if(checkvowel(s[right]))vowel++;

            if((right-left+1)==k){
                maxvowel=max(maxvowel,vowel);
                if(checkvowel(s[left]))vowel--;
                left++;
            }
        }
        return maxvowel;
    }
};