#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    ll n, q, x, y, z, sum = 0;
    cin >> n >> q;

    vector<vector<ll>> mp_x(n, vector<ll>(n, 0));
    vector<vector<ll>> mp_y(n, vector<ll>(n, 0));
    vector<vector<ll>> mp_z(n, vector<ll>(n, 0));

    for (int i = 0; i < q; i++) {
        cin >> x >> y >> z;

        if (++mp_x[y][z] == n) sum++;
        if (++mp_y[x][z] == n) sum++;
        if (++mp_z[x][y] == n) sum++;

        cout << sum << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
