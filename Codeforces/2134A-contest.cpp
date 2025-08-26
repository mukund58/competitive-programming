#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, a, b;
    cin >> n >> a >> b;

    if ((n - b) % 2 == 0 && (a <= b || (a - b) % 2 == 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

