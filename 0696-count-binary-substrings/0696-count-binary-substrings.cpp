class Solution {
public:
    int countBinarySubstrings(std::string s) {
        int ans = 0;
        int prevGroup = 0;   // Length of the previous consecutive block
        int currGroup = 1;   // Length of the current consecutive block
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                // Still in the same block of 0s or 1s
                currGroup++;
            } else {
                // We hit a transition (0 to 1 or 1 to 0)
                // Add the minimum of the two adjacent groups to our total
                ans += std::min(prevGroup, currGroup);
                
                // The current group now becomes the previous group
                prevGroup = currGroup;
                currGroup = 1;
            }
        }
        
        // Final addition for the last two groups encountered
        return ans + std::min(prevGroup, currGroup);
    }
};