//brute force, first approach
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> arr2(2001,0);
        for(int i=0;i<arr.size();i++){
            arr2[arr[i]]=-1;
        }
        int count=0,i=1;
        while(count!=k){
            if(arr2[i]==0) count++;
            i++;
        }
        return i-1;
    }
};

//second attempt after looking at approaches
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            int missing = arr[mid]-mid-1;
            if(missing<k) low=mid+1;
            else{
                high=mid-1;
            }
        }
        return low+k;
    }
};
