
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> arr;
        unordered_map<int, int> freq; // Key: số trong nums, Value: số lần xuất hiện

        for (int temp : nums) {
            // Kiểm tra điều kiện: Nếu key này chưa xuất hiện quá 2 lần
            if (freq[temp] < 2) {
                arr.push_back(temp); // Thêm vào mảng kết quả
                freq[temp]++;        // Đánh dấu tăng số lần xuất hiện
            }
            // Nếu freq[temp] == 2 thì bỏ qua, không push_back nữa
        }

        nums = arr;          // Ghi đè lại mảng gốc
        return nums.size();  // Trả về độ dài mảng thỏa mãn
    }
};