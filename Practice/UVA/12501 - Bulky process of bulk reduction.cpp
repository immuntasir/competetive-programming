#include <bits/stdc++.h>
using namespace std;
#define mid (left+right)/2
#define L 2*idx
#define R 2*idx+1
#define goL L, left, mid
#define goR R, mid+1, right
#define int long long
typedef struct no {
    int sum, psum, n, lazy;
} node;
int ara[100010];
node tree[100010*4];
node makeNode(int val, int n) {
    node tmp;
    tmp.sum = tmp.psum = val;
    tmp.n = n;
    tmp.lazy = 0;
    return tmp;
}
node mergeIt(node a, node b) {
    node tmp;
    tmp.n = a.n+b.n;
    tmp.psum = a.psum+b.psum;
    tmp.sum = a.sum + b.sum + a.n * b.psum;
    tmp.lazy = 0;
    return tmp;
}
node build (int idx, int left, int right) {
    if (left==right) return tree[idx] = makeNode(ara[left], 1);
    return tree[idx] = mergeIt(build(goL), build(goR));
}
node query (int idx, int left, int right, int l, int r) {
    if (tree[idx].lazy) {
        tree[idx].psum = tree[idx].psum + tree[idx].lazy * tree[idx].n;
        tree[idx].sum = tree[idx].sum + ((tree[idx].n * (tree[idx].n + 1))/2) * tree[idx].lazy;
        if (left < right) {
            tree[L].lazy += tree[idx].lazy;
            tree[R].lazy += tree[idx].lazy;
        }
        tree[idx].lazy = 0;
    }
    if (l<=left && right<=r) return tree[idx];
    if (l>right || r<left) return makeNode(0, 0);
    return mergeIt(query(goL, l, r), query(goR, l, r));
}
node update (int idx, int left, int right, int l, int r, int val) {
    if (l<=left && right<=r) tree[idx].lazy += val;
    if (tree[idx].lazy) {
        tree[idx].psum = tree[idx].psum + tree[idx].lazy * tree[idx].n;
        tree[idx].sum = tree[idx].sum + ((tree[idx].n * (tree[idx].n + 1))/2) * tree[idx].lazy;
        if (left < right) {
            tree[L].lazy += tree[idx].lazy;
            tree[R].lazy += tree[idx].lazy;
        }
        tree[idx].lazy = 0;
    }
    if (l<=left && right<=r) return tree[idx];
    if (l>right || r<left) return tree[idx];
    return tree[idx] = mergeIt(update(goL, l, r, val), update(goR, l, r, val));
}
main () {
    //freopen("in.txt", "r", stdin);
    int T, n, q, a, b, c;
    char str[10];
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        scanf("%lld %lld", &n, &q);
        for (int i=0; i<n; i++) ara[i] = 100;
        build(1, 0, n-1);
        printf("Case %d:\n", cs);
        for (int i=0; i<q; i++) {
            scanf("%s", str);
            if (str[0] == 'q') {
                scanf("%lld %lld", &a, &b);
                node tmp = query(1, 0, n-1, a-1, b-1);
                printf("%lld\n", tmp.sum);
            }
            else {
                scanf("%lld %lld %lld", &a, &b, &c);
                update(1, 0, n-1, a-1, b-1, c);
            }
        }
    }
    return 0;
}
