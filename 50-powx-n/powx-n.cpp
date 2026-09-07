class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(n==0) return 1;
        long long exp = n;
        if(n<0) exp = -exp;
        double res = 1;
        double run = x;
        while(exp!=0){
            if((exp&1)==1) res = res*run;
            run = run*run;
            exp = exp>>1;
        }
        if(n<0) return (1/res);
        return res;
    }
};