class Solution {
public:
vector<vector<string>>ans;
vector<string>path;
vector<vector<bool>>ispal;
void dfs(string s,int start){
    if(start==s.size()){
        ans.push_back(path);
        return ;
    }
    for(int i=start;i<s.size();i++){
        if(ispal[start][i]){
            path.push_back(s.substr(start,i-start+1));
            dfs(s,i+1);
            path.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
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
        dfs(s,0);
        return ans;
    }   
};