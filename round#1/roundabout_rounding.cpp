#include <bits/stdc++.h>
using namespace std;

#define ll long long
void solve(){
    ll n, sum = 0, a = 5, c = 10, b = 5;
    cin >> n;

    while(n >= a) { 
        sum = sum + abs(min(b, n + 1) - min(a, n + 1));
        a = a + 4 * c; 
        c = c * 10;
        b = b * 10;
    }
    cout << sum << endl; 
}

int main() {
    int t;
    cin>>t;
    while(t--) solve();
}
