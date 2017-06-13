#include <bits/stdc++.h>
using namespace std;
#define MAX 10010
#define INF 1000000000
vector <int> edge[MAX];
int shomoy;
int ans;
int dt[MAX];
int visited[MAX];
int low[MAX];
int parent[MAX];
void clearShob (int n) {
    shomoy = ans = 0;
    for (int i=0; i<=n; i++) {
        edge[i].clear();
        dt[i] = INF;
        low[i] = INF;
    }
    memset(visited, 0, sizeof visited);
}
void arti (int root) {
    shomoy++;
    dt[root] = shomoy;
    visited[root] = 1;
    low[root] = dt[root];
    int children = 0;
    int flag = 0;
    for (int i=0; i<edge[root].size(); i++) {
        if (!visited[edge[root][i]]) {
            parent[edge[root][i]] = root;
            arti(edge[root][i]);
            children++;
            if (parent[root] != root && low[edge[root][i]] >= dt[root]) {
                flag = 1;
            }
            if (low[edge[root][i]] < low[root]) {
                low[root] = low[edge[root][i]];
            }
        }
        else if (visited[edge[root][i]] == 1 && edge[root][i] != parent[root]) {
            if (dt[edge[root][i]] < low[root]) low[root] = dt[edge[root][i]];
        }
        if (parent[root] == root && children > 1) flag = 1;
    }
    ans+=flag;
    shomoy++;
    visited[root] = 2;
}
int main () {
    int T;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        int n, m, a, b;
        scanf("%d %d", &n, &m);
        clearShob(n);
        parent[1] = 1;
        for (int i=0; i<m; i++) {
            scanf("%d %d", &a, &b);
            edge[a].push_back(b);
            edge[b].push_back(a);
        }
        arti(1);
        printf("Case %d: %d\n", cs, ans);
    }
    return 0;
}
