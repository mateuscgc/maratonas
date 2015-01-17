#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

char str[1001];

int main(int argc, char const *argv[])
{
    vector <int> digits;

    int numdigs, i, j;
    cin >> numdigs;
    scanf ("%s", str);

    for (i = 0; i < numdigs; i++) {
        digits.push_back((int) str[i] - '0');
    }

    int older = (10 - digits[0]) % 10;
    int menor = 0;
    for (i = 1; i < numdigs; i++) {

        int now = (10 - digits[i]) % 10;

        for (j = 1; j < numdigs && (digits[(menor + j) % numdigs] + older) % 10 == (digits[(i + j) % numdigs] + now) % 10; j++);

        if (j < numdigs && (digits[(menor + j) % numdigs] + older) % 10 > (digits[(i + j) % numdigs] + now) % 10) {
            menor = i;
            older = now;
        }
    }

    for (i = 0; i < numdigs; i++) {
        cout << (digits[(menor + i) % numdigs] + older) % 10;
    }

    return 0;
}
