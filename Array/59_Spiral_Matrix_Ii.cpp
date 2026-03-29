class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans (n, vector<int>(n,0));
        int hoop = n/2;
        int len = n-1;
        int count = 1;
        int start = 0;
        while (hoop--) {
            int i = start;
            int j = start;
            for (; j < start + len; j++) {
                ans[i][j] = count++;
            }
            for (; i < start + len; i++) {
                ans[i][j] = count++;
            }
            for (; j > start; j--) {
                ans[i][j] = count++;
            }
            for (; i > start; i--) {
                ans[i][j] = count++;
            }
            len -= 2;
            start++;
        }
        if (n%2) ans[n/2][n/2] = count;
        return ans;
    }
};