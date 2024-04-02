class Solution {
public:
    bool isIsomorphic(string s, string t) {
        const int len = s.length();
        unordered_map<char,char> smapper;
        unordered_map<char,char> tmapper;
        for (int index = 0; index < len; index++) {
            if (!smapper.count(s[index])) {
                smapper[s[index]] = t[index];
            }
            if (!tmapper.count(t[index])) {
                tmapper[t[index]] = s[index];
            }
            if (smapper[s[index]] != t[index] || tmapper[t[index]] != s[index]) {
                return false;
            }
        }
        return true;
    }
};