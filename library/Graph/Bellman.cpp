// bellman
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
#define INF 1000000000
vector <int> edge[MAX];
vector <int> cost[MAX];
int dist[MAX];
int n, m;
bool bellman () {
    for (int i=0; i<200; i++) dist[i] = INF;
    dist[0] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<edge[j].size(); k++) {
                if (dist[edge[j][k]] > dist[j] + cost[j][k]) {
                    dist[edge[j][k]] = dist[j] + cost[j][k];
                }
            }
        }
    }
    bool flag = false;
    for (int j=0; j<n && !flag; j++) {
        for (int k=0; k<edge[j].size() && !flag; k++) {
            //printf("%d -> %d -> %d - %d %d\n", edge[j][k], j, k, dist[edge[j][k]], dist[j] + cost[j][k]);
            if (dist[edge[j][k]] > dist[j] + cost[j][k]) {
                flag = true;
                dist[edge[j][k]] = dist[j] + cost[j][k];
            }
        }
    }
    return flag;
}
int main () {
    int a, b, c;
    scanf("%d %d", &n, &m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d", &a, &b, &c);
        edge[a].push_back(b);
        cost[a].push_back(c);
    }
    if (bellman()) printf("Yes\n");
    else printf("No\n");
    return 0;
}





