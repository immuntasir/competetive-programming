// warshall

#include <bits/stdc++.h>
using namespace std;
int edge[200][200];
#define INF 1000000000
int main () {
    int n, m;
    int a, b, c;
    //printf("%d\n", INF);
    scanf("%d %d", &n, &m);
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            edge[i][j] = INF;
        }
    }
    for (int i=1; i<=m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        if (edge[a][b] > c) edge[a][b] = c;
        if (edge[b][a] > c) edge[b][a] = c;
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            //printf("%d ", edge[i][j]);
            for (int j=0; j<n; j++) {
                //printf("%d -> %d -> %d %d %d\n", i, k, j, edge[i][j], edge[i][k] + edge[k][j]);
                if (edge[i][j] > edge[i][k] + edge[k][j]) {
                    edge[i][j] = edge[i][k] + edge[k][j];
                }
            }
        }
       // printf("\n");
    }
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (i==j) continue;
            printf("%d to %d: ", i, j);
            if (edge[i][j] == INF) printf("No Path\n");
            else printf("%d\n", edge[i][j]);
        }
    }
    return 0;
}
