class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        if(h==piles.size()) return piles[piles.size()-1];
        int ans=-1;
        int start=1,end=piles[piles.size()-1];
        while(start<=end){
            int mid=(start+end)/2;
            long long hours=0;
            for(int i=0;i<piles.size();i++){
                hours += ceil((double)piles[i]/(double)mid);

            }
            if(hours>h) start=mid+1;
            else if(hours<=h){
                end=mid-1;
                ans=mid;
            }

        }
        return ans;
    }
};