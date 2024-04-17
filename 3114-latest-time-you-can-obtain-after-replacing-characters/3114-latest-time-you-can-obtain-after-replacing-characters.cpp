class Solution {
private:
    enum Index {
        HOUR_LEFT = 0,
        HOUR_RIGHT,
        SEPARATOR,
        MINUTE_LEFT,
        MINUTE_RIGHT
    };

public:
    string findLatestTime(string s) {
        if (s[MINUTE_RIGHT] == '?') {
            s[MINUTE_RIGHT] = '9';
        }
        if (s[MINUTE_LEFT] == '?') {
            s[MINUTE_LEFT] = '5';
        }
        if (s[HOUR_RIGHT] == '?' && s[HOUR_LEFT] == '?') {
            s[HOUR_RIGHT] = '1';
            s[HOUR_LEFT] = '1';
        } else {
            if (s[HOUR_RIGHT] == '?') {
                s[HOUR_RIGHT] = s[HOUR_LEFT] == '1' ? '1' : '9';
            }
            if (s[HOUR_LEFT] == '?') {
                s[HOUR_LEFT] = s[HOUR_RIGHT] <= '1' ? '1' : '0';
            }
        }
        return s;
    }
};