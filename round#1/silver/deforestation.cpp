#include <bits/stdc++.h> 
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<ll> x(N);
        for (int i = 0; i < N; ++i) cin >> x[i];

        vector<tuple<ll, ll, ll>> restrictions(K);
        for (int i = 0; i < K; ++i) {
            ll li, ri, ti;
            cin >> li >> ri >> ti;
            restrictions[i] = {li, ri, ti};
        }

        sort(x.begin(), x.end());
        vector<bool> keep(N, false);

        for (auto [li, ri, ti] : restrictions) {
            vector<int> in_range;
            for (int i = 0; i < N; ++i) {
                if (x[i] >= li && x[i] <= ri) {
                    in_range.push_back(i);
                }
            }

            int already_kept = 0;
            for (int idx : in_range) {
                if (keep[idx]) already_kept++;
            }

            int need_to_keep = ti - already_kept;
            for (int idx : in_range) {
                if (need_to_keep <= 0) break;
                if (!keep[idx]) {
                    keep[idx] = true;
                    need_to_keep--;
                }
            }
        }

        int trees_cut = 0;
        for (bool k : keep) if (!k) trees_cut++;
        cout << trees_cut << '\n';
    }

    return 0;
}
