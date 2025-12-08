class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        vector<int>pse(n,0);
        vector<int>nse(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }
            else{
             nse[i]=st.top();
            }
            st.push(i);
        }

        st=stack<int>();

        for(int i=0;i<n;i++){
            while(!st.empty()&&heights[st.top()]>heights[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }
            else{
             pse[i]=st.top();
            }
            st.push(i);

        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;


    }
};