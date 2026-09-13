class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        if(n==1) return 10;
        long long count = 10;
        n = n-1;
        int digit = 9;
        while(n){
            int mul = 9;
            for(int i=0;i<n;i++){
                mul = mul*(digit-i);
            }
            count += mul;
            n--;
        }
        return count;
    }
};