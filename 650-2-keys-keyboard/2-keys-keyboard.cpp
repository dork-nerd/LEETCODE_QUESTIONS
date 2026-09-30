class Solution {
public:
    int minSteps(int n) {
        if(n==1)return 0;
        int currA = 1;
        int curr = 1;
        int count = 1;
        while(curr<n){
            curr += currA;
            count++;
            if(n-curr==0) break;
            if((n-curr)%(curr)==0){
                currA = curr;
                count++;
            }
        }
        return count;
    }
};