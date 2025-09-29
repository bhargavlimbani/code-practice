#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'howManyGames' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER d
 *  3. INTEGER m
 *  4. INTEGER s
 */

int howManyGames(int p, int d, int m, int s) {
    int count = 0;
    int price = p;

    while (s >= price) {
        s -= price;
        count++;
        price -= d;
        if (price < m) price = m; // price cannot go below minimum
    }

    return count;
}

int main() {
    int p, d, m, s;
    cin >> p >> d >> m >> s;

    int answer = howManyGames(p, d, m, s);
    cout << answer << "\n";

    return 0;
}
