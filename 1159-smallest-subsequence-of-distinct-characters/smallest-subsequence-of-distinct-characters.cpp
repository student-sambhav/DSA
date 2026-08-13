class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char,int>mpp;
        for(char c:s) mpp[c]++;
        stack<char>st;
        int n=s.size();
        vector<int>vis(26,0);
        for(int i=0;i<n;i++){
            mpp[s[i]]--;
            if(vis[s[i]-'a']) continue;
            while(!st.empty() && st.top()>s[i] && mpp[st.top()]>0){
                vis[st.top()-'a']=0;
                st.pop();
            }
                st.push(s[i]);
                vis[s[i]-'a']=1;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};