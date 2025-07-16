#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;

        cin >> n;


        int firstDigit = n / (int)pow(10, (int)log10(n)); // First digit extraction

        int count = (int)log10(n) + 1; // Number of digits


        int ans = (9 * (count - 1) + firstDigit) ;

        cout<<ans<<endl;

        

    }

}
