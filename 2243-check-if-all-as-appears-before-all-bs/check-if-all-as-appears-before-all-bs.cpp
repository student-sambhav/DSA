class Solution {
public:
    bool checkString(string s) {
        char prev='a';
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' && prev=='b'){
                return false;
            }
            
            if(s[i]=='a'){
                prev='a';
                continue;
            }
            else{
                prev='b';
            }

        }
        return true;
    }
};