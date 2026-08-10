class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        int pos = nums.size() - 1;
        while(left <= right){
            int left_ = nums[left] * nums[left];
            int right_ = nums[right] * nums[right];

            if(left_ < right_){
                result[pos] = right_;
                right--;
            }
            else{
                result[pos] = left_;
                left++;
            }

            pos--;
        }

        return result;
    }
};