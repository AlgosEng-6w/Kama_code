class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, t_ptr = -1;
        while (l <= r){
            int temp = l + (r - l)/2;
            if (nums[temp] == target) {
                t_ptr = temp;
                break; 
            } else if (nums[temp] > target) r = temp-1;
            else l = temp+1;
        }
        if (t_ptr == -1) return {-1,-1};
        r = t_ptr; l = r;
        while (r < nums.size() && nums[r] == target) r++;
        while (l > -1 && nums[l] == target) l--;
        return {++l, --r};
    }
};