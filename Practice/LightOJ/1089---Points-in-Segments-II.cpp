#include <bits/stdc++.h>
using namespace std;
int tree[2000000];
int x[100000];
vector <int> ara;
int y[100000];
int q[100000];
map <int, int> M;
void update (int idx, int left, int right, int l, int r) {
    if (l > right || r < left) return;
    if (l <= left && r >= right) {
        tree[idx]++;
        return;
    }
    if (left == right) return;
    if (tree[idx]) {
        tree[2*idx] += tree[idx];
        tree[2*idx+1] += tree[idx];
        tree[idx] = 0;
    }
    int mid = (left+right)/2;
    update(idx*2, left, mid, l, r);
    update(idx*2+1, mid+1, right, l, r);
}
int query (int idx, int left, int right, int x) {
    if (left == right) {
        if (left == x) return tree[idx];
        return 0;
    }
    if (tree[idx]) {
        tree[2*idx] += tree[idx];
        tree[2*idx+1] += tree[idx];
        tree[idx] = 0;
    }
    if (left <= x && x <= right) {
        int mid = (left+right)/2;
        return query(idx*2, left, mid, x) | query(idx*2 + 1, mid+1, right, x);
    }
    return 0;
}
int main () {
    //freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        int n, Q;
        ara.clear();
        M.clear();
        memset(tree, 0, sizeof tree);
        scanf("%d %d", &n, &Q);
        for (int i=0; i<n; i++) {
            scanf("%d %d", &x[i], &y[i]);
            ara.push_back(x[i]);
            ara.push_back(y[i]);
        }
        for (int i=0; i<Q; i++) {
            scanf("%d", &q[i]);
            ara.push_back(q[i]);
        }
        sort(ara.begin(), ara.end());
        int sz = ara.size();
        int cnt = 0;
        for (int i=0; i<sz; i++) {
            if (M[ara[i]] == 0) M[ara[i]] = ++cnt;
        }
        for (int i=0; i<n; i++) {
            update(1, 0, cnt, M[x[i]], M[y[i]]);
            //printf("%d %d\n", M[x[i]], M[y[i]]);
        }
        printf("Case %d:\n", cs);
        for (int i=0; i<Q; i++) printf("%d\n", query(1, 0, cnt, M[q[i]]));
    }
    return 0;
}
