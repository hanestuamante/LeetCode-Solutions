class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = floor(nums.size() / 2);
        unordered_map<int, int> ma;
        for(int i = 0; i < nums.size(); i++){
            ma[nums[i]]++;
        }

        for(auto &pair : ma){
            if(pair.second > n){
                return pair.first;
            }
        }
        return -1;
    }
};