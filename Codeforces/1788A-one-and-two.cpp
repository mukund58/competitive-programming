#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int total_twos = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 2) {
                total_twos++;
            }
        }

        int prefix_twos = 0;
        bool found = false;
        for (int k = 1; k < n; k++) {
            if (a[k - 1] == 2) {
                prefix_twos++;
            }
            int suffix_twos = total_twos - prefix_twos;
            if (prefix_twos == suffix_twos) {
                cout << k << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << -1 << endl;
        }
    }
    return 0;
}

