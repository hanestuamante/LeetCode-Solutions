class Solution {
public:
    int mySqrt(int x) {
        // Trường hợp đặc biệt: x = 0 hoặc x = 1
        if (x < 2) return x;

        int left = 1, right = x / 2;
        int ans;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Dùng phép chia (x / mid) thay vì (mid * mid) để tránh tràn số kiểu int
            if (mid <= x / mid) {
                ans = mid;     // Tạm thời ghi nhận mid là kết quả tiềm năng
                left = mid + 1; // Thử tìm số lớn hơn ở bên phải
            } else {
                right = mid - 1; // Số này quá lớn, thu hẹp về bên trái
            }
        }

        return ans;
    }
};