class Solution {
public:
static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),cmp);
        int start=intervals[0][0];
        int end=intervals[0][1];
        int ans=0;
        for(int i=1;i<n;i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            if(s<end){
                ans++;
            }
            else{
                end=e;
                start=s;
            }
        }
        return ans;
    }
};