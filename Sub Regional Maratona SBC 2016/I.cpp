#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int n;
    cin >> n;
    int wall[n+1];
    for(int i = 1; i <= n; i++) {
        cin >> wall[i];
        if(i <= (n+1)/2)
            wall[i] = min(wall[i], i);
        else
            wall[i] = min(wall[i], n - i + 1);
    }

    int mudou =0;
    for(int k = 1; k <= n; k++) {
        mudou =0;
        for(int i = 2; i < n; i++) {
            int aux = wall[i];
            wall[i] = min(wall[i], min(wall[i-1], wall[i+1]) + 1);
            if(wall[i] != aux)
                mudou=1;
        }
        if(!mudou)
            break;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans,wall[i]);
    }
    cout << ans << "\n";

    return 0;
}
