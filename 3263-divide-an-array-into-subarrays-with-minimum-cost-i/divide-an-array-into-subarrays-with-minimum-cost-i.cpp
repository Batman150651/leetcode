class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int minFirst = INT_MAX;
        int minSecond = INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(minFirst>=nums[i]){
                minSecond = minFirst;
                minFirst = nums[i];
            }
            if(nums[i]>minFirst && nums[i]<minSecond) minSecond = nums[i];
        }
        return nums[0]+minFirst+minSecond;
    }
};