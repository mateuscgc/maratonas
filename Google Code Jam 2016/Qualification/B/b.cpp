#include <bits/stdc++.h>

using namespace std;

string st;

int happy() {
    int len = st.size();
    for(int i = 0; i < len; i++) {
        if(st[i] == '-')
            return 0;
    }
    return 1;
}

int num_groups(int n) {
    int len = st.size();
    string aux = st;
    for(int i = 0; i <= n; i++) {
        aux[i] = st[n-i] == '+' ? '-' : '+';
    }
    // cout << aux << endl;
    int ans = 1;
    for(int i = 1; i < len; i++) {
        if(aux[i] != aux[i-1])
            ans++;
    }
    return ans;
}

int last(int n) {
    int len = st.size();
    if(n == len-1)
        return (st[0] == '-');
    return (st[len-1] == '+');
}

int best_move() {
    int len = st.size();

    int min = 101;
    int n = -1;
    for(int i = 0; i < len; i++) {
        int now = num_groups(i);
        // cout << now << endl;
        if (now < min || (now == min && last(i) < last(n))) {
            min = now;
            n = i;
        }
    }
    // cout << n << endl;
    return n;
}

int move(int n) {
    int len = st.size();
    string aux = st;
    for(int i = 0; i <= n; i++) {
        st[i] = aux[n-i] == '+' ? '-' : '+';
    }
    // cout << st << endl << endl;
}


int main() {

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> st;

        int ans = 0;
        cout << st << endl;
        while(!happy()) {
            // cout << best_move() << endl;
            move(best_move());
            cout << st << endl;
            ans++;
        }

        cout << "Case #" << i << ": " << ans << endl;
    }

    return 0;
}
