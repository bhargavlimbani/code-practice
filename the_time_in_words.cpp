#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m) {
    string numbers[] = { "", "one", "two", "three", "four", "five", "six", "seven",
                         "eight", "nine", "ten", "eleven", "twelve", "thirteen",
                         "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                         "nineteen", "twenty", "twenty one", "twenty two", "twenty three",
                         "twenty four", "twenty five", "twenty six", "twenty seven",
                         "twenty eight", "twenty nine" };

    if (m == 0) {
        return numbers[h] + " o' clock";
    } else if (m == 15) {
        return "quarter past " + numbers[h];
    } else if (m == 30) {
        return "half past " + numbers[h];
    } else if (m == 45) {
        int nextHour = h == 12 ? 1 : h + 1;
        return "quarter to " + numbers[nextHour];
    } else if (m < 30) {
        string minuteStr = m == 1 ? " minute" : " minutes";
        return numbers[m] + minuteStr + " past " + numbers[h];
    } else {
        int nextHour = h == 12 ? 1 : h + 1;
        int remaining = 60 - m;
        string minuteStr = remaining == 1 ? " minute" : " minutes";
        return numbers[remaining] + minuteStr + " to " + numbers[nextHour];
    }
}

int main() {
    int h, m;
    cin >> h >> m;

    string result = timeInWords(h, m);
    cout << result << "\n";

    return 0;
}
