class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int it=1;
        it+=b.size()/a.size();
        if(b.size()%a.size() != 0) it++;

        string repeated=a;

        for(int i=1;i<=it;i++,repeated +=a){
            if(repeated.find(b) != string::npos){
                return i;
            }
        }
        return -1;
    }
};