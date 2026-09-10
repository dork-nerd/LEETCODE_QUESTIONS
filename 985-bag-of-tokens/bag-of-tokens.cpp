class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int front = 0;
        int back = tokens.size()-1;
        int forward = 0;
        int maxi = 0;
        while(front<=back){
            if(tokens[front]<=power){
                power -= tokens[front++];
                forward++;
                maxi = max(maxi,forward);
            }
            else if(forward>0){
                power += tokens[back--];
                forward--;
            }
            else break;
        }
        return maxi;
    }
};