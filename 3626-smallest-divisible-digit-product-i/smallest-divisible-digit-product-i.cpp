class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans=0;
        for(int i=n;i<=n+10;i++){
            int pro=1;
            int a=i;
            while(a){
                int rem=a%10;
                pro=pro*rem;
                a/=10;
            }
            if(pro%t==0){
                ans=i;
               break;
            }
        }
        return ans;

    }
};