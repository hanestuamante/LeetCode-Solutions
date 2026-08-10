
class Solution {
public:
    std::vector<int> majorityElement(std::vector<int>& nums) {
        int cand1 = 0, cand2 = 0;
        int count1 = 0, count2 = 0;

       
        for (int num : nums) {
            if (num == cand1) {
                count1++;
            } else if (num == cand2) {
                count2++;
            } else if (count1 == 0) {
                cand1 = num;
                count1 = 1;
            } else if (count2 == 0) {
                cand2 = num;
                count2 = 1;
            } else {
                count1--;
                count2--;
            }
        }

        // Bước 2: Xác minh lại tần suất thực tế của 2 ứng viên
        count1 = 0;
        count2 = 0;
        for (int num : nums) {
            if (num == cand1) count1++;
            else if (num == cand2) count2++;
        }

        std::vector<int> result;
        int n = nums.size();
        if (count1 > n / 3) result.push_back(cand1);
        if (count2 > n / 3) result.push_back(cand2);

        return result;
    }
};