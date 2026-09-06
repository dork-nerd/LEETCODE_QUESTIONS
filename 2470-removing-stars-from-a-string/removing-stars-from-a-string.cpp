#define rep(i,a,b) for(int i=a;i<b;i++)
class Solution {
public:
    string removeStars(string s) {
        string str = "";
        rep(i,0,s.size()){
            if(s[i]>='a' && s[i]<='z') str.push_back(s[i]);
            else str.pop_back();
        }
        return str;
    }
};