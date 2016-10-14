#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
vector <int> edge[MAX];
vector <int> cost[MAX];
int visited[MAX];
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
int main () {
    int n, m, a, b, c;
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(b);
        edge[b].push_back(a);
        cost[a].push_back(c);
        cost[b].push_back(c);
    }
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            costi(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
