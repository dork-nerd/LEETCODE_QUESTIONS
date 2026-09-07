#define rep(i,a,b) for(int i=a;i<b;i++)
#define reprev(i,a,b) for(int i=a;i>=b;i--)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> maxii(nums.size());
        vector<int> minii(nums.size());
        int maxi = nums[0];
        int mini = nums[nums.size()-1];
        rep(i,0,nums.size()){
            maxi = max(nums[i],maxi);
            maxii[i] = maxi;
        }
        reprev(i,nums.size()-1,0){
            mini = min(nums[i],mini);
            minii[i] = mini;
        }
        rep(i,0,nums.size()){
            if(maxii[i]-minii[i]<=k) return i;
        }
        return -1;
    }
};