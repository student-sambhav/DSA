class Solution {
public:
    int numSteps(string s) {
        int steps=0;
        int carry=0;
        int n=s.size();
        for(int i=n-1;i>0;i--){
            int bit=s[i]-'0'+carry;
            if(bit==0){
                steps+=1;
            }
            else if(bit==1){
                steps+=2;
                carry=1;
            }
            else{
                steps++;
                carry=1;
            }
        }
            if(s[0]-'0'+carry==2){
                steps++;
            }
            return steps;
        }
};