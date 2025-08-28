class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            vector<int> res;
            int j = i, k = 0;
            while (j < n) {
                res.push_back(grid[j][k]);
                j++;
                k++;
            }
            sort(res.begin(), res.end(), greater<int>());
            j = i, k = 0;
            int idx = 0;
            while (j < n) {
                grid[j][k] = res[idx++];
                j++;
                k++;
            }
        }
        for (int i = 1; i < n; i++) {
            vector<int> res;
            int j = 0, k = i;
            while (k < n) {
                res.push_back(grid[j][k]);
                j++;
                k++;
            }
            sort(res.begin(), res.end());
            j = 0, k = i;
            int idx = 0;
            while (k < n) {
                grid[j][k] = res[idx++];
                j++;
                k++;
            }
        }
        return grid;
    }
};