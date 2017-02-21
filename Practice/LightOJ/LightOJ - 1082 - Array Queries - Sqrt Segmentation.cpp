#include <bits/stdc++.h>
#define INF 1000000010
using namespace std;
int ara[100010];
int prep[1000];
void prepo (int n) {
    int sqr = (int) ceil(sqrt(n));
    int curp = 0, mn;
    for (int i=0; i<sqr; i++) {
        mn = INF;
        for (int j=0; j<sqr && curp < n; j++) {
            mn  = min(ara[curp], mn);
            curp++;
        }
        prep[i] = mn;
    }
    while (curp < n) {
        prep[sqr-1] = min(prep[sqr-1], ara[curp]);
        curp++;
    }
}
int query (int n, int x, int y) {
    int sqr = (int) ceil(sqrt(n));
    int s = x/sqr;
    int e = y/sqr;
    int ret = INF;
    if (s==e) {
        for (int i=x; i<=y; i++) ret = min(ret, ara[i]);
    }
    else {
        for (int i=x; i<sqr  * (s+1); i++) ret = min(ret, ara[i]);
        for (int i=sqr*(e); i<=y; i++) ret = min(ret, ara[i]);
        for (int i= s+1; i<e; i++) ret = min(ret, prep[i]);
    }
    return ret;
}
int main () {
    //freopen("in.txt", "r", stdin);
    int  T, n, m, x, y;
    scanf("%d", &T);
    for (int cs=1; cs<=T; cs++) {
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; i++) scanf("%d", &ara[i]);
        prepo(n);
        printf("Case %d:\n", cs);
        for (int i=0; i<m; i++) {
            scanf("%d %d", &x, &y);
            x--;
            y--;
            printf("%d\n", query(n, x, y));
        }
    }

    return 0;
}
