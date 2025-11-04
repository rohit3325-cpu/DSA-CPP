class Solution {
public:
    double myPow(double x, long n) {
        long long m=n;
        if(m==0)
        return 1;
        if(m<0)
        return myPow(1/x,-m);
        if(m%2==0)
        return myPow(x*x,m/2);
        else{
            return x*myPow(x*x,m/2);
        }
    }
};