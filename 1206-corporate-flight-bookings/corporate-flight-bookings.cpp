#define rep(i,a,b) for(int i=a;i<b;i++)
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> vec(n+1);
        vector<int> ans(n);
        rep(i,0,bookings.size()){
            vec[bookings[i][0]-1] += bookings[i][2];
            vec[bookings[i][1]] -= bookings[i][2];
        }
        int sum = 0;
        rep(i,0,n){
            ans[i] = sum + vec[i];
            sum += vec[i];
        }
        return ans;
    }
};