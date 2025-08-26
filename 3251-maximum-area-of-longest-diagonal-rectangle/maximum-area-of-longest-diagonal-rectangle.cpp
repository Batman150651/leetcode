class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = INT_MIN; double maxLength = INT_MIN;
        for(int i=0;i<dimensions.size();i++){
            int lenSquare = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1];
            double length = sqrt(lenSquare);
            if(length>maxLength){
                maxLength = length;
                maxArea = dimensions[i][0]*dimensions[i][1];
            }
            else if(length == maxLength){
                maxArea = max(maxArea,dimensions[i][0]*dimensions[i][1]);
            }
        }
        return maxArea;
    }
};