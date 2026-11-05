class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int n=arr1.size();
        int m=arr2.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int low=0,high=m-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                int sum=abs(arr1[i]-arr2[mid]);
                if(sum<=d){
                    cnt++;
                     break;
                }
                if(arr2[mid]<arr1[i]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return n-cnt;
    }
};