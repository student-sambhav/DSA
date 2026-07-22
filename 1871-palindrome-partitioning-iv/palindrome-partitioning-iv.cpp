class Solution {
public:
vector<vector<bool>>ispal;
    bool checkPartitioning(string s) {
        int n=s.size();
        ispal.assign(n,vector<bool>(n,false));
        for(int gap=0;gap<n;gap++){
            for(int l=0;l+gap<n;l++){
                int r=l+gap;
                if(s[l]==s[r]){
                    if(r-l<=2){
                        ispal[l][r]=true;
                    }
                    else{
                        ispal[l][r]=ispal[l+1][r-1];
                    }
                }
            }
        }
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(ispal[0][i] && ispal[i+1][j] && ispal[j+1][n-1]){
                    return true;
                }
            }
        }
        return false;
    }
};