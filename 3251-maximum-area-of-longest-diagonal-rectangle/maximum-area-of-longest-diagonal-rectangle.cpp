class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = INT_MIN, maxLength = INT_MIN;
        for(int i=0;i<dimensions.size();i++){
            int lenSquare = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1];
            if(lenSquare>maxLength){
                maxLength = lenSquare;
                maxArea = dimensions[i][0]*dimensions[i][1];
            }
            else if(lenSquare == maxLength){
                maxArea = max(maxArea,dimensions[i][0]*dimensions[i][1]);
            }
        }
        return maxArea;
    }
};