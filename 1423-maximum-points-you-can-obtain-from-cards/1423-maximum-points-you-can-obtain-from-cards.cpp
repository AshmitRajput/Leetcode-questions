class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size()-1;
        int rsum=0,lsum=0,maxsum=0;
        for(int i=0;i<k;i++) lsum+=cardPoints[i];
        maxsum=lsum;
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[n--];
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
        
    }
};