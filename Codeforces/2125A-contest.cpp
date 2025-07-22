#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void solve() {

  string s;
  cin >> s;
  while (s.find("FFT") != string::npos || s.find("NTT") != string::npos) {
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'F' && s[i + 1] == 'F' && s[i + 2] == 'T') {
        swap(s[i + 1], s[i + 2]);
      } else if (s[i] == 'N' && s[i + 1] == 'T' && s[i + 2] == 'T') {
        swap(s[i], s[i + 1]);
      }
    }
  }
  cout << s << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
