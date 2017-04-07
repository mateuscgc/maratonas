#include <bits/stdc++.h>

using namespace std;

long long binary(int dec) {
    long long ans = 0;
    stack<int> s;
    while(dec / 2 != 0) {
        s.push(dec % 2);
        dec /= 2;
    }
    s.push(dec);
    while(!s.empty()) {
        ans *= 10;
        ans += s.top(); s.pop();
    }
    return ans;
}

long long decimal(long long num, int base) {
    if(base == 10)
        return num;
    long long ans = 0;
    long long aux = 1;
    while(num != 0) {
        int dig = num % 10;
        ans += dig*aux;
        aux *= base;
        num /= 10;
    }
    return ans;
}

long long divisor(long long num) {
    long long sr = sqrt(num);
    for(long long i = 2; i <= sr; i++) {
        if(num % i == 0)
            return i;
    }
    return 0;
}

int main() {

    int t;
    cin >> t;

    int n, j;
    cin >> n >> j;

    int num = (1 << n-1) -1;
    // cout << num << endl;

    cout << "Case #1:" << endl;
    int count = 0;
    while (count < j) {
        num += 2;
        long long bin = binary(num);

        vector<long long> divs;
        for(int i = 2; i <= 10; i++) {
            // cout << decimal(bin, i) << endl;
            long long aux = divisor(decimal(bin, i));
            if(!aux)
                break;
            divs.push_back(aux);
        }

        if(divs.size() == 9) {
            cout << bin;
            for(int i = 0; i < 9; i++) {
                cout << " " << divs[i];
            }
            cout << endl;
            count++;
        }
    }

    return 0;
}
