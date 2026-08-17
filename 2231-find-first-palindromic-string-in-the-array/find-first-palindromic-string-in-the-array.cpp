class Solution {
public:
bool ispal(string word){
    int n=word.size();
    int i=0,j=n-1;
    while(i<j){
        if(word[i]!=word[j]){
            return false;
        }
        else{
            i++;
            j--;
        }

    }
    return true;
}
    string firstPalindrome(vector<string>& words) {
        int n=words.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(ispal(words[i])){
                ans=words[i];
                break;
            }
        }
        return ans;
    }
};