class Solution {
public:
    int mySqrt(int x) {
        if (!x) return 0;
        int r = x, l = 1, ans = -1;
        while (l <= r) {
            int temp = (r - l)/2 + l;
            if (x/temp >= temp) {
                l = temp+1;
                ans = temp;
            }
            else r = temp-1;
        }
        return ans;
    }
};