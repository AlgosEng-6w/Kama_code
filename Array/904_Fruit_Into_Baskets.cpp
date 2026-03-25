class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size(), len = 0;
        if (n < 3) return n;
        unordered_map<int, int> count;
        for (int right = 0, left = 0; right < n; ++right) {
            count[fruits[right]]++;
            while (count.size() > 2) {
                count[fruits[left]]--;
                if (!count[fruits[left]]) {
                    count.erase(fruits[left]);
                }
                left++;
            }
            len = max(len, right - left + 1);
        }
        return len;
    }
};



class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int size = fruits.size();
        if (size < 3) return size;
        int last = 0;
        while (last < size-1 && fruits[last] == fruits[0]) last++;
        int len = last + 1;
        for (int a, b; last < size-1; last++) {
            int first = last - 1;
            a = fruits[first], b = fruits[last];
            while (first > 0 && (fruits[first - 1] == a || fruits[first - 1] == b)) --first;
            while (last < size-1 && (fruits[last + 1] == a || fruits[last + 1] == b)) ++last;
            len = len < last - first + 1 ? last - first + 1 : len;
        }
        return len;
    }
};