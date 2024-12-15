#include <bits/stdc++.h>
using namespace std;

bool is_10b(int n){
    if(n==0) return true;
    while(n%10==0) n = n/10;
    return (n == 1);
}

int find_b(int n) {
    if (n <= 1) return 1;
    return static_cast<int>(ceil(log10(n)));
}

int method_1(int n) {
    int b = 1;
    while(!is_10b(n)){
        int digit = -1, cn = n, powb = 1;
        for (int i = 0; i < b; ++i) {
            digit = cn % 10;
            cn /= 10;
            powb *= 10;
        }

        if (digit >= 5) n += powb; 
        n = (n / powb) * powb;
        b = b + 1;
        // cout << n << " " << b << " " << digit << " " << powb << endl;
    }
    return n;
}

int method_2(int n){
    int b = find_b(n);
    int digit = -1, cn = n, powb = 1;
    for (int i = 0; i < b; ++i) {
        digit = cn % 10;
        cn /= 10;
        powb *= 10;
    }

    if (digit >= 5) n += powb; 
    n = (n / powb) * powb;
    return n;
}

int main() { 
    for(int i = 1; i < 30000; i++){
        cout << i << " " << method_1(i) << " " << method_2(i) << endl;
    }
}
