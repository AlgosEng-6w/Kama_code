class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int s_num = solve(s);
        int t_num = solve(t);
        if (s_num != t_num) return false;
        while (s_num--) {
            if (s[s_num] != t[s_num]) return false;
        } return true;
    }
    int solve(string& s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] == '#') slow = slow == 0 ? 0 : slow-1;
            else s[slow++] = s[fast];
        }
        return slow;
    }
};