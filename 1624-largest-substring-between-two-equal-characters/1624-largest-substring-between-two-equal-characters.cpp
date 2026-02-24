

class Solution {
public:
    int maxLengthBetweenEqualCharacters(std::string s) {
        // Array to store the first seen index of each character 'a'-'z'
        std::vector<int> first_occurrence(26, -1);
        int max_len = -1;

        for (int i = 0; i < s.length(); ++i) {
            int char_index = s[i] - 'a'; // Convert char to 0-25 index

            if (first_occurrence[char_index] != -1) {
                // Character seen before, calculate distance
                int current_len = i - first_occurrence[char_index] - 1;
                max_len = std::max(max_len, current_len);
            } else {
                // First time seeing this character, store its index
                first_occurrence[char_index] = i;
            }
        }

        return max_len;
    }
};