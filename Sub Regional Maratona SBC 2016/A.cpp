#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ll a, b, c;
    cin >> a >> b >> c;
    if (a+b== c || a+c==b || b+c==a || a==b || a==c || b==c) cout << "S\n";
    else cout << "N\n";

    return 0;
}
