#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
map <int, int> M;
int ara[100010];
long long int tree[300010];
long long query (int idx, int left, int right, int x) {
    if (x > right) {
        return tree[idx];
    }
    if (x <= left) return 0;
    if (left == right) return 0;
    int mid = (left+right)/2;
    long long v1, v2;
    v1 = query(idx*2, left, mid, x);
    v2 = query(idx*2 + 1, mid + 1, right, x);
    v1 %= MOD;
    v2 %= MOD;
    return (v1+v2)%MOD;
}
long long update (int idx, int left, int right, int x, long long tmp) {
    if (left <= x && right >= x) {
        if (left == right) {
            tree[idx] += tmp;
            tree[idx] %= MOD;
            return tree[idx];
        }
        int mid = (left+right)/2;
        long long v1, v2;
        v1 = update(idx*2, left, mid, x, tmp);
        v2 = update(idx*2 + 1, mid + 1, right, x, tmp);
        v1 %= MOD;
        v2 %= MOD;
        return tree[idx] = (v1+v2)%MOD;
    }
    return tree[idx];
}
int a[100010];
int ar[100010];
int main () {
    int T, n, cnt = 0;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        scanf("%d", &n);
        cnt = 0;
        M.clear();
        memset(tree,0, sizeof tree);
        for (int i=0; i<n; i++) {
            scanf("%d", &ara[i]);
            ar[i] = ara[i];
        }
        sort(ar, ar+n);
        for (int i=0; i<n; i++) {
            if (M[ar[i]] == 0) {
                M[ar[i]] = ++cnt;
            }
        }
        long long ans = 0, tmp;
        for (int i=0; i<n; i++) {
            tmp = 1 + query (1, 1, cnt, M[ara[i]]);
            //printf("%d : %d %d\n", ara[i], M[ara[i]], tmp);
            update(1, 1, cnt, M[ara[i]], tmp);
            ans = ans + tmp;
            ans %= MOD;
        }
        printf("Case %d: %lld\n", cs, ans);
    }
    return 0;
}
