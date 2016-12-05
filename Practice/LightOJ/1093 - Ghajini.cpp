#include <bits/stdc++.h>
using namespace std;
int ara[100010];
int minTree[3000000];
int maxTree[3000000];
int buildMin (int idx, int left, int right) {
    if (left == right) {
        return minTree[idx] = ara[left];
    }
    int mid = (left+right)/2;
    return minTree[idx] = min(buildMin(idx*2, left, mid), buildMin(idx*2+1, mid+1, right));
}
int buildMax (int idx, int left, int right) {
    if (left == right) {
        return maxTree[idx] = ara[left];
    }
    int mid = (left+right)/2;
    return maxTree[idx] = max(buildMax(idx*2, left, mid), buildMax(idx*2+1, mid+1, right));
}
int queryMin(int idx, int left, int right, int l, int r) {
    if (r < left || l > right) return 1000000000;
    if (l <= left && right <= r) return minTree[idx];
    if (left == right) return 1000000000;
    int mid = (left+right)/2;
    return min(queryMin(idx*2, left, mid, l, r), queryMin(idx*2+1, mid+1, right, l, r));
}
int queryMax(int idx, int left, int right, int l, int r) {
    if (r < left || l > right) return 000000000;
    if (l <= left && right <= r) return maxTree[idx];
    if (left == right) return 000000000;
    int mid = (left+right)/2;
    return max(queryMax(idx*2, left, mid, l, r), queryMax(idx*2+1, mid+1, right, l, r));
}
int main () {
    int T;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        int n, q;
        scanf("%d %d", &n, &q);
        for (int i=0; i<n; i++) {
            scanf("%d", &ara[i]);
        }
        buildMin(1, 0, n-1);
        buildMax(1, 0, n-1);
        int mx, mn, ans=0;
        for (int i=0; i+q<n; i++) {
            mn = queryMin(1, 0, n-1, i, i+q-1);
            mx = queryMax(1, 0, n-1, i, i+q-1);
            ans = max(ans, mx-mn);
        }
        printf("Case %d: %d\n", cs, ans);
    }
    return 0;
}
