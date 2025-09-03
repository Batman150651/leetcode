class Solution {
public:
    static bool cmp(vector<int>& p1, vector<int>& p2) {
        return (p1[0] == p2[0]) ? p1[1] < p2[1] : p1[0] > p2[0];
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ans = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            int y = INT_MAX;
            for (int j = i + 1; j < points.size(); j++) {
                if (points[j][1] >= points[i][1] && y > points[j][1]) {
                    ans++;
                    y = points[j][1];
                }
            }
        }
        return ans;
    }
};