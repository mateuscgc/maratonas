#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {

    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll min_a = c+1;
    for(ll i = 1; i <= sqrt(c); i++) {
        if(c%i == 0) {
            if(i%a == 0 && i%b != 0 && d%i != 0) min_a = min(min_a, i);
            ll aux = c/i;
            if(aux%a == 0 && aux%b != 0 && d%aux != 0) min_a = min(min_a, aux);
        }
    }

    if(min_a > c)
        cout << "-1\n";
    else
        cout << min_a << "\n";

    return 0;
}
