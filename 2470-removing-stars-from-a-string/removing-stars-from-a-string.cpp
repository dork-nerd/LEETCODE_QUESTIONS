#define rep(i,a,b) for(int i=a;i<b;i++)
class Solution {
public:
    string removeStars(string s) {
        vector<char> vec;
        string str = "";
        rep(i,0,s.size()){
            if(s[i]>='a' && s[i]<='z') vec.push_back(s[i]);
            else vec.pop_back();
        }
        rep(i,0,vec.size()){
            str += vec[i];
        }
        return str;
    }
};