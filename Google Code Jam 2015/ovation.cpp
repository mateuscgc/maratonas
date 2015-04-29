#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);

    char s[1001];
    int max;
    int result;
    int num;
    for (int i = 1; i <= t; i++) {
        scanf("%d", &max);
        scanf("%s", s);
        result = 0;
        num = 0;
        for (int j = 0; j <= max; j++) {
            if (s[j] > '0' && j > num + result) {
                result += j-num-result;
            }
            num += s[j]-'0';
        }
        printf("Case #%d: %d\n", i, result);
    }

    return 0;
}
