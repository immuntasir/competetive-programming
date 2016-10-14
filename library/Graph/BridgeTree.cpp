#include <bits/stdc++.h>
#define MAX 100010
using namespace std;
vector <int> edge[MAX];
map < pair <int, int> , bool > M;
pair < int, int > temp;
int visited[MAX];
typedef struct nodes {
    int a, b;
} node;
bool cmp (node x, node y) {
    if (x.a == y.a) return x.b < y.b;
    return x.a < y.a;
}
bool cmp2 (vector <node> x, vector <node> y) {
    if (x[0].a == y[0].a) return x[0].b < y[0].b;
    return x[0].a < y[0].a;
}
vector <node> oka;
vector < vector <node> > okay;
node tmp;
int shomoy;
int dt[MAX];
int low[MAX];
int parent[MAX];
void findTheGoddamnBridges (int root) {
    visited[root] = 1;
    shomoy++;
    dt[root] = low[root] = shomoy;
    for (int i=0; i<edge[root].size(); i++) {
        if (edge[root][i] == parent[root]) continue;
        if (!visited[edge[root][i]]) {
            parent[edge[root][i]] = root;
            findTheGoddamnBridges(edge[root][i]);
            if (low[edge[root][i]] > dt[root]) {
                temp.first = min(root, edge[root][i]);
                temp.second = max(root, edge[root][i]);
                M[temp] = true;
                tmp.a = temp.first;
                tmp.b = temp.second;
                oka.clear();
                oka.push_back(tmp);
                okay.push_back(oka);
                //printf("%d %d\n", temp.first, temp.second);
            }
            low[root] = min(low[root], low[edge[root][i]]);
        }
        else low[root] = min(low[root], low[edge[root][i]]);
    }
    shomoy++;
}
void findTheBiconnectedComponents (int root) {
    visited[root] = 1;
    for (int i=0; i<edge[root].size(); i++) {
        temp.first = min(root, edge[root][i]);
        temp.second = max(root, edge[root][i]);
        if (!visited[edge[root][i]] && parent[root] != edge[root][i] && !M[temp]) {
            tmp.a = temp.first;
            tmp.b = temp.second;
            oka.push_back(tmp);
            M[temp] = true;
            findTheBiconnectedComponents(edge[root][i]);
        }
        else if (!M[temp]  && parent[root] != edge[root][i]) {
            tmp.a = temp.first;
            tmp.b = temp.second;
            M[temp] = true;
            oka.push_back(tmp);
        }
    }
}
int main () {
    //freopen("5.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            parent[i] = i;
            findTheGoddamnBridges(i);
        }
    }
    memset(visited, 0, sizeof visited);
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            //printf("%d\n", i);
            oka.clear();
            findTheBiconnectedComponents(i);
            sort(oka.begin(), oka.end(), cmp);
            if (oka.size()) okay.push_back(oka);
        }
    }
    sort(okay.begin(), okay.end(), cmp2);
    int sz = okay.size();
    for (int i=0; i<sz; i++) {
        if (i!=0) printf("---\n");
        int sze = okay[i].size();
        for (int j=0; j<sze; j++) {
            printf("%d %d\n", okay[i][j].a, okay[i][j].b);
        }
    }
    return 0;
}
