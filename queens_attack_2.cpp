#include <bits/stdc++.h>
using namespace std;

/*
 * Complete the 'queensAttack' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER r_q
 *  4. INTEGER c_q
 *  5. 2D_INTEGER_ARRAY obstacles
 */

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // Use a set to store obstacles for O(1) lookup
    set<pair<int,int>> obs;
    for (auto &o : obstacles) {
        obs.insert({o[0], o[1]});
    }

    int count = 0;

    // Directions: N, NE, E, SE, S, SW, W, NW
    int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

    for (int d = 0; d < 8; d++) {
        int r = r_q + dr[d];
        int c = c_q + dc[d];

        while (r >= 1 && r <= n && c >= 1 && c <= n && obs.find({r,c}) == obs.end()) {
            count++;
            r += dr[d];
            c += dc[d];
        }
    }

    return count;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int r_q, c_q;
    cin >> r_q >> c_q;

    vector<vector<int>> obstacles(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> obstacles[i][0] >> obstacles[i][1];
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);
    cout << result << "\n";

    return 0;
}
