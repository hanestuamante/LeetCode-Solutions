class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        unordered_map<int, string> mp;
        
        // 1. Sao chép mảng gốc để giữ nguyên thứ tự ban đầu
        vector<int> sorted_score = score; 

        // 2. Sắp xếp giảm dần để tìm thứ hạng
        sort(sorted_score.begin(), sorted_score.end(), greater<int>());

        // 3. Gán danh hiệu vào map
        for(int i = 0; i < n; i++) {
            if (i == 0)      mp[sorted_score[i]] = "Gold Medal";
            else if (i == 1) mp[sorted_score[i]] = "Silver Medal";
            else if (i == 2) mp[sorted_score[i]] = "Bronze Medal";
            else             mp[sorted_score[i]] = to_string(i + 1);
        }

        vector<string> result(n);
        for(int i = 0; i < n; i++) {
            result[i] = mp[score[i]];
        }

        return result;
    }
};