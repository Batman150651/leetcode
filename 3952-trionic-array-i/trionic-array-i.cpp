class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        if(nums.size()<=3) return false;
        int i = 1;
        while(i<nums.size() && nums[i]>nums[i-1]){
            i++;
        }
        if(i>nums.size()-2 || i==1 || nums[i]==nums[i-1]) return false;
        while(i<nums.size() && nums[i]<nums[i-1]){
            i++;
        }
        if(i>nums.size()-1 || nums[i]==nums[i-1]) return false;
        while(i<nums.size() && nums[i]>nums[i-1]){
            i++;
        }
        if(i<nums.size()) return false;
        return true;
    }
};