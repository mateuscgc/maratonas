#include <bits/stdc++.h>

using namespace std;

int named[10];

void update(long long num) {
    while(num != 0) {
        named[num%10] = 1;
        num /= 10;
    }
}

int all() {
    int sum = 0;
    for(int i = 0; i < 10; i++) {
        sum += named[i];
    }
    return sum;
}

int main() {

    int t;
    cin >> t;

    for(int i = 1; i <= t; i++) {
        memset(named, 0, sizeof(named));
        long long n;
        cin >> n;
        if(n == 0) {
            cout << "Case #" << i << ": INSOMNIA" << endl;
            continue;
        }
        long long num = 0;
        while(all() < 10) {
            num += n;
            update(num);
        }
        cout << "Case #" << i << ": " << num << endl;
    }

    return 0;
}
