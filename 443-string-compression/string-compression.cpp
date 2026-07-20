class Solution {
public:
    int compress(vector<char>& chars) {
        int idx=0;
        int count=0;
        for(int i=0;i<chars.size();i++){
            count++;
            if(i+1==chars.size() || chars[i]!=chars[i+1]){
                chars[idx++]=chars[i];
                if(count!=1){
                    for(auto c: to_string(count)){
                        chars[idx++]=c;
                    }
                }
                count=0;
            }
        }
        return idx;
    }
};