#include <bits/stdc++.h>
using namespace std;
#define MOD 10007
#define L 2*idx
#define R 2*idx + 1
#define mid (left+right)/2
#define goL L, left, mid
#define goR R, mid+1, right
#define int long long
/*
20 4
0 0 14  10005 9999 1464
1 3 13
*/
typedef struct no {
    int a, b, c, sum;
} node;
node tree[600010];
long long lin[200010];
long long quad[200010];
node makeNode (int a, int b, int c, int sum) {
    node tmp;
    tmp.a = a;
    tmp.b = b;
    tmp.c = c;
    tmp.sum = sum;
    return tmp;
}
void build (int idx, int left, int right) {
    memset(tree, 0, sizeof tree);
    int n = right+1;
    for (long long i=1; i<=n; i++) lin[i] = (lin[i-1]%MOD + i%MOD)%MOD;
    for (long long i=1; i<=n; i++) quad[i] = (quad[i-1]%MOD + (i*i)%MOD)%MOD;
}
int func (int l, int r, int mode) {
    if (mode == 0) {
        if (l==0) return quad[r];
        else return (quad[r] - quad[l-1] + MOD) %MOD;
    }
    else if (mode == 1) {
        if (l==0) return lin[r];
        else return (lin[r] - lin[l-1] + MOD) %MOD;
    }
    else {
        return (r-l+1);
    }
}
node mergeIt (node a, node b) {
    node tmp = a;
    tmp.sum += b.sum;
    tmp.sum %= MOD;
    return tmp;
}
node query(int idx, int left, int right, int l, int r) {
    if (tree[idx].a || tree[idx].b || tree[idx].c) {
        tree[idx].sum = tree[idx].sum + tree[idx].c * (right-left+1);
        tree[idx].sum %= MOD;
        tree[idx].sum = tree[idx].sum + tree[idx].b*func(left, right, 1);
        tree[idx].sum %= MOD;
        tree[idx].sum = tree[idx].sum + tree[idx].a*func(left, right, 0);
        tree[idx].sum %= MOD;
        if (left < right) {
            tree[L].a = tree[L].a + tree[idx].a;
            tree[L].a %= MOD;
            tree[L].b = tree[L].b + tree[idx].b;
            tree[L].b %= MOD;
            tree[L].c = tree[L].c + tree[idx].c;
            tree[L].c %= MOD;
            tree[R].a = tree[R].a + tree[idx].a;
            tree[R].a %= MOD;
            tree[R].b = tree[R].b + tree[idx].b;
            tree[R].b %= MOD;
            tree[R].c = tree[R].c + tree[idx].c;
            tree[R].c %= MOD;
        }
        tree[idx].a = tree[idx].b = tree[idx].c = 0;
    }
    //printf("qr: %d %d %d %d %d %d\n", idx, left, right, l, r, tree[idx].sum);
    if (l<=left && right<=r) return tree[idx];
    if (l>right || r<left) return makeNode(0, 0, 0, 0);
    return mergeIt(query(goL, l, r), query(goR, l, r));
}
node update (int idx, int left, int right, int l, int r, int a, int b, int c) {
    //printf("upd : %d %d %d %d %d %d %d\n", idx, left, right, tree[idx].sum, tree[idx].a, tree[idx].b, tree[idx].c);
    if (l<=left && right <= r) {
        tree[idx].a += a;
        tree[idx].a %= MOD;
        tree[idx].b += b;
        tree[idx].b %= MOD;
        tree[idx].c += c;
        tree[idx].c %= MOD;
    }
    if (tree[idx].a || tree[idx].b || tree[idx].c) {
        tree[idx].sum = tree[idx].sum + tree[idx].c * (right-left+1);
        tree[idx].sum %= MOD;
        tree[idx].sum = tree[idx].sum + tree[idx].b*func(left, right, 1);
        tree[idx].sum %= MOD;
        tree[idx].sum = tree[idx].sum + tree[idx].a*func(left, right, 0);
        tree[idx].sum %= MOD;
        if (left < right) {
            tree[L].a = tree[L].a + tree[idx].a;
            tree[L].a %= MOD;
            tree[L].b = tree[L].b + tree[idx].b;
            tree[L].b %= MOD;
            tree[L].c = tree[L].c + tree[idx].c;
            tree[L].c %= MOD;
            tree[R].a = tree[R].a + tree[idx].a;
            tree[R].a %= MOD;
            tree[R].b = tree[R].b + tree[idx].b;
            tree[R].b %= MOD;
            tree[R].c = tree[R].c + tree[idx].c;
            tree[R].c %= MOD;
        }
        tree[idx].a = tree[idx].b = tree[idx].c = 0;
    }
    if (l<=left && right<=r) return tree[idx];
    if (l > right || r < left) return tree[idx];
    return tree[idx] = mergeIt(update(goL, l, r, a, b, c), update(goR, l, r, a, b, c));
}
main () {
    int n, q, z, x, y, a, b, c;
    scanf("%lld %lld", &n, &q);
    build(1, 0, n-1);
    //printf("%d %d %d %d\n", func(0, n-1, 1), func(0, n-1 ,0), lin[3], quad[3]);
    for (int i=0; i<q; i++) {
        scanf("%lld %lld %lld", &z, &x, &y);
        if (z == 1) printf("%lld\n", query(1, 0, n-1, x, y).sum);
        else {
            scanf("%lld %lld %lld", &a, &b, &c);
            update(1, 0, n-1, x, y, a, b, c);
        }
        //printf("done\n");
    }
    return 0;
}
