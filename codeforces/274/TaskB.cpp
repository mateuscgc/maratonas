#include <iostream>

#include <bits/stdc++.h>

using namespace std;

// Input macros
// Useful hardware instructions
// Useful comparation
// Useful container manipulation / traversal macros
// Bit ops


class TaskB_479{
public:
    // Problem heap variables

    //
    void solve(std::istream & in, std::ostream & out){
        int n, k;
        vector <int> towers;
        int diff, minDiff;
        vector  < pair<int, int> >  ops;
        in >> n;
        in >> k;
        int i, b, j;
        for (i = 0; i < n; i++) {
            in >> b;
            towers.push_back(b);
        }
        int min = 0, max = 0;
        diff;
        minDiff = 10000;
        for (j = 0; j <= k; j++) {
            for (i = 0; i < n; i++) {
                if (towers[i] > towers[max])
                    max = i;
                if (towers[i] < towers[min])
                    min = i;
            }
            if (towers[max] - towers[min] < minDiff) {
                minDiff = towers[max] - towers[min];
                diff = j;
            }
            ops.push_back(make_pair(max, min));
            towers[max]--;
            towers[min]++;
        }

        out << minDiff << " " << diff << endl;

        for (i = 0; i < diff; i++ ) {
            out << ops[i].first + 1 << " " << ops[i].second + 1 << endl;
        }
    }
};

namespace SHelper{
    TaskB_479 solver; // make sure it's initialized on heap
}

int main(){
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::istream & in(std::cin);
    std::ostream & out(std::cout);
    SHelper::solver.solve(in,out);
    return 0;
}