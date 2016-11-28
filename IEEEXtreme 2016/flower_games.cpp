#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long  joseph(long long N, long long k) {
    if(N==1) {
        return 1;
    }
    if(N%2 == 0) {
        if(k == 1) {
            return 2*joseph(N/2, 1);
        } else {
            return 2*joseph(N/2, 2) - 1;
        }
    } else {
        if(k == 1) {
            return 2*joseph(N/2, 2);
        } else {
            return 2*joseph(N/2+1, 1) - 1;
        }
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    
    int t; cin >> t;
    while(t--) {
        long long n; cin >> n;
        //long long m = log2(n);
        //long long o = pow(2,m);
        //long long ans = 2*(n-o) + 1;
        //cout << ans << endl;
        
        //cout << 1LL + 2LL*(n - (1LL << (long long)log2(n))) << endl;
        
        cout << joseph(n, 2) << endl;
        
        
    }
    
    return 0;
}
