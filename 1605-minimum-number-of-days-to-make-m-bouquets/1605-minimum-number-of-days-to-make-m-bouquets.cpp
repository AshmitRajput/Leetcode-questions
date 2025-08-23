class Solution {
public:
    int maxi(vector<int>& arr){
        int bada = INT_MIN;
        for(int i=0;i<arr.size();i++) bada=max(bada,arr[i]);
        return bada;
    }
    int mini(vector<int>& arr){
        int chota = INT_MAX;
        for(int i=0;i<arr.size();i++) chota=min(chota,arr[i]);
        return chota;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        long long t=m*1LL*k*1LL;
        if(t>bloomDay.size()) return -1;
        if(t==bloomDay.size()) return maxi(bloomDay);
        int start=mini(bloomDay),end=maxi(bloomDay),ans =-1;
        while(start<=end){
            int mid=(end+start)/2, bouqet=0, count=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid) count++;
                else{
                    count=0;
                }
                if(count==k){
                    bouqet++;
                    count=0;
                }
            }
            if(bouqet<m) start=mid+1;
            else if(bouqet>=m){
                end=mid-1;
                ans=mid;
            }

        }
        return ans;

    }
};