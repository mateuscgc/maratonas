#include <stdio.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    int n, m, i, j;
    char palavra[11];
    scanf("%d %d", &n, &m);
    char ling1[m][11];
    char ling2[m][11];
    for (i = 0; i < m; i++){
        scanf("%s %s", ling1[i], ling2[i]);
    }
    for (i = 0; i < n; i++){
        scanf("%s", palavra);
        for (j = 0; j < m; j++){
            if (!strcmp(palavra, ling1[j])) {
                break;
            }
        }
        if (strlen(ling1[j]) <= strlen(ling2[j])){
            printf("%s\n", ling1[j]);
        } else {
            printf("%s\n", ling2[j]);
        }
    }

    return 0;
}
