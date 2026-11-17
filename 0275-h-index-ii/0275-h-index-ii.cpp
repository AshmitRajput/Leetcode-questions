class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int left=1;
        int right=n;
        int ans=0;

        while(left<=right) {
            int mid=left+(right-left)/2;
            if (citations[n-mid]>=mid) {
                ans=mid;
                left=mid+1;
            }else{
                right=mid-1; 
            }
        }

        return ans;
    }
};