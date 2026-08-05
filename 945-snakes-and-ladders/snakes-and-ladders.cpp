class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int>vis(n*n+1,0);
        queue<int>q;
        q.push(1);
        vis[1]=1;
        int level=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
            int curr=q.front();
            q.pop();
            if(curr==n*n){
                return level;
            }
            for (int dice = 1; dice <= 6 && curr + dice <= n * n; dice++) {
                    int next = curr + dice;
                    int row = n - 1 - (next - 1) / n;
                    int col = (next - 1) % n;
                    int rowFromBottom = (next - 1) / n;
                    if (rowFromBottom % 2 == 1)
                        col = n - 1 - col;
                    if (board[row][col] != -1)
                        next = board[row][col];
                    if (!vis[next]) {
                        vis[next] = 1;
                        q.push(next);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};