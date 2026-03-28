class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>diff(128,0);
        int count = 0, ans_left = 0, ans_right = s.size();
        for (int i = 0; i < t.size(); i++) {
            if (diff[t[i]]-- == 0) count++;
        }
        for (int right = 0, left = 0; right < s.size(); right++) {
            if (++diff[s[right]] == 0) {
                count--;
            }

            while (count == 0) {
                if (ans_right - ans_left > right - left) {
                    ans_right = right;
                    ans_left = left;
                }

                if (diff[s[left]]-- == 0) count++;
                left++;
            }
            
        }
        if (ans_right == s.size()) return "";
        return s.substr(ans_left, ans_right-ans_left+1);
    }
};