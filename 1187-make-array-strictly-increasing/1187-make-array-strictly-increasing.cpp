
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // Step 1: Sort and remove duplicates from arr2
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());

        // dp[last_val] = min_operations
        map<int, int> dp;
        dp[-1] = 0;

        for (int x : arr1) {
            map<int, int> next_dp;
            for (auto const& [prev_val, ops] : dp) {
                // Option 1: Keep the current element arr1[i]
                if (x > prev_val) {
                    if (next_dp.find(x) == next_dp.end() || next_dp[x] > ops) {
                        next_dp[x] = ops;
                    }
                }

                // Option 2: Replace arr1[i] with an element from arr2
                // upper_bound finds the first element strictly greater than prev_val
                auto it = upper_bound(arr2.begin(), arr2.end(), prev_val);
                if (it != arr2.end()) {
                    int v = *it;
                    if (next_dp.find(v) == next_dp.end() || next_dp[v] > ops + 1) {
                        next_dp[v] = ops + 1;
                    }
                }
            }
            
            if (next_dp.empty()) return -1;
            dp = move(next_dp);
        }

        // The answer is the minimum value in our final map
        int res = 2001; // Max possible operations is arr1.size() (max 2000)
        for (auto const& [val, ops] : dp) {
            res = min(res, ops);
        }

        return res;
    }
};