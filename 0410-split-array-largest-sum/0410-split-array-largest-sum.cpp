class Solution {
public:
    int count(vector<int>& arr,int pages){
        int students=1;
        long long studentpages=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]+studentpages<=pages){
                studentpages+=arr[i];
            }
            else{
                students+=1;
                studentpages=arr[i];
            }
        }
        return students;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid = low+((high-low)/2);
            int student=count(nums,mid);
            if(student>k) low=mid+1;
            else{
                high=mid-1;
            }
        }
        return low;
    }
};