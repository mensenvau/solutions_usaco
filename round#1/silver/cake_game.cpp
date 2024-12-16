#include <iostream>
#include <vector>
#include <deque>
using namespace std;

pair<long long, long long> solve_test_case(int n, vector<int>& cakes) {
    deque<int> dq(cakes.begin(), cakes.end());
    long long bessie_total = 0, elsie_total = 0;

    while (dq.size() > 1) {
        // Elsie's turn: pick the larger of the two ends
        if (dq.front() >= dq.back()) {
            elsie_total += dq.front();
            dq.pop_front();
        } else {
            elsie_total += dq.back();
            dq.pop_back();
        }

        // Bessie's turn: stack the two largest adjacent cakes
        if (dq.size() > 1) {
            int max_sum_index = 0;
            int max_sum = dq[0] + dq[1];
            for (int i = 1; i < dq.size() - 1; ++i) {
                if (dq[i] + dq[i + 1] > max_sum) {
                    max_sum = dq[i] + dq[i + 1];
                    max_sum_index = i;
                }
            }
            dq[max_sum_index] += dq[max_sum_index + 1];
            dq.erase(dq.begin() + max_sum_index + 1);
        }
    }

    // Bessie gets the last remaining cake
    if (!dq.empty()) {
        bessie_total += dq.front();
    }

    return {bessie_total, elsie_total};
}

int main() {
    int t;
    cin >> t;
    vector<pair<long long, long long>> results;

    while (t--) {
        int n;
        cin >> n;
        vector<int> cakes(n);
        for (int i = 0; i < n; ++i) {
            cin >> cakes[i];
        }

        results.push_back(solve_test_case(n, cakes));
    }

    for (auto& result : results) {
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
