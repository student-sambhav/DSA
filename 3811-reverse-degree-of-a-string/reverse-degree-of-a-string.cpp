class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int j=26;
        int sum=0;
        for(int i=0;i<n;i++){
            int sub=abs('a'-s[i]);
            sum=sum+(j-sub)*(i+1);
        }
        return sum;
    }
};