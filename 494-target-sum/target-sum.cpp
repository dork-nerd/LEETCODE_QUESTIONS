class Solution {
public:
    int count = 0;
    int t = 0;
    void rec(vector<int>& vec,int sum,int i){
        if(i==vec.size()){
            if(sum==t) count++;
            return;
        }
        rec(vec,sum+vec[i],i+1);
        rec(vec,sum-vec[i],i+1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        t = target;
        rec(nums,0,0);
        return count; 
    }
};