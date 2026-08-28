class Solution {
public:
    vector<string> letterCombinations(string arr) {
        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string>ans;
        string current;
        backtrack(0,ans,arr,current,mapping);
        return ans;
    }
    void backtrack(int ind,vector<string>&ans,string &arr,
        string &current,vector<string> &mapping){
            if(ind==arr.size()){
                ans.push_back(current);
                return ;
            }
           int digit = arr[ind];

    
    if (digit == 0 || digit == 1) {
        backtrack(ind + 1, ans, current, arr, mapping);
        return;
    }
            string letters=mapping[arr[ind]-'0'];
            for(char ch:letters){
                current.push_back(ch);
                backtrack(ind+1,ans,arr,current,mapping);
                current.pop_back();
            }
        }
};