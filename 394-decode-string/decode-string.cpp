class Solution {
public:
    string decodeString(string s) {
      stack<pair<int,string>>st;
      int curnum=0;
      string curst="";
      for(char c:s){
        if(isdigit(c)){
            curnum=curnum*10+(c-'0');
        }
        else if(c=='['){
            st.push({curnum,curst});
            curnum=0;
            curst="";
        }
        else if(isalpha(c)){
            curst+=c;
        }
        else{
            auto[cnt,prev]=st.top();
            st.pop();
            string temp="";
            while(cnt){
                temp+=curst;
                cnt--;
            }
            curst=prev+temp;
        }
      }
      return curst;  
    }
};