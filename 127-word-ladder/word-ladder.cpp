class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        queue<string>q;
        unordered_set<string>vis;
        unordered_set<string>dict(wordList.begin(),wordList.end());
        if (!dict.count(endWord))
        return 0;
        q.push(beginWord);
        vis.insert(beginWord);
        int lvl=0;
        while(!q.empty()){
            int s=q.size();
            while(s--){
                string curr=q.front();
                q.pop();
                if(curr==endWord){
                    return lvl+1;
                }
                for(int i=0;i<curr.size();i++){
                   string word=curr;
                   char original=word[i];
                   for(char ch='a';ch<='z';ch++){
                    if(ch == original) continue;
                    word[i]=ch;
                    if(dict.count(word) && !vis.count(word)){
                    q.push(word);
                    vis.insert(word);
                }

                }
                word[i]=original;

                }
            }
            lvl++;
        }
        return 0;
    }
};