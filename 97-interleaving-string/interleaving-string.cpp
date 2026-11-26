class Solution {
public:
int n,m,K;
int t[101][101][201];
bool solve(int i,int j,int k,string &s1, string &s2, string &s3){
    if(i==n && j==m && k==K) return true;
    if(k>=K) return false;
    bool res=false;
    if(t[i][j][k]!=-1) return t[i][j][k];
    if(s1[i]==s3[k]){
        res=solve(i+1,j,k+1,s1,s2,s3);
    }
    if(res==true) return t[i][j][k]= res;
    if(s2[j]==s3[k]){
        res= solve(i,j+1,k+1,s1,s2,s3);
    }
    return t[i][j][k]=res;
}
    bool isInterleave(string s1, string s2, string s3) {
        n=s1.size();
        m=s2.size();
        K=s3.size();
        memset(t,-1,sizeof(t));
        return solve(0,0,0,s1,s2,s3);
    }
};