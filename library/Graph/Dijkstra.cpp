// Dijkstra

#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
#define INF 1000000000
vector <int> edge[MAX];
vector <int> cost[MAX];
int parent[MAX];
int visited[MAX];
int dis[MAX];
struct element{
    int node, path_cost;
    //constructors
    element(){}
    element(int _node, int _path_cost){
        node = _node;
        path_cost = _path_cost;
    }


   // bool operator <(const element &a)const
    //{
      //  return path_cost < a.path_cost;
   // }



    bool operator >(const element &a)const
    {
        return path_cost > a.path_cost;
    }
} ele;
int ans;
priority_queue<element, vector<element>, greater<element> > q;
void costi (int root) {
    //printf("%d -> ", root);
    visited[root] = 1;
    for (int i=0; i<edge[root].size(); i++) {
        if (!visited[edge[root][i]]) q.push(element(edge[root][i], cost[root][i]));
    }
    while (!q.empty() && visited[q.top().node]) {
        q.pop();
    }
    //printf("%d\n", q.size());
    if (q.empty()) return;
    int roo = q.top().node;
    ans += q.top().path_cost;
   // printf(" %d %d\n", roo, ans);
    q.pop();
    costi(roo);
}
set <int> S;
void dijkstra (int root) {
    dis[root] = 0;
    parent[root] = root;
    q.push(element(root, 0));
    while (!q.empty()) {
        element nxt = q.top();
        q.pop();
        int nx = nxt.node;
       // printf("%d -> ", q.top().node);
        for (int i=0; i<edge[nx].size(); i++) {
            //q.push(element(edge[nx][i], cost[nx][i]));
            //printf("a");
            element tmp;
            tmp = element(edge[nx][i], cost[nx][i]);
            if (dis[tmp.node] > dis[nx] + cost[nx][i]) {
                dis[tmp.node] = dis[nx] + cost[nx][i];
                q.push(element(tmp.node, dis[tmp.node]));
            }
            //printf("a");
        }
    }

}
int main () {
    //freopen("in.txt", "r", stdin);
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(b);
        edge[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    for (int i=0; i<n; i++) dis[i] = INF;
    dijkstra(0);
    //printf("%d\n", ans);
    for (int i=0; i<n; i++) {
        if (dis[i] == INF) printf("%d: Infinity\n", i);
        else printf("%d: %d\n", i, dis[i]);
    }
    return 0;
}













