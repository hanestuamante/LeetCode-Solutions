class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> arr;
        unordered_set<int> se; 

        for(int i = 0; i < nums.size(); i++) {
            int temp = nums[i];

            if(se.find(temp) == se.end()) { 
                se.insert(temp);
                arr.push_back(temp);
            }
        }

        nums = arr; 
        return nums.size();
    }
};