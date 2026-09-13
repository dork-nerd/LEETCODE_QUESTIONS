class Solution {
public:
    string reverseWords(string s) {
        int word = 1;
        string temp;
        string ans = "";
        for(char& c:s){
            if(c==' ') word = 0;
            if(word==0 && c!=' '){
                if(ans.size()!=0) ans = temp + ' ' + ans;
                else ans = temp + ans;
                temp = "";
                word = 1;
            }
            if(word==1)temp += c;
        }
        if(ans.size()!=0) ans = temp + ' ' + ans;
        else ans = temp + ans;
        return ans;
    }
};