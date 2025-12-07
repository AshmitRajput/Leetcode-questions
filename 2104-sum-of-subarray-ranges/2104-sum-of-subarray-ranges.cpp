class Solution {
public:
    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>pse(n,0);
        vector<int>nse(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i]){
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
            while(!st.empty()&&arr[st.top()]>arr[i]){
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
        long long total=0;
        int mod = 1e9+7;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total = (total+ (right*left*1LL*arr[i]));
        }
        return total;

    }
    long long sumSubarrayMax(vector<int>& arr) {
        int n=arr.size();
        stack<int>st;
        vector<int>pse(n,0);
        vector<int>nse(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&arr[st.top()]<=arr[i]){
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
            while(!st.empty()&&arr[st.top()]<arr[i]){
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
        long long total=0;
        int mod = 1e9+7;
        for(int i=0;i<n;i++){
            int left=i-pse[i];
            int right=nse[i]-i;
            total = (total+ (right*left*1LL*arr[i]));
        }
        return total;

    }
    long long subArrayRanges(vector<int>& nums) {
        long long ans;
        ans = sumSubarrayMax(nums) - sumSubarrayMins(nums);
        return ans;
    }
};