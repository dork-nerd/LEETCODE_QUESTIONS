class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) { 
        sort(score.begin(),score.end(),[k](const vector<int>& vec1,const vector<int>& vec2){
            return vec1[k]>vec2[k];
        });
        return score;
    }
};