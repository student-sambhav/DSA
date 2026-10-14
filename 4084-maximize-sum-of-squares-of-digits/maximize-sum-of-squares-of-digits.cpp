class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s="";
        int n=num;
        while(n){
            if(sum>9){
                s+=to_string(9);
                sum-=9;
            }
            else{
                s+=to_string(sum);
                sum-=sum;
            }
            n--;
        }
        if(s.size()==num && sum==0){
            return s;
        }
        return "";
    }
};