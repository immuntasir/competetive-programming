#include <bits/stdc++.h>
using namespace std;
vector <int> edge[100010];
int visited[100010];
int dt[100010];
int parent[100010];
int low[100010];
int indeg[100010];
int shomoy;
set <int> ans;
void clearShob () {
    for (int i=0; i<100010; i++) {
        low[i] = 1000000000;
        dt[i] = 1000000000;
    }
}
void dfs (int root) {
    shomoy++;
    //printf("%d -> ", root);
    dt[root] = shomoy;
    visited[root] = 1;
    //printf("a");
    low[root] = dt[root];
    int children = 0;
    for (int i=0; i<edge[root].size(); i++) {
        if (!visited[edge[root][i]]) {
            parent[edge[root][i]] = root;
            dfs(edge[root][i]);
            //printf("%d %d %d %d\n", root, edge[root][i], low[edge[root][i]], dt[root]);
            if (parent[root] == root && children > 1) ans.insert(root);
            if (parent[root] != root && low[edge[root][i]] >= dt[root]) ans.insert(root);
            if (low[edge[root][i]] < low[root]) {
                low[root] = low[edge[root][i]];
                //printf("omg\n");
            }
        }
        else if (visited[edge[root][i]] == 1 && edge[root][i] != parent[root]) {
            //printf("omg: %d %d\n", root, edge[root][i]);
            if (dt[edge[root][i]] < low[root]) low[root] = dt[edge[root][i]];
        }
    }
    shomoy++;
    visited[root] = 2;
}
int main () {
    //freopen("in.txt", "r", stdin);
    int n, m, a, b;
    clearShob();
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
        indeg[b]++;
    }
    //for (int i=0; i<n; i++) {
        //printf("%d\n", indeg[i]);
        //if (indeg[i] == 0)
      //  edge[100009].push_back(i);
        //edge[i].push_back(100009);
    //}
    int rooot = 5;
    parent[rooot] = rooot;
    dfs(rooot);
    //for (int i=0; i<n; i++) printf("%d ", dt[i]);
    set <int> :: iterator it;
    for (it=ans.begin(); it!=ans.end(); it++) {
        printf("%d\n", *it);
    }
    return 0;
}
