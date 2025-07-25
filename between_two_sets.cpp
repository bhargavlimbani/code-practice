#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to compute GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Helper function to compute LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int getTotalX(vector<int> a, vector<int> b) {
    // Find LCM of all elements in array a
    int lcm_a = a[0];
    for (int i = 1; i < a.size(); i++) {
        lcm_a = lcm(lcm_a, a[i]);
    }

    // Find GCD of all elements in array b
    int gcd_b = b[0];
    for (int i = 1; i < b.size(); i++) {
        gcd_b = gcd(gcd_b, b[i]);
    }

    // Count how many multiples of lcm_a evenly divide gcd_b
    int count = 0;
    for (int x = lcm_a; x <= gcd_b; x += lcm_a) {
        if (gcd_b % x == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    int result = getTotalX(a, b);
    cout << result << endl;

    return 0;
}
