class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        int ans = 0;
        while(l<=r){
            int mid = l + (r-l)/2;
            long long count = 0;
            for(int i:piles){
                if(i<mid) count++;
                else if(i%mid==0) count += i/mid;
                else if(i%mid!=0) count += i/mid + 1;
            }
            if(count<=h){
                ans = mid;
                r = mid-1;
            }
            else l = mid+1;
        }
        return ans;
    }
};