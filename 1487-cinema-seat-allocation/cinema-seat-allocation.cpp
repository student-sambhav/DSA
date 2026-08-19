class Solution {
public:
int calrow(vector<bool>&vis){
    int res=0;
  if(!vis[2] && !vis[3] && !vis[4] && !vis[5]){
    res++;
  }
  else if(!vis[4] && !vis[5] && !vis[6] && !vis[7]){
    res++;
    vis[6]=true;
    vis[7]=true;
  }
  if(!vis[6] && !vis[7] && !vis[8] && !vis[9]){
    res++;
  }
  return res;
}
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int k=reservedSeats.size();
        sort(reservedSeats.begin(),reservedSeats.end());
        int res=2*(reservedSeats[0][0]-1);
        vector<bool>vis(11,0);
        for(int i=0;i<k;i++){
            if( i>0 &&reservedSeats[i][0]!=reservedSeats[i-1][0]){
                res+=calrow(vis);
                for(int j=1;j<=10;j++){
                    vis[j]=false;
                }
                res+=2*(reservedSeats[i][0]-reservedSeats[i-1][0]-1);
            }
            vis[reservedSeats[i][1]]=true;
        }
        res+=calrow(vis);
        res+=2*(n-reservedSeats[k-1][0]);
        return res;     
    }
};