class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int left = 1, right = num/2;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (num / mid == mid) {
                if (num % mid == 0) return true;
                else return false;
            } else if (mid > num / mid) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};