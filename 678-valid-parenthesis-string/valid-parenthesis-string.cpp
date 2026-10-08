class Solution {
public:
    bool checkValidString(string s) {
        int l = 0;
        int st = 0;
        int r = 0;
        int closing = 0;
        for(char c:s){
            if(c=='('){
                l++;
                closing++;
            }
            else if(c=='*'){
                st++;
                closing--;
            }
            else {
                r++;
                closing--;
            }
            if(l+st<r) return false;
            if(closing<0) closing=0;
        }
        return closing==0;
    }
};