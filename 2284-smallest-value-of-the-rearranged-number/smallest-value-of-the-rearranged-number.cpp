class Solution {
public:
    long long smallestNumber(long long num) {
        vector<long long>ans;
        long long a=num;
        while(a){
        long long rem=abs(a%10);
        ans.push_back(rem);
        a/=10;
        }
        long long b=0;
        if(num>0){
            sort(ans.begin(),ans.end());
            if(ans.size()>1 && ans[0]==0){
                for(int i=0;i<ans.size();i++){
                    if(ans[i]!=0){
                        swap(ans[i],ans[0]);
                        break;
                    }
                }
            }
            for(int i=0;i<ans.size();i++){
                b=b*10+ans[i];
            }
        }
        else{
            sort(ans.begin(),ans.end(),greater<long long>());
            for(int i=0;i<ans.size();i++){
                b=b*10+ans[i];
            }
            b=-b;
        }
        return b;
    }
};