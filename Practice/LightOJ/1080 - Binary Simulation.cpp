#include <bits/stdc++.h>
using namespace std;
#define MAX 100010
int tree[3*MAX];
char str[MAX];
char s[3];
void build (int idx, int left, int right) {
    if (left == right) {
        tree[idx] = str[left] - '0';
        return;
    }
    int mid = (left+right)/2;
    build(idx*2, left, mid);
    build(idx*2+1, mid+1, right);
    return;
}
void update (int idx, int left, int right, int l, int r) {
    //printf("index - %d %d %d %d %d\n", idx, left, right, l, r);
    if (l <= left && right <= r ) {
        tree[idx] ^= 1;
        return;
    }
    if (l > right || r < left) return;
    if (left == right) return;
    if (tree[idx]) {
        tree[idx*2] ^= 1;
        tree[idx*2+1] ^= 1;
        tree[idx] = 0;
    }
    int mid = (left+right)/2;
    update(idx*2, left, mid, l, r);
    update(idx*2+1, mid+1, right, l, r);
}
int query (int idx, int left, int right, int x) {
    if (left == right) {
        if (x == left) return tree[idx];
        return 0;
    }
    if (x > right || x < left) return 0;
    if (tree[idx]) {
        tree[idx*2] ^= 1;
        tree[idx*2+1] ^= 1;
        tree[idx] = 0;
    }
    int mid = (left+right)/2;
    return query(idx*2, left, mid, x) | query(idx*2+1, mid+1, right, x);
}

int main () {
    //freopen("in.txt", "r", stdin);
    int T;
    int q, a, b;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        memset(tree, 0, sizeof tree);
        scanf("%s", str);
        int len = strlen(str);
        build(1, 0, len-1);
        printf("Case %d:\n", cs);
        scanf("%d", &q);
        for (int i=0; i<q; i++) {
            scanf("%s", s);
            if (strcmp("I", s) == 0) {
                scanf("%d %d", &a, &b);
                update(1, 0, len-1, --a, --b);
            }
            else {
                scanf("%d", &a);
                printf("%d\n", query(1, 0, len-1, --a));
            }
        }
    }
    return 0;
}
