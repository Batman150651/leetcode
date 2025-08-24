class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int start = 0, zeros = 0, maxLength = 0;

        for (int end = 0; end < nums.size(); end++) {
            if (nums[end] == 0)
                zeros++;
            while (zeros > 1) { 
                if (nums[start] == 0)
                    zeros--;
                start++;
            }
            maxLength = max(maxLength, end - start);
        }

        return maxLength;
    }
};