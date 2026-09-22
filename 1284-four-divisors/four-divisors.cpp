class Solution {
public:
    vector<int> ans;
    void isdiv(int num) {
        int cnt = 0;
        vector<int> temp;
        for (int i = 1; i <= sqrt(num); i++) {
            if (num % i == 0) {
                temp.push_back(i);
                cnt++;
                if (i != num / i) {
                    temp.push_back(num / i);
                    cnt++;
                }
            }
        }
        if (cnt == 4) {
            for (int x : temp)
                ans.push_back(x);
        }
    }
    int sumFourDivisors(vector<int>& nums) {
        ans.clear();
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            isdiv(nums[i]);
        }
        for (int i = 0; i < ans.size(); i++) {
            sum += ans[i];
        }
        return sum;
    }
};