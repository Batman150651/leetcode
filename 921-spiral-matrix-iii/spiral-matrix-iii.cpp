class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int fact = 1;
        int top = rStart;
        int bottom = rStart+1;
        int left = cStart;
        int right = cStart+1;
        res.push_back({rStart,cStart});
        while(res.size()<rows*cols){
            for(int k=left+1;k<=right;k++){
                if(top>=0 && k<cols && k>=0){  
                    res.push_back({top,k});
                }
            }
            left--;
            for(int k=top+1;k<=bottom;k++){
                if(right<cols && k<rows && k>=0){  
                    res.push_back({k,right});
                }
            }
            top--;
            for(int k=right-1;k>=left;k--){
                if(bottom<rows && k>=0 && k<cols){  
                    res.push_back({bottom,k});
                }
            }
            right++;
            for(int k=bottom-1;k>=top;k--){
                if(left>=0 && k>=0 && k<rows){  
                    res.push_back({k,left});
                }
            }
            bottom++;
        }  
        return res;
    }
};