class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> arr;
        unordered_set<int> se; 

        for(int i = 0; i < nums.size(); i++){
            int temp = nums[i];

            if(se.find(temp) == se.end()){ // Tim xem temp co trong set khong, se.end() tra ve khi khong tim thay
                se.insert(temp);
                arr.push_back(temp);
            }
        }

        nums = arr; // do trinh cham co luu y, nen em se truyen tham chieu theo vector<int>& nums
        return nums.size();
    }
};