#include <stdio.h>

int main(int argc, char const *argv[])
{
    char str[11], letter;
    scanf("%s", str);
    int diff = 0, pos, len, i, j, k, z;
    for (len = 0; str[len] != 0 && len < 11; len++);
    for (j = 0, i = len - 1; j < i; j++, i--) {
        if (str[j] != str[i]) {
            diff++;
            if (diff == 2)
                break;
            for (k = j, z = i - 1; str[k] == str[z] && k < z; k++, z--);
            if (k >= z) {
                pos = j;
                letter = str[i];
                j--;
            } else {
                pos = i + 1;
                letter = str[j];
                i++;
            }
        }

    }
    if (diff == 0) {
        letter = str[len / 2];
        pos = len / 2;
    }

    if (diff == 2) {
        printf("NA\n");
    } else {
        for (i = 0, j = 0; i < len + 1; i++){
            if (i == pos) {
                printf("%c", letter);
            } else {
                printf("%c", str[j++]);
            }
        }
    }

    return 0;
}
