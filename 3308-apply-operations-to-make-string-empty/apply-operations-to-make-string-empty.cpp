class Solution {
public:
    string lastNonEmptyString(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int maxi=0;
        for(char c:s){
            mpp[c]++;
            maxi=max(maxi,mpp[c]);
        }
        string ans = "";
    unordered_set<char> st;
    for(char c : s) {
        if(mpp[c] == maxi)
            st.insert(c);
    }
     for(int i = n - 1; i >= 0; i--) {
        if(st.count(s[i])) {
            ans += s[i];
            st.erase(s[i]);
        }
    }
    reverse(ans.begin(), ans.end());
        return ans;

    }
};