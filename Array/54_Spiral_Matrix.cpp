class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>ans(m*n, 0);
        int loop = (m > n ? m : n)/2;
        int start = 0, count = 0;
        int len_x = m-1;
        int len_y = n-1;
        while (loop--) {
            int x = start;
            int y = start;
            for (;count != m*n && y < start + len_y; y++) {
                ans[count++] = matrix[x][y];
            }
            for (;count != m*n && x < start + len_x; x++) {
                ans[count++] = matrix[x][y];
            }
            for (;count != m*n && y > start; y--) {
                ans[count++] = matrix[x][y];
            }
            for (;count != m*n && x > start; x--) {
                ans[count++] = matrix[x][y];
            }
            start++;
            len_x-=2;
            len_y-=2;
        }
        if (m == n && m%2) {
            ans[count] = matrix[start][start];
        }
        return ans;
    }
};