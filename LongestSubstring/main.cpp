class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> charSet;
        int maxLength = 0;
        int right = 0;

        for (int left = 0; left < s.size(); ++left) {
            while (right <= s.size()) {
                if (right == s.size() || charSet.find(s[right]) != charSet.end()) {
                    if (right - left > maxLength) {
                        maxLength = right - left;
                    }
                    charSet.erase(s[left]);
                    break ;
                }
                charSet.insert(s[right++]);
            }
        }
        return maxLength;
    }
};