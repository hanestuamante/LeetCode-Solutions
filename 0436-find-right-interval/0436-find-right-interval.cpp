
using namespace std;

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<int> result(n);
    
        map<int, int> startMap;
        
        for (int i = 0; i < n; ++i) {
            startMap[intervals[i][0]] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            int endVal = intervals[i][1];
            auto it = startMap.lower_bound(endVal);
            
            if (it != startMap.end()) {
                result[i] = it->second;
            } else {
                result[i] = -1;
            }
        }
        
        return result;
    }
};