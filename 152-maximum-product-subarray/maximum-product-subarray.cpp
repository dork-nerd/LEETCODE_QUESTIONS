class Solution {
public:
    int maxi = -11;
    void maxsub(vector<int> &vec,int l ,int r){
        if(l<0 || l>vec.size()-1) return; 
        if(l>r) return;
        if(l==r){
            maxi = max(maxi,vec[l]);
            return;
        } 
        int count = 0;
        int first = -1;
        int last = -1;
        int prod = 1;
        for(int i=l;i<=r;i++){
            if(vec[i]<0){
                if(first==-1) first = i;
                last = i;
                count++;
            }
            prod = prod*vec[i];
        }
        if(count%2==0){
            maxi = max(maxi,prod);
            return;
        }
        else{
            prod = 1;
            for(int i=l;i<last;i++){
                prod = prod*vec[i];
            }
            maxi = max(maxi,prod);
            prod = 1;
            for(int i=first+1;i<=r;i++){
                prod = prod*vec[i];
            }
            maxi = max(maxi,prod);
        }
        return;
    }
    int maxProduct(vector<int>& nums){
        int l=0;
        int flag=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                flag = 1;
                maxsub(nums,l,i-1);
                l = i+1; 
            }
            else continue;
        }
        maxsub(nums,l,nums.size()-1);
        if(flag==1) return max(maxi,0);
        return maxi;
    }
};