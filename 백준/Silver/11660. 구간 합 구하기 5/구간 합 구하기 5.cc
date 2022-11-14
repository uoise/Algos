#include <iostream>
int N, M, x1, x2, y1, y2;
long long V[1025][1025];

int main() {   
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++) {
            scanf("%lld", &V[i][j]);
            V[i][j] += V[i][j - 1] + V[i - 1][j] - V[i - 1][j - 1];
        }
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        printf("%lld\n", V[x2][y2] - V[x1-1][y2] - V[x2][y1-1] + V[x1-1][y1-1]);
    }
}