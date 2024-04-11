class Solution {
private:
    string removeLeadingZeros(const string& s) {
        int index = 0;
        while (index < s.length() && s[index] == '0') {
            index++;
        }
        return index == s.length() ? "0" : s.substr(index);
    }
    
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for (const char& c: num) {
            while (!ans.empty() && k > 0 && ans.back() > c) {
                ans.pop_back();
                k--;
            }
            ans.push_back(c);
        }
        while (k > 0) {
            ans.pop_back();
            k--;
        }
        return removeLeadingZeros(ans);
    }
};
