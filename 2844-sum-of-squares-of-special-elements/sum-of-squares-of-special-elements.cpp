class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long sum = 0;
        int index =1;
        for(int i:nums){
            if((nums.size()%index)==0){
                sum += i*i;
            }
            index++;
        }
        return sum;
    }
};