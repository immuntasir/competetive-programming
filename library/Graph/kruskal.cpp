#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
struct element {
	int a, b, c;
	bool operator < ( const element & x ) const {
		return c < x.c;
	}
};
int parent[MAX];
int ans;
vector <element> edges;
int findParent (int root) {
    if (parent[root] == root) return root;
    else return parent[root] = findParent(parent[root]);
}
int kruskal (int n) {
	int cnt = 0;
	for(int i = 0; i < edges.size(); i++) {
		int u = findParent(edges[i].a);
		int v = findParent(edges[i].b);
		if(u != v) {
			parent[u] = v;
			cnt++;
			//printf("%d %d\n", ans, edges[i].c);
			ans = max(ans, edges[i].c);
			if(cnt == n-1) break;
		}
	}
	return ans;
}

int main () {
    //freopen("in.txt", "r", stdin);
	int n, m;
	int a, b, c;
	element temp;
    scanf("%d %d", &n, &m);
	for (int i=0;i<=n;i++) parent[i] = i;
	for (int i=0;i<m;i++) {
		scanf("%d %d %d", &a, &b, &c);
		temp.a=a;
		temp.b=b;
		temp.c=c;
		edges.push_back(temp);
	}
	sort(edges.begin(), edges.end());
	ans = -1;
	kruskal(n);
	printf("%d\n", ans);
	return 0;

}
