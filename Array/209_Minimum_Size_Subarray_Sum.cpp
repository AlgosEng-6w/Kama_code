class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT32_MAX, ans = nums[nums.size()-1];
        for (int i = nums.size()-1, j = i; i >= j; i--) {
            while (ans < target && j > 0) {
                ans += nums[--j];
            }
            if (ans < target) break;
            len = len > i-j+1 ? i-j+1 : len;
            ans -= nums[i];
        }
        return (len == INT32_MAX) ? 0 : len;
    }
};