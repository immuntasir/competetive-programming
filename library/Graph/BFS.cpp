#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
vector <int> edge[MAX];
int visited[MAX];
int level[MAX];
int parent[MAX];
void Input (int n, int m) {
    int a, b;
    for (int i=0; i<n; i++) {
        edge[i].clear();
        visited[i] = 0;   
    }
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
}
void bfs (int root) {
    queue <int> Q;
    Q.push(root);
    parent[root] = root;
    level[root] = 0;
    while (!Q.empty()) {
        int x = Q.front();
        visited[x] = 1;
        for (int i=0; i<edge[x].size(); i++) {
            if (!visited[edge[x][i]]) {
                Q.push(edge[x][i]);
                level[edge[x][i]] = level[x] + 1;
                parent[edge[x][i]] = x;
            }
        }
        Q.pop();
    }
}
int main () {
    //freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    Input(n, m);
    for (int i=0; i<n; i++) {
        if (!visited[i]) bfs(i);
    }
    for (int i=0; i<n; i++) {
        printf("%d: %d %d\n", i, level[i], parent[i]);
    }
    return 0;
}
