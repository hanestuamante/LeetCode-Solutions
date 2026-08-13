class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        unordered_set<char> se;
        int max_len = 0;

        for (int right = 0; right < s.length(); right++) {
            while (se.count(s[right])) {
                se.erase(s[left]);
                left++;
            }

            se.insert(s[right]);

            max_len = max(max_len, right - left + 1);
        }

        return max_len;
    }
};