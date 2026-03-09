class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        long long result = 0;
        // Stack stores pairs: {value, current_frequency_in_valid_range}
        stack<pair<int, int>> st;

        for (int x : nums) {
            // Maintain monotonic decreasing property
            while (!st.empty() && st.top().first < x) {
                st.pop();
            }

            if (!st.empty() && st.top().first == x) {
                // We found a match; increment the frequency
                st.top().second++;
            } else {
                // New element or smaller than top, start a new count
                st.push({x, 1});
            }

            // The number of valid subarrays ending here is the frequency of 'x'
            result += st.top().second;
        }

        return result;
    }
};