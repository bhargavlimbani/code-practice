#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Since constraints are small, using map is fine
    unordered_map<int, int> freq;
    int maxFreq = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
        if (freq[x] > maxFreq) maxFreq = freq[x];
    }

    // Minimum deletions = total elements - count of most frequent element
    cout << n - maxFreq << "\n";

    return 0;
}
