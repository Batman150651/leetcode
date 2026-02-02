class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int cnt = 1;
        int left = 0, top = 0, right = n-1, bottom = n-1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                res[top][i]=cnt;
                cnt++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                res[i][right]=cnt;
                cnt++;
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    res[bottom][i]=cnt;
                    cnt++;
                }
                bottom--;
                  
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    res[i][left]=cnt;
                    cnt++;
                }
                left++;
            }
        }
        return res;
    }
};