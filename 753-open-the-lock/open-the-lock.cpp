class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n=deadends.size();
        queue<string>q;
        unordered_set<string>dead(deadends.begin(),deadends.end());
        if(dead.count("0000")) return -1;
        unordered_set<string>vis;
        q.push("0000");
        vis.insert("0000");
        int level=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                string curr=q.front();
                q.pop();
                if(curr==target){
                    return level;
                }
                for(int i=0;i<4;i++){
                    string up=curr;
                    string down=curr;
                    up[i]=(curr[i]=='9')?'0':curr[i]+1;
                    down[i]=(curr[i]=='0')?'9':curr[i]-1;

                    if(!dead.count(up) && !vis.count(up)){
                        q.push(up);
                        vis.insert(up);
                    }
                    if(!dead.count(down) && !vis.count(down)){
                        q.push(down);
                        vis.insert(down);
                    }
                }
            }
            level++;
        }
        return -1;
    }
};