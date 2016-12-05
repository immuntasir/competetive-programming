#include <bits/stdc++.h>
using namespace std;
vector <int> ara;
char str[4];
int tree[700000];
int build (int idx, int left, int right) {
    if (left == right) {
        tree[idx] = 1;
        return 1;
    }
    int mid = (left+right)/2;
    return tree[idx] = build(idx*2, left, mid) + build(idx*2+1, mid+1, right);
}
int query(int idx, int left, int right, int x) {
    if (left == right) return left;
    int l, r, mid;
    mid = (left+right)/2;
    l = 2*idx;
    r = 2*idx+1;
    if (x <= tree[l]) return query(l, left, mid, x);
    else return query(r, mid+1, right, x - tree[l]);
}
int update (int idx, int left, int right, int x) {
    if (left == right) {
        if (left == x) tree[idx] = 0;
        return tree[idx];
    }
    if (x > right || x < left) return tree[idx];
    int mid = (left+right)/2;
    return tree[idx] = update(2*idx, left, mid, x) + update(2*idx + 1, mid+1, right, x);
}
int main () {
    //freopen("in.txt", "r", stdin);
    int T, n, a, q, tmp;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        ara.clear();
        printf("Case %d:\n", cs);
        scanf("%d %d", &n, &q);
        for (int i=0; i<n; i++) {
            scanf("%d", &a);
            ara.push_back(a);
        }
        build(1, 0, 160000);
        for (int i=0; i<q; i++) {
            scanf("%s %d", str, &a);
            if (str[0] == 'c') {
                if (a < ara.size()) tmp = query(1, 0, 160000, a);
                else tmp = a;
                if (tmp >= ara.size()) printf("none\n");
                else {
                    printf("%d\n", ara[tmp]);
                    update(1, 0, 160000, tmp);
                }
            }
            else {
                ara.push_back(a);
            }
        }
    }
    return 0;
}
