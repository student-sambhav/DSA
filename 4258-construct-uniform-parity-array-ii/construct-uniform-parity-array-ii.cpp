class Solution {
public:
bool check(vector<int>& arr,int parity){
    int n=arr.size();
    int smallodd=INT_MAX;
    for(auto x:arr){
        if(x%2!=0)
        smallodd=min(smallodd,x);
    }
    for(int i=0;i<n;i++){
        if(arr[i]%2==parity) continue;
        if(smallodd>=arr[i]){
            return false;
        }
    }
    return true;

}
    bool uniformArray(vector<int>& arr) {
        return check(arr,0) || check(arr,1);
    }
};