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

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxarea=0;
        vector<vector<int>>presum(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=matrix[i][j]-'0';
                if(matrix[i][j]=='0') sum=0;
                presum[i][j]=sum;
            }
        }

        for(int i=0;i<n;i++){
            maxarea=max(maxarea,largestRectangleArea(presum[i]));
        }
        return maxarea;

    }
};