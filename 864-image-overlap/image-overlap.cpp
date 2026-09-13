class Solution {
public:

    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        long long maxi = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                long long c1 = 0;
                long long c2 = 0;
                long long c3 = 0;
                long long c4 = 0;                
                for(int k=0;k<n;k++){
                    for(int l=0;l<n;l++){
                        if(k+i<=n-1 && l+j<=n-1){
                            if(img1[k+i][l+j]==1 && img1[k+i][l+j]==img2[k][l]) c1++;
                        }
                        if(k+i<=n-1 && l-j>=0){
                            if(img1[k+i][l-j]==1 && img1[k+i][l-j]==img2[k][l]) c3++;
                        }
                        if(k-i>=0 && l-j>=0){
                            if(img1[k-i][l-j]==1 && img1[k-i][l-j]==img2[k][l]) c2++;   
                        }
                        if(k-i>=0 && l+j<=n-1){
                            if(img1[k-i][l+j]==1 && img1[k-i][l+j]==img2[k][l]) c4++;
                        }             
                    }
                }
                maxi = max({maxi,c1,c2,c3,c4});
            }
        }
        return maxi;
    }
};