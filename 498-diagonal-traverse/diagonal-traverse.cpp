class Solution {
public:
     vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i = 0, j = 0;
        int d = 1;
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        int index = 0;
        while (index < m * n) {
            res.push_back(mat[i][j]);
            index++;
            if (d == 1) {
                if (j == n-1) {
                    i++;
                    d = 0;
                } else if (i == 0) {
                    j++;
                    d = 0;
                } else {
                    i--;
                    j++;
                }
            } else {
                if (i == m - 1) {
                    j++;
                    d=1;
                } else if (j == 0) {
                    i++;
                    d=1;
                } else {
                    i++;
                    j--;
                }
            }
        }
        return res;
    }
};