#include <bits/stdc++.h>
using namespace std;

int ara[100010];
int ans[100010];
bool flag[100010];
int aa[100010];
vector <int> X[100010];
int ptr[100010];
int tree[500010];
typedef struct no {
    int i, j;
    int idx;
} node;
node qs[100010];
void clearAll() {
    for (int i=0; i<100010; i++) X[i].clear();
    memset(flag, false, sizeof flag);
    memset(tree, 0, sizeof tree);
    memset(ptr, 0, sizeof ptr);
    memset(aa, 0, sizeof aa);
    memset(ara, 0, sizeof ara);
    memset(ans, 0, sizeof ans);
    memset(qs, 0, sizeof qs);
}
bool cmp (node a, node b) {
    return a.i < b.i;
}
int build (int idx, int i, int j) {
    if (i == j) return tree[idx] = aa[i];
    int mid = (i+j)/2;
    return tree[idx] = build (idx*2, i, mid) + build(idx*2 + 1, mid+1, j);
}
int update (int idx, int i, int j, int x) {
    if (i==j && x == i) return tree[idx] ^= 1;
    if (x < i || x > j) return tree[idx];
    int mid = (i+j)/2;
    return tree[idx] = update(idx*2, i, mid, x) + update(idx*2 + 1, mid+1, j, x);
}
int query(int idx, int i, int j, int l, int r) {
    if ( l <= i && j <= r) return tree[idx];
    if (l > j || r < i) return 0;
    if (i==j) return 0;
    int mid = (i+j)/2;
    return query(idx*2, i, mid, l, r) + query(idx*2+1, mid+1, j, l, r);
}
int main () {
    //freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        int n, q;
        scanf("%d %d", &n, &q);
        clearAll();
        for(int i=0; i<n; i++) {
            scanf("%d", &ara[i]);
            if (flag[ara[i]] == false) {
                aa[i] = 1;
                flag[ara[i]] = true;
            }
            X[ara[i]].push_back(i);
        }
        for (int i=0; i<q; i++) {
            scanf("%d %d", &qs[i].i, &qs[i].j);
            qs[i].i--;
            qs[i].j--;
            qs[i].idx = i;
        }
        sort(qs, qs+q, cmp);
        build(1, 0, n-1);
        int cur = 0;
        int l, r;
        for (int i=0; i<q; i++) {
            l = qs[i].i;
            r = qs[i].j;
            while (l!=cur) {
                if (ptr[ara[cur]] + 1 < X[ara[cur]].size()) {
                    ptr[ara[cur]]++;
                    update(1, 0, n-1, X[ara[cur]][ptr[ara[cur]]]);
                }
                cur++;
            }
            ans[qs[i].idx] = query(1, 0, n-1, l, r);
        }
        printf("Case %d:\n", cs);
        for (int i=0; i<q; i++) printf("%d\n", ans[i]);
    }
    return 0;
}
