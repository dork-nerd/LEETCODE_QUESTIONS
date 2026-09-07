#define rep(i,a,b) for(int i=a;i<b;i++)
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int oddcount = 0;
        int evencount = 0;
        int mini = nums1[0];
        rep(i,0,nums1.size()){
            if(nums1[i]%2==0){
                evencount++;
            }
            else {
                oddcount++;
            }
            mini = min(mini,nums1[i]);
        }
        if(oddcount==0 || evencount==0 || mini%2!=0) return true;
        return false;
    }
};