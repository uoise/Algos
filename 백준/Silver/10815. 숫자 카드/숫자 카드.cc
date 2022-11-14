#include <iostream>
bool arr[20000001];

int main() {
    int N, i, t;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &t);
        arr[t + 10000000] = true;
    }

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &t);
        if (arr[t + 10000000])
            printf("%d ", 1);
        else
            printf("%d ", 0);
    }
    printf("\n");
}