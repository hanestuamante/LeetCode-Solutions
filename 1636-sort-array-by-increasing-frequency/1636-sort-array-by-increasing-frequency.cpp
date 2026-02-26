


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] != freq[b]) {
                // Primary: Ascending Frequency
                return freq[a] < freq[b];
            }
            // Secondary: Descending Value
            return a > b;
        });

        return nums;
    }
};