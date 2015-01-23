#include <iostream>

#include <bits/stdc++.h>

using namespace std;

// Input macros
// Useful hardware instructions
// Useful comparation
// Useful container manipulation / traversal macros
// Bit ops


class TaskC_479{
public:
    // Problem heap variables

    //
    void solve(std::istream & in, std::ostream & out) {
        int n, f, s, i;
        in >> n;
        vector<pair<int, int> > exams;

        for (i = 0; i < n; i++) {
            in >> f;
            in >> s;
            exams.push_back(make_pair(f, s));
        }

        sort(exams.begin(), exams.end());
        for (i = 1; i < n; i++) {
//            out << exams[i].first << endl;
            if (exams[i].second < exams[i - 1].second && exams[i].first > exams[n-1].second) {
                break;
            }
        }
        if (i < n)
            out << exams[n - 1].first;
        else
            out << exams[n - 1].second;
    }
};

namespace SHelper{
    TaskC_479 solver; // make sure it's initialized on heap
}

int main(){
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::istream & in(std::cin);
    std::ostream & out(std::cout);
    SHelper::solver.solve(in,out);
    return 0;
}