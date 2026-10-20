class Solution {
public:
    void f(vector<int>&d,int n){
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                d.push_back(i);
                if(i*i!=n)d.push_back(n/i);
            }
        }
    }
    bool rot(vector<int>&a,vector<int>&b){
        int n=a.size();
        long long mod=1e9+7,base=131;
        long long ha=0,hb=0,p=1;
        for(int i=0;i<n;i++){
            ha=(ha*base+a[i])%mod;
            hb=(hb*base+b[i])%mod;
            if(i<n-1) p=p*base%mod;
        }
        vector<int>t=a;
        t.insert(t.end(),a.begin(),a.end());
        for(int i=0;i<2*n;i++){
            if(i>=n){
                ha=(ha - t[i-n]*p%mod + mod)%mod;
                ha=(ha*base + t[i])%mod;
            }
            if(i>=n-1){
                if(ha==hb) return 1;
            }
        }
        return 0;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int>b=nums;
        sort(b.begin(),b.end());
        vector<int>d;
        f(d,n);
        for(int k:d){
            bool yes=1;
            for(int i=0;i<n&&yes;i+=k){
                vector<int>a(k),c(k);
                for(int j=0;j<k;j++){
                    a[j]=nums[i+j];
                    c[j]=b[i+j];
                }
                if(!rot(a,c)) yes=0;
            }
            if(yes) ans+=k;
        }
        return ans;
    }
};