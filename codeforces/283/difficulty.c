#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int holds[n], max, i;
    scanf("%d", &holds[0]);
    max = -1;
    for (i = 1; i < n; i++){
        scanf("%d", &holds[i]);
        if (holds[i] - holds[i-1] > max){
            max = holds[i] - holds[i-1];
        }
    }
    int max2 = 1001;
    for (i = 1; i < n-1; i++){
        if (holds[i+1] - holds[i-1] > max) {
            if (holds[i+1] - holds[i-1] < max2){
                max2 = holds[i+1] - holds[i-1];
            }
        } else {
            max2 = max;
        }
    }
    printf("%d\n", max2);


    return 0;
}
