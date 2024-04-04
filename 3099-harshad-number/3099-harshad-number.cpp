class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        for (int temp = x; temp > 0; temp /= 10) {
            sum += temp % 10;
        }
        return x % sum == 0 ? sum : -1;
    }
};