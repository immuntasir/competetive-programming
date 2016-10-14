#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
vector <int> edge[MAX];
int visited[MAX];
int level[MAX];
int parent[MAX];
int dt[MAX];
int ft[MAX];
int shomoy;
void Input (int n, int m) {
    int a, b;
    shomoy = 0;
    for (int i=0; i<n; i++) {
        edge[i].clear();
        visited[i] = 0;   
    }
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        //edge[b].push_back(a);
    }
}
void dfs (int root) {
    //printf("%d -> ", root);
    visited[root] = 1;
    shomoy++;
    dt[root] = shomoy;
    for (int i=0; i<edge[root].size(); i++) {
        if (!visited[edge[root][i]]) {
            // tree edge
            printf("%d %d: tree\n", root, edge[root][i]);
            dfs(edge[root][i]);
        }
        else if (visited[edge[root][i]] == 1) {
            // backedge
            // cycle
            printf("%d %d: back\n", root, edge[root][i]);
        }
        else {
            if (dt[root] < dt[edge[root][i]]) {
                // forward edge
                printf("%d %d: forward\n", root, edge[root][i]);
            }
            else {
                // cross edge
                printf("%d %d: cross\n", root, edge[root][i]);
            }
        }
    }
    shomoy++;
    ft[root] = shomoy;
    visited[root] = 2;
}
int main () {
    freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    Input(n, m);
    for (int i=0; i<n; i++) {
        if (!visited[i]) dfs(i);
    }

    return 0;
}
