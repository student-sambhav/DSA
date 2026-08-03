class Solution {
public:
    bool check(string &s,int i,int j){
    if(i>j){
        return true;
    }
    if(s[i]==s[j]){
        return check(s,i+1,j-1);
    }
    return false;
}
    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=0;
        int newi=0,newj=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
            if(check(s,i,j)){
                if(j-i>maxi){
                    newi=i;
                    newj=j;
                    maxi=j-i;
                }
            }
            }
        }
        return s.substr(newi,newj-newi+1);
    }
};