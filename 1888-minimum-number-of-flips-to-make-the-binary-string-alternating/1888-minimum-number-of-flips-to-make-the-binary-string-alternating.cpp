class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        string doubled = s + s;
        
        // Target strings of the same length as the doubled string
        string t1 = "", t2 = "";
        for (int i = 0; i < doubled.length(); i++) {
            t1 += (i % 2 == 0 ? '0' : '1');
            t2 += (i % 2 == 0 ? '1' : '0');
        }
        
        int diff1 = 0, diff2 = 0;
        int minFlips = INT_MAX;
        
        // Sliding window across the doubled string
        for (int i = 0; i < doubled.length(); i++) {
            // Add new character's diff
            if (doubled[i] != t1[i]) diff1++;
            if (doubled[i] != t2[i]) diff2++;
            
            // If window size exceeds n, remove the element sliding out
            if (i >= n) {
                if (doubled[i - n] != t1[i - n]) diff1--;
                if (doubled[i - n] != t2[i - n]) diff2--;
            }
            
            // Once we have a full window of size n, record the minimum
            if (i >= n - 1) {
                minFlips = min({minFlips, diff1, diff2});
            }
        }
        
        return minFlips;
    }
};