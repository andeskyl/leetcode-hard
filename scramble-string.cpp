class Solution {
public:
    unordered_map<string, bool> isScramble_res;
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (isScramble_res.find(s1 + '/' + s2) != isScramble_res.end())
            return isScramble_res[s1 + '/' + s2];
        int count[26] = {0}, len = s1.length();
        for (int i = 0; i < len; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) 
            if (count[i] != 0) return (isScramble_res[s1 + '/' + s2] = false);
        for (int i = 1; i < len; i++) {
            if ((isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) 
                || (isScramble(s1.substr(0, len - i), s2.substr(i)) && isScramble(s1.substr(len - i), s2.substr(0, i))))
                return true;
        }
        return (isScramble_res[s1 + '/' + s2] = false);
    }
};