class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
    int n = nums.size();

    unordered_map<int, vector<int>> mpp;

    for(int i = 0; i < n; i++) {
        mpp[nums[i]].push_back(i);
    }

    vector<int> ans;

    for(int q : queries) {

        vector<int>& arr = mpp[nums[q]];

        if(arr.size() == 1) {
            ans.push_back(-1);
            continue;
        }

        int low = 0;
        int high = arr.size() - 1;

        // Find q's position
        while(low < high) {
            int mid = low + (high - low) / 2;

            if(arr[mid] >= q)
                high = mid;
            else
                low = mid + 1;
        }

        int pos = low;
        int res = INT_MAX;

        // Next occurrence
        int next = (pos + 1) % arr.size();

        // Previous occurrence
        int prev = (pos - 1 + arr.size()) % arr.size();

        int d1 = abs(arr[pos] - arr[next]);
        int d2 = abs(arr[pos] - arr[prev]);
        d1 = min(d1, n - d1);
        d2 = min(d2, n - d2);

        res = min(d1, d2);

        ans.push_back(res);
    }

    return ans;
}
};