#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool is_moo(char s1, char s2, char s3) {
    return (s2 == s3 && s1 != s2);
}

bool is_moo(char s1, char s2, char s3, string s) {
    return (((s[0] == s1) + (s[1] == s2) + (s[2] == s3)) == 2);
}

void solve(){
    int n, f;
    string s;
    unordered_map<string, int> mp;
    unordered_map<string, set<int>> st;

    set<string> res;

    cin >> n >> f;
    cin >> s;

    if (f == 1) {
        for (int i = 0; i < n - 2; i++) {
            string original = s.substr(i, 3);
            if (is_moo(original[0], original[1], original[2])) {
                res.insert(original);
            }
            for (int j = 0; j < 3; j++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (original[j] == c) continue; 
                    string modified = original;
                    modified[j] = c;
                    if (is_moo(modified[0], modified[1], modified[2])) {
                        res.insert(modified);
                    }
                }
            }
        }
    } else {
        for (int i = 0; i < n - 2; i++) {
            if (is_moo(s[i], s[i + 1], s[i + 2])) {
                string d = string() + s[i] + s[i + 1] + s[i + 2];
                mp[d]++;
                st[d].insert({ i, i + 1, i + 2});
            }
        }

        for (const auto &x : mp) {
            if(x.second >= f) {
                res.insert(x.first);
            } else if(x.second + 1 == f) {
                for (int i = 0; i < n - 2; i++) {
                    if (is_moo(s[i], s[i + 1], s[i + 2], x.first) && !st[x.first].count(i) && !st[x.first].count(i + 1) && !st[x.first].count(i + 2)) {
                    string d = string() + s[i] + s[i + 1] + s[i + 2];
                    res.insert(x.first);
                    }
                }
            }
        }
    }

    cout << res.size() << endl;
    for (const auto &x : res) {
      cout << x << endl; 
    }
}

int main() {
    solve();
}
