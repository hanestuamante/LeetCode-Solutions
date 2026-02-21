class Solution {
public:
    bool canMakeThreeSections(vector<pair<int, int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    int count = 0; 
    int maxEndSoFar = intervals[0].second;

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].first >= maxEndSoFar) {
            count++;
        }
        
        maxEndSoFar = max(maxEndSoFar, intervals[i].second);
        
        if (count >= 2) return true;
    }

    return false;
}

    bool check(vector<vector<int>>& rectangles, bool isHorizontal) {
        vector<pair<int, int>> intervals;
        
        for (const auto& r : rectangles) {
            if (isHorizontal) {
                intervals.push_back({r[1], r[3]});
            } else {
                intervals.push_back({r[0], r[2]});
            }
        }
        
        return canMakeThreeSections(intervals);
    }

    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        return check(rectangles, true) || check(rectangles, false);
    }
};
