class Solution {
public:
    int maxDistinct(string s) {
        int n=s.size();
        unordered_set<int>st;
        for(auto it:s){
            st.insert(it);
        }
        return st.size();
    }
};