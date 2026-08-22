class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0,product=1;
        int a=n;
        while(n){
            int rem=n%10;
            n/=10;
            sum+=rem;
            product*=rem;
        }
        if(sum+product==0) return false;
        if(a%(sum+product)==0){
            return true;
        }
        return false;
    }
};