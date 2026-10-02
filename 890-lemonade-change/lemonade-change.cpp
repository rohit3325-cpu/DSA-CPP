class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c1=0;
        int c2=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5) c1++;
            else{
                if(bills[i]==10){
                    if(c1>0){
                        c2++;
                        c1--;
                    }else{
                        return false;
                    }
                }else{
                    if(c1>0 && c2>0){
                        c1--;
                        c2--;
                    }else{
                        if(c1>=3){
                            c1 -=3;
                        }else{
                            return false;
                        }
                    }
                }

            }
        }
        return true;
    }
};