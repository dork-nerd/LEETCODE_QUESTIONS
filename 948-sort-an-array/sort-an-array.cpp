class Solution {
public:
    void merge(vector<int> &vec,int l,int r){
        vector<int> ans(r-l+1);
        int st1 = l;
        int mid = l+(r-l)/2;
        int st2 = mid+1;
        int k = 0;
        while(st1<=mid && st2<=r){
            if(vec[st1]<vec[st2]){
                ans[k] = vec[st1];
                st1++;
            }
            else{
                ans[k] = vec[st2];
                st2++;
            }
            k++;
        }
        while(st1<=mid){
            ans[k++] = vec[st1++];
        }
        while(st2<=r){
            ans[k++] = vec[st2++];
        }
        k=0;
        for(int i=l;i<=r;i++){
            vec[i] = ans[k++];
        }
    }
    void breakk(vector<int> &vec,int l,int r){
        if(l<r){
            int mid = l + (r-l)/2;
            breakk(vec,l,mid);
            breakk(vec,mid+1,r);
            merge(vec,l,r);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        int mid = l+(r-l)/2;
        breakk(nums,l,r);
        return nums;
    }
};