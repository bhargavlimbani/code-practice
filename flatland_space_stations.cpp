#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum distance to nearest space station
int main() {
    int n, m;
    cin >> n >> m;

    int stations[m];
    for (int i = 0; i < m; i++)
        cin >> stations[i];

    sort(stations, stations + m); // Sort the station positions

    int maxDist = 0;

    // Distance before the first station
    if (stations[0] != 0)
        maxDist = stations[0];

    // Distance after the last station
    if (stations[m - 1] != n - 1)
        maxDist = max(maxDist, n - 1 - stations[m - 1]);

    // Distance between consecutive stations
    for (int i = 1; i < m; i++) {
        int dist = (stations[i] - stations[i - 1]) / 2;
        if (dist > maxDist)
            maxDist = dist;
    }

    cout << maxDist << "\n";

    return 0;
}
