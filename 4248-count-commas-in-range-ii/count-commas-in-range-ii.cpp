class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        long long commacount = 0;
        long long div = 1000;
        while(n/div>0){
            commacount += (count*(div-div/1000));
            div = div*1000;
            count++;
        }
        cout << div << " ";
        div=div/1000;
        cout << div << " ";
        cout << commacount;
        commacount += (count*(n-div));
        return commacount+count;
    }
};