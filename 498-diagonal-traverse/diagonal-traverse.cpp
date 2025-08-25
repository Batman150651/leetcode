class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i =0,j = 0;
        int d = 1;
        vector<int> res;
        while(i!=mat.size()-1 || j!=mat[0].size()-1){
            if(d==1){
                while(i>=0 && j<mat[0].size()){
                    res.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                i++;
                j--;
                d=0;
                if(j!=mat[0].size()-1) j++;
                else i++;
            }
            else{
                while(j>=0 && i<mat.size()){
                    res.push_back(mat[i][j]);
                    i++;
                    j--;
                }
                i--;
                j++;
                d=1;
                if(i!=mat.size()-1) i++;
                else j++;
            }
        }
        res.push_back(mat[i][j]);
        return res;
    }
};