class Solution {
public:
    string minWindow(string s, string t) {
        int diff[128]{};
        int kinds = 0;
        for (char c : t) {
            if (diff[c] == 0) kinds++;
            diff[c]--;
        }

        int m = s.size();
        int ans_left = -1, ans_right = m;
        int ge_cnt = 0, left = 0;

        for (int right = 0; right < m; right++) {
            char c = s[right];
            diff[c]++;
            if (diff[c] == 0) ge_cnt++;

            while (ge_cnt == kinds) {
                if (right - left < ans_right - ans_left) {
                    ans_left = left;
                    ans_right = right;
                }

                char x = s[left];
                if (diff[x] == 0) ge_cnt--;
                diff[x]--;
                left++;
            }
        }

        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }
};