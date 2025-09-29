#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();

    string topic[n];

    // Read input topics
    for (int i = 0; i < n; i++) {
        getline(cin, topic[i]);
    }

    int maxTopics = 0;
    int teamCount = 0;

    // Compare all pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int known = 0;
            for (int k = 0; k < m; k++) {
                if (topic[i][k] == '1' || topic[j][k] == '1') known++;
            }
            if (known > maxTopics) {
                maxTopics = known;
                teamCount = 1;
            } else if (known == maxTopics) {
                teamCount++;
            }
        }
    }

    cout << maxTopics << "\n" << teamCount << "\n";

    return 0;
}
