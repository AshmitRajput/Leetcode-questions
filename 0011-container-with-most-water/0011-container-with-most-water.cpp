class Solution {
public:
    int maxArea(vector<int>& height) {
        long n=height.size();
        long l=0,r=n-1;
        long maxi=0;
        while(l!=n-1 && r!=0){
            long mini=min(height[l],height[r]);
            long area = mini*(r-l);
            if(area>maxi) maxi=area;
            if(height[l]<height[r]) l++;
            else{
                r--;
            }
            if(l==n-1) r--;
            if(r==0) l++;

        }
        return maxi;
    }
};