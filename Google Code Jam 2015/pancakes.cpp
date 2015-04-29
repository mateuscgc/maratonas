#include <bits/stdc++.h>

using namespace std;

int main() {
    int nT;
    cin >> nT;
    for (int i = 1; i <= nT; i++) {
        int nD;
        cin >> nD;
        int nP[1001] = {0};
        int num;
        int max = -1;
        for(int j = 0; j < nD; j++) {
            cin >> num;
            nP[num]++;
            if (num > max)
                max = num;    
        }
        int min = max+1;
        for (int j = 1; j <= max; j++) {
            int nM = 0; 
            int cp[max+1];
            copy(nP, nP+max+1, cp);

            for (int k = max; k > j; k--) {
                if (cp[k] > 0) {
                    int ini = 2, end = k;
                    while(ini < end) {
                        int center = (ini+end)/2;
                        if ((k+center-1)/center <= j)
                            end = center;
                        else
                            ini = center+1;                    
                    }
                    cp[(k+ini-1)/ini] = k % ini * cp[k];
                    cp[k/ini] = (ini - k % ini) * cp[k];
                    nM += (ini-1)*cp[k]; 
                }
            }
            nM += j;
            if (nM < min)
                min = nM;
        }
        cout << "Case #" << i << ": " << min << endl;
    }

    return 0;
}
