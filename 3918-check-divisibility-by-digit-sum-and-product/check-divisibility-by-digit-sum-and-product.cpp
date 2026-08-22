class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int x=n;
        while(x>0){
            int r=x%10;
            sum +=r;
            product *=r;
            x=x/10;
        }
        if(n%(sum+product)==0){
            return true;
        }
        return false;
    }
};