#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int T; 
    cin >> T;

    while (T--) {
        int N; 
        cin >> N;

        vector<int> cakes(N);
        vector<vector<long long>> dp(N, vector<long long>(N, 0));
        vector<long long> prefix_sum(N + 1, 0);

        for (int i = 0; i < N; ++i) {
            cin >> cakes[i];
            prefix_sum[i + 1] = prefix_sum[i] + cakes[i];
        }

        for (int length = 1; length <= N; ++length) {
            for (int i = 0; i + length - 1 < N; ++i) {
                int j = i + length - 1;
                if (i == j) {
                    dp[i][j] = cakes[i];
                } else {
                    long long left = cakes[i] + (prefix_sum[j + 1] - prefix_sum[i + 1] - dp[i + 1][j]);
                    long long right = cakes[j] + (prefix_sum[j] - prefix_sum[i] - dp[i][j - 1]);
                    dp[i][j] = max(left, right);
                }
            }
        }

        long long bessie = dp[0][N - 1];
        long long total = prefix_sum[N];
        long long elsie = total - bessie; 

        cout << bessie << " " << elsie << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
