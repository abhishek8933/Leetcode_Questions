class Solution {
public:
    
    bool isValid(vector<int>& weights,int n,int k,int max){
        int day=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
            if(sum>max){
                day++;
                sum=weights[i];
            }
            if(day>k){
                return false;
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n=weights.size();
        if(days>n){
            return -1;
        }
        int start=INT_MIN;
        int end=0;
        for(int i=0;i<n;i++){
            end+=weights[i];
            if(weights[i]>start){
                start=weights[i];
            }
        }
        int res=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isValid(weights,n,days,mid)){
                res=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return res;
    }
};