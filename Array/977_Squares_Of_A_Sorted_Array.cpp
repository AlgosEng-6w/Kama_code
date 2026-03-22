class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }
        vector<int>ans(nums.size());
        int i = 0, j = nums.size()-1;
        for (int index = j; i <= j;) {
            if (nums[i] > nums[j]) ans[index--] = nums[i++];
            else ans[index--] = nums[j--];
        }
        return ans;
    }
};