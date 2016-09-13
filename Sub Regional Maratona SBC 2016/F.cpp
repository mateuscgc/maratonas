#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define F first
#define S second

int main() {
    int nE;
    cin >> nE;

    int centE[nE+1];
    memset(centE, 0, sizeof centE);
    for(int i = 0; i < nE; i++) {
        int ind, esq,cen;
        cin >> ind >> esq >> cen;
        centE[ind] = cen;
    }

    int nD;
    cin >> nD;

    int centD[nD+1];
    memset(centD, 0, sizeof centD);
    for(int i = 0; i < nD; i++) {
        int ind, esq,cen;
        cin >> ind >> cen >> esq;
        centD[ind] = cen;
    }

    int visE[nE+1];
    memset(visE, 0, sizeof visE);

    int mE = 0;
    int mrE;
    for(int i = 1; i <= nE; i++) {
        if(!visE[i]) {
            int cmE = 0;
            int cur = i;
            visE[cur] = 1;
            while(centE[cur] != 0) {
                cur = centE[cur];
                cmE++;
                visE[cur] = 1;
            }
            mE = max(mE, cmE);
            if(i == 1) mrE = cmE;
        }

    }

    int visD[nD+1];
    memset(visD, 0, sizeof visD);

    int mD = 0;
    int mrD;
    for(int i = 1; i <= nD; i++) {
        if(!visD[i]) {
            int cmD = 0;
            int cur = i;
            visD[cur] = 1;
            while(centD[cur] != 0) {
                cur = centD[cur];
                cmD++;
                visD[cur] = 1;
            }
            mD = max(mD, cmD);
            if(i == 1) mrD = cmD;
        }

    }

    int ans = max(min(mrE, mD), min(mrD, mE));
    cout << nE + nD - ans - 1 << "\n";


    return 0;
}
