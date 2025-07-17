#include <iostream>
#include <set>
using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        set<char> digits(x.begin(), x.end());
        for (int y = 0; y <= 9; y++) {
            char c = y + '0';
            if (digits.count(c)) {
                cout << c << endl;
                break;
            }
        }
    }
}

int main() {
    solve();
    return 0;
}
