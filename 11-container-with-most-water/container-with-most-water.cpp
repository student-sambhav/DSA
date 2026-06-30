class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        long long maxi=0;
        while(l<r){
            int mini=min(height[l],height[r]);
            long long ans=(r-l)*mini;
            maxi=max(maxi,ans);
            if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }
        }
        return maxi;
    }
};