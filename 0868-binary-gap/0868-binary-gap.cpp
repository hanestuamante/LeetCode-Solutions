class Solution {
public:
    int binaryGap(int n) {
        int max_gap = 0;
        int last_pos = -1; // Stores the index of the previous '1'
        int current_pos = 0;

        while (n > 0) {
            // Check if the rightmost bit is a 1
            if (n & 1) {
                if (last_pos != -1) {
                    // Calculate distance and update max_gap
                    max_gap = max(max_gap, current_pos - last_pos);
                }
                // Update last_pos to the current index
                last_pos = current_pos;
            }
            
            // Move to the next bit (right shift) and increment index
            n >>= 1;
            current_pos++;
        }

        return max_gap;
    }
};