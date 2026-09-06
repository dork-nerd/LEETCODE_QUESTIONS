#define rep(i,a,b) for(int i=a;i<b;i++)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current = 0;
        int part = nums[0];
        rep(i,0,nums.size()){
            current += nums[i];
            if(current>part) part = current;
            if(current<0) current = 0;
        }
        return part;
    }
};