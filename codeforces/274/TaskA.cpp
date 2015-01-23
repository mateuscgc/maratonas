#include <iostream>

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

// Input macros
// Useful hardware instructions
// Useful comparation
// Useful container manipulation / traversal macros
// Bit ops


class TaskA_479{
public:
    // Problem heap variables
    //
    void solve(std::istream & in, std::ostream & out){

        int a, b, c, maxi;
        in >> a;
        in >> b;
        in >> c;

        maxi = max(a+b+c, a+b*c);
        maxi = max(maxi, (a+b)*c);
        maxi = max(maxi, a*b+c);
        maxi = max(maxi, a*(b+c));
        maxi = max(maxi, a*b*c);

        out << maxi;
    }
};

namespace SHelper{
    TaskA_479 solver; // make sure it's initialized on heap
}

int main(){
    std::cin.sync_with_stdio(false);
    std::cin.tie(0);
    std::istream & in(std::cin);
    std::ostream & out(std::cout);
    SHelper::solver.solve(in,out);
    return 0;
}