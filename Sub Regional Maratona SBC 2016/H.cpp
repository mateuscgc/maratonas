#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    string ris;
    char res[51];
    cin >> ris;
    ll pos=0;
    for (ll i=0; i<ris.size(); i++)
        if (ris[i]=='a' || ris[i]=='e' || ris[i]=='i' || ris[i]=='o' || ris[i]=='u'){
            res[pos]=ris[i];
            pos++;
        }
    res[pos] = 0;
    if(pos == 0) {
        cout << "N\n";
        return 0;
    }

    ll f=1;
    for (ll i=0; i<pos/2; i++)
    {
        if (res[i]!=res[pos-1-i]) f=0;
    }
    if (f) cout << "S\n";
    else cout << "N\n";
    return 0;
}
