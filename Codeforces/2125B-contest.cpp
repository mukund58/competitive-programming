#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

struct State {
    ll x, y;
    set<pii> used;

    bool operator<(const State &other) const {
        return tie(x, y, used) < tie(other.x, other.y, other.used);
    }
};

int bfs(ll a, ll b, ll k) {
    queue<State> q;
    set<State> visited;

    State start = {a, b, {}};
    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        auto [x, y, used] = q.front();
        q.pop();

        if (x == 0 && y == 0) {
            return (int)used.size();  // Reached goal
        }

        for (ll dx = 0; dx <= k; dx++) {
            for (ll dy = 0; dy <= k; dy++) {
                if (dx == 0 && dy == 0) continue;

                ll nx = x - dx;
                ll ny = y - dy;

                if (nx < 0 || ny < 0) continue;

                set<pii> new_used = used;
                new_used.insert({dx, dy});

                State next = {nx, ny, new_used};

                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
    }

    return -1; // Should never reach here
}

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;

    ll g = gcd(a, b);
    ll dx = a / g, dy = b / g;
    if (dx <= k && dy <= k) {
        cout << 1 << '\n';
        return;
    }

    cout << bfs(a, b, k) << '\n';
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
