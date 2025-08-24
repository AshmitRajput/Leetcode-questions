class Solution {
public:

    int maxi(vector<int>& weights){
        int bada=INT_MIN;
        for(int i=0;i<weights.size();i++) if(weights[i]>bada) bada=weights[i];
        return bada;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        if(days==weights.size()) return maxi(weights);
        int low=maxi(weights); long long high=0;
        for(int i=0;i<weights.size();i++) high += (weights[i]*1LL);
        if(days==1) return high;
        while(low<=high){
            int mid=low+((high-low)/2);
            int sum=0,count=1;
            for(int i=0;i<weights.size();i++){
                if(weights[i]+sum>mid){
                    count++;
                    sum=weights[i];
                }
                else{
                    sum += weights[i];
                }
            }
            if(count<=days) high=mid-1;
            else if(count>days) low=mid+1;


        }
        return low;
    }
};