class Solution {
public:
  string strWithout3a3b(int a, int b) {
    string ans = "";

    while(a > 0 || b > 0) {

        if(a > b) {
            if(a >= 2) {
                ans += "aa";
                a -= 2;
            }
            else {
                ans += "a";
                a--;
            }

            if(b > 0) {
                ans += "b";
                b--;
            }
        }
        else if(b > a) {
            if(b >= 2) {
                ans += "bb";
                b -= 2;
            }
            else {
                ans += "b";
                b--;
            }

            if(a > 0) {
                ans += "a";
                a--;
            }
        }
        else {
            ans += "ab";
            a--;
            b--;
        }
    }

    return ans;

    }
};