class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long low=1;
        long long high=1LL*n*min(a,b);
        long long l=lcm(a,b);
        while(low<high){
            long long mid=low+(high-low)/2;
            long long cnt=mid/a+mid/b-mid/l;
            if(cnt>=n){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low % 1000000007;
    }
};